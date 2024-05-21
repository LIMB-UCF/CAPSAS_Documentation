import serial 
import time 

arduino = serial.Serial(port='COM3', baudrate=115200, timeout=None) #check serial port based on your OS
time.sleep(1)

x = b'\x00\x05'
#y = b'\xD3\x05' #object test
#y = b"\x00\x01" #regular test
y = b'\x8e\x02' #gesture move test

arduino.write(x)
time.sleep(0.1)
print(str(arduino.readline()) + str(time.time()))

def write_read(num): 
    # Send two bytes (e.g., 0x41 and 0x42)
    arduino.write(num)
    #arduino.close()
    print("Bytes sent successfully!")
    data1 = str(arduino.readline()) + str(time.time())
    data2 = str(arduino.readline()) + str(time.time())
    #data3 = str(arduino.readline()) + str(time.time())
    #data4 = str(arduino.readline()) + str(time.time())
    return data1 + "\n" + data2 #+ "\n" + data3 + "\n" + data4


try: 
    while True:
        value = write_read(y) #gets number of milliseconds passed in format "b'9999\r\n'" without the quotes "" (that example had 9999ms passed)
        print(value) # printing the value 
        time.sleep(3)
except KeyboardInterrupt:
    arduino.close() #make sure to close the port or you'll have to reconnect arduino 
    quit() 

