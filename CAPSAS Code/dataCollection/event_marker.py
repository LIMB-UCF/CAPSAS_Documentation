import serial
import numpy as np
import time
import pylsl
from pylsl import StreamInfo, StreamOutlet, local_clock, resolve_streams, stream_inlet, LostError
import numpy as np
import random
import itertools
import sys
import pynput
import os
import pandas as pd
from colorama import Fore, init
import ast
init(autoreset=True)


subject_number = int(input("Enter the subject number: "))
session_number = int(input("Enter the session number: "))
case = 1
####
global value #verify later
sent_data_max_values = {'1': 240,'2': 180,'3': 216}
x = b'\x00\x05'
num_locations = 16
num_gestures = 5
rest_duration = 300 #5 min rest BACK TO 300
repeats = 3 #number of repeats for each number
sent_data_max = sent_data_max_values.get(case)
############
gesture_names = {0: 'open', 1: 'close', 2: 'flexion', 3: 'extension', 4: 'rest'}
gesture_numbers = {v: k for k, v in gesture_names.items()}
static_combination = np.random.permutation(np.repeat(np.arange(num_locations*num_gestures), repeats)) #generate a randomized vector of 240 numbers ranging 0:80

def map_sequence_to_locations(location_dict):
    # Randomly select a row from the DataFrame
    row = ob_df.sample(1).iloc[0]
    # Map the sequence to the locations and return it
    return [location_dict[item] for item in row]


############
arduino = serial.Serial(port='COM3', baudrate=115200, timeout=None) #check serial port based on your OS
time.sleep(1)
arduino.write(x)
print(str(arduino.readline()) + str(time.time()))

def write_read(num):
    # Send two bytes (e.g., 0x41 and 0x42)
    arduino.write(num)
    #arduino.close()
    print("Bytes sent successfully!")
    data1 = str(arduino.readline()) + str(time.time())
    timestamp1 = local_clock()
    data2 = str(arduino.readline()) + str(time.time())
    timestamp2 = local_clock()
    return [data1, data2, timestamp1, timestamp2]

def failed_trial(key):
    global repeat_trial
    if key == pynput.keyboard.Key.space:
        repeat_trial = 1
        print("Failed Trial!!!")
        return repeat_trial


def clear_inlet(inlet, timeout=0.0):
    while True:
        sample, timestamp = inlet.pull_sample(timeout=timeout)
        if sample is None:
            break

def write_to_file(subject_number, session_number, sample):
    # Create a directory for the subject if it doesn't exist
    directory = f"subject_{subject_number}"
    if not os.path.exists(directory):
        os.makedirs(directory)
    # Open the file for the session in append mode
    filename = f"subject_{subject_number}/session_{session_number}.csv"
    with open(filename, 'a') as outfile:
        outfile.write(f"{sample}\n")
try:
    buffer = [] #store the sent data
    flag_set = 1
    recovery_trial = [] #recover last trial
    obj_sequence = [] #store the sequence of object locations temporarily
    global failed_trial_trigger
    failed_trial_trigger = False
    repeat_trial = 0
    global sent_data
    sent_data = 0
    old_value = 0
    value = 0
    send_again = False
    listener = pynput.keyboard.Listener(on_press=failed_trial) #discuss this*
    streams = list(resolve_streams(0.5))
    #Define the name and type of the stream you want to connect to
    desired_name = 'Virtual Reality'
    desired_type = 'IMU'
    #Find the stream in the list of resolved streams
    for streamnum, stream in enumerate(streams):
        if stream.name() == desired_name and stream.type() == desired_type:
            inlet = stream_inlet(stream)
    print("Connected to stream.")
    listener.start()
    time.sleep(1)
    print('Starting the experiment..')
    print('Now sending data ...')
    if case == '1': 
        while sent_data < sent_data_max:
            if (sent_data == 80 or sent_data == 160)and send_again == False: 
                print(f'{Fore.BLUE} Rest of 5 minutes starts now...')
                time.sleep(rest_duration)  # having 5 min rest every 80 trails
                # verify that the data lost in the wait isn't counted avoid trigger fail trial
                clear_inlet(inlet)
                imu_sample, timestamps = inlet.pull_sample(timeout=0.1)
                old_value = imu_sample[-1]
            if send_again == True: #trigger for resending failed trial
                num = recovery_trial
                print(f"Resending failed trial #{num}")
                send_again = False
                repeat_trial = 0
            else: 
                filtered_nums = [p for p in static_combination if buffer.count(p) < 3] #do we want unique values during sess?
                #print(f'Filtered numbers are {filtered_nums}')
                num = random.choice(filtered_nums)
            gesture = gesture_names[num % 5]
            location = str(num // 5)
            print(f'sending number: {num}, location: {location} and gesture: {gesture}')
            data1, data2, timestamp1, timestamp2 = write_read(b'\x00' + bytes([num]))
            clear_inlet(inlet)
            imu_sample, timestamps = inlet.pull_sample(timeout=0.1)
            value = imu_sample[-1]
            if repeat_trial == 1 or value > old_value:
                failed_trial_trigger = True #trigger for saving!
                send_again = True
            recovery_trial = num
            if data1 is not None and data2 is not None: 
                if failed_trial_trigger == True:
                    print(f"{Fore.RED} Failed trial triggered")
                    data1 = 'failed_trial'
                    data2 = 'failed_trial'  #can change back to gesture and location! discuss*
                    failed_trial_trigger = False
                else:
                    sent_data += 1
                    buffer.append(num)
                old_value = value #store the last value of imu trigger
                sample = [data1, data2, gesture, location, timestamp1, timestamp2] 
                write_to_file(subject_number, session_number, sample)
                print(f" sample saved {sample}, data count : {sent_data}")
            else:
                print("Skipping invalid value")
            print(f"{Fore.GREEN} sent data count : {sent_data}")
            time.sleep(5)
            #making sure data lost in wait isnt counted
            clear_inlet(inlet)
            imu_sample, timestamps = inlet.pull_sample(timeout=0.1)
            old_value = imu_sample[-1]
        print(f"{Fore.MAGENTA} main data sent: ", sent_data)
        add_trials = input("Do you want to add more trials? (y/n): ").strip().lower()
        if add_trials == 'y':
            while add_trials == 'y':
                repeat_manual = 1
                gesture = int(input("Enter the gesture number ('open'= 0, 'close' = 1, 'flexion' = 2, 'extension' = 3, 'rest' = 4)): "))
                location = int(input("Enter the location number (0-15): "))
                num = 5 * location + gesture
                #clearing the inlet to not trigger repeat
                clear_inlet(inlet)
                imu_sample, timestamps = inlet.pull_sample(timeout=0.1)
                old_value = imu_sample[-1]
                while repeat_manual == 1:
                    data1, data2, timestamp1, timestamp2 = write_read(b'\x00' + bytes([num]))
                    time.sleep(5)
                    clear_inlet(inlet)
                    imu_sample, timestamps = inlet.pull_sample(timeout=0.1)
                    value = imu_sample[-1]
                    if value > old_value:
                        repeat_manual = 1
                    else:
                        repeat_manual = 0
                    old_value = value
                sample = [data1, data2, gesture, location, timestamp1, timestamp2]
                write_to_file(subject_number, session_number, sample)
                print(f"sample saved {sample}")
                add_trials = input("Do you want to add more trials? (y/n): ").strip().lower()
        else:
            print(f"{Fore.GREEN} All data sent")
            listener.stop()
        sys.exit()
    else:
        print('Invalid case')
except KeyboardInterrupt:
        arduino.close()  # make sure to close the port or you'll have to reconnect arduino
        quit()
        sys.exit()
