## Overview
First, the computer will send an integer to the Arduino that codes for a specific animation and location. Then, once the IR is triggered, the Arduino will send a message to the Serial port. The Python code then marks when the IR is triggered and saves the data to a CSV file.

Simultaneously, a program on the computer will be recording sEMG and kinematic data of the arm. The sEMG armband used is an OyMotion gForcePro+, which collects eight data channels at 500 Hz. The arm kinematics are tracked using four VIVE VR motion trackers at 500 Hz. All data streams are synchronized and recorded using the Lab Streaming Layer Python library. 

## General Installation
SteamVR must be installed and configured. 

Additionally, Python must be installed with the required libraries: 
- numpy
- pylsl 
- pynput
- colorama
- pybullet
- threading_module
- triad_openvr
- asyncio
- struct
- contextlib
- dataclasses 
- bleak 

## General Use

Three python files must be run in the following order:

`python oymotion_streamer.py`

This starts the EMG stream.

`python imu_stream.py`

This starts the IMU data stream. A live view of the trackers is also provided.

`python event_marker.py`

This starts to communicate with the Arduino. 

***Finally, you must start recording the data within the LSL GUI.***
