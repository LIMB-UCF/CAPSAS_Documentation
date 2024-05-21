import time
import sys
import csv
import datetime
import pybullet as p
from pylsl import StreamInfo, StreamOutlet
import threading_module as tm
import triad_openvr


#### LSL initialization ######
num_devices = 4
srate = 500
name = 'Virtual Reality'
type = 'IMU'
n_channels = 10*num_devices + 1
info = StreamInfo(name, type, n_channels, srate, 'float32') 
outlet = StreamOutlet(info)
#### LSL Initialization is done #####

DESIRED_INTERVAL = 1/500 # 500 Hz

# Initialize OpenVR, etc.
v = triad_openvr.triad_openvr()
v.print_discovered_objects()

# Initialize PyBullet (need to check which configureDebugVisualizer args made it work)
physicsClient = p.connect(p.GUI)
p.setGravity(0,-9.8,0)
#p.VRCameraState()
p.configureDebugVisualizer(p.COV_ENABLE_Y_AXIS_UP,1)
#p.configureDebugVisualizer(p.COV_ENABLE_MOUSE_PICKING,0)
#p.configureDebugVisualizer(p.COV_ENABLE_GUI, 0)
p.configureDebugVisualizer(p.COV_ENABLE_KEYBOARD_SHORTCUTS, 1)
p.configureDebugVisualizer(p.COV_ENABLE_MOUSE_PICKING, 1)
p.configureDebugVisualizer(p.COV_ENABLE_SHADOWS, 1)
p.configureDebugVisualizer(p.COV_ENABLE_RENDERING, 1)
view_mtx = p.computeViewMatrix(cameraEyePosition=[-1, 1, -1], cameraTargetPosition=[0, 0, 0], cameraUpVector=[0, 0, 1])
p.getCameraImage(width=1000, height=1000, viewMatrix=view_mtx)

# Load your objects (replace with your own objects)
num_trackers = num_devices   # replace with your number of trackers
object_ids = [p.loadURDF("box2.urdf") for _ in range(num_trackers)]

# Set data collection interval based on command line arguments
if len(sys.argv) == 1: # Default interval
    interval = 1/950
elif len(sys.argv) == 2: # idk the purpose of this, was there before
    interval = 1/float(sys.argv[1])
else:
    print("Invalid number of arguments")
    interval = False
# queue = []
# queue.append(0)
queue = 0
# Loop for data collection
if interval:
    try:
        while(True):
            # Record start time of each loop iteration
            start = time.time()
            pause_time = time.time()
            # Wait for interval to pass (busy waiting), time.sleep is too slow
            while time.time() < (pause_time + interval):
                pass
            # Stores poses for console output
            lsl_imu = []
            imu_lsl_missing = [0]*10
            # Get poses for each tracker
            for device_name, device in v.devices.items():
                time_lost = []
                if 'tracker' in device_name:
                    # Get pose in Euler and Quaternion formats
                    pose = device.get_pose_euler()
                    q_pose = device.get_pose_quaternion()

                    # Pause if tracker disconnects, retry until it reconnects
                    timestamp = datetime.datetime.now().strftime("%H:%M:%S.%f")
                    if pose is None or q_pose is None:
                        lsl_imu += imu_lsl_missing
                        queue += 1
                    else:
                        # Extract individual components from the poses
                        x, y, z, yaw, pitch, roll = pose
                        _, _, _, qw, qx, qy, qz = q_pose
                        imu = [x, y, z, yaw, pitch, roll, qw, qx, qy, qz]
                        lsl_imu += imu #append the next tracker info
                    # Update PyBullet visualization
                    position = [x, y, z]
                    orientation = [qx, qy, qz, qw]
                    # Get the index from the device name
                    index = int(device_name[-1]) - 1    # Subtract 1 b/c indices start at 0
                    # Update the object's position and orientation in pybullet visualization
                    p.resetBasePositionAndOrientation(object_ids[index], position, 
                                                      orientation)
            #q = queue.pop(0)
            lsl_imu.append(queue) #so item 31 i 3 trackers is the trigger!! ftech always the last element in event marker!
            outlet.push_sample(lsl_imu)
            #print(lsl_imu)
            # Step the simulation
            p.stepSimulation()

    # Handle keyboard interrupt to ensure data is saved when the script is stopped
    except KeyboardInterrupt:
        sys.exit()

p.disconnect()






"""
conda activate vivepy6
cd "C:/VIVEPro2/Projects/body_tracking"
python lsl_bullet.py
"""