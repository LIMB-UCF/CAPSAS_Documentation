# Common Arm Position Signal Acquisition System (CAPSAS)
#### *Created by the Laboratory for Interaction of Machine and Brain (LIMB) at the University of Central Florida*

## Introduction
Surface electromyography (sEMG) is the leading method of non-invasive control of prosthetic hands. Using sEMG recorded over a short time window, machine-learning algorithms can be used to classify intended hand gestures with high accuracy if the training and testing data are collected when the arm’s location remains relatively the same. However, during activities of daily living (ADL), the arm position varies, deteriorating gesture recognition accuracy. Therefore, to systematically study how arm position influences hand gesture recognition, we have built a device to position subjects’ arms at different locations across two dimensions while recording sEMG and upper limb kinematics using motion trackers. Compared to existing methods, the innovative device improves the data collection process for upper limb prosthesis experiments. Since the system is automated, datasets can be collected with minimal experimenter interference. Additionally, since the system is open source, other laboratories worldwide can build similar systems to create standardized datasets. Such datasets, collected across participants and days, will provide invaluable insights for robust myoelectric control of prosthetic hands invariant to the limb position.

## Explanation of the Project (Video)
https://youtu.be/4Bmu42mNIyQ

## Using the CAPSAS

![image](https://github.com/LIMB-UCF/CAPSAS_Documentation/assets/69369213/e816d62a-b948-4343-bbef-259fd5ef5be6)


The CAPSAS is composed of sixteen hexagons, each with twelve LEDs and an IR distance sensor in the middle. An Arduino Mega receives information from the computer about what LED animation to display at which location. Once received, it will then return a message whenever the IR sensor for that hexagon is triggered. You can learn more about the physical construction of the CAPSAS at this [link](https://github.com/LIMB-UCF/CAPSAS_Documentation/tree/main/CAPSAS%20Physical%20Parts). 

The sEMG of the forearm is recorded to the [Lab Streaming Layer](https://github.com/sccn/labstreaminglayer) (LSL). Additionally, kinematics of the trunk, arm, forearm, and wrist are recorded by four VIVE trackers. The IR sensor timestamps are currently recorded in a separate CSV to be interpreted in post-processing. You can learn more about the software of the CAPSAS at this [link](https://github.com/LIMB-UCF/CAPSAS_Documentation/tree/main/CAPSAS%20Code). 

The [material cost](https://github.com/LIMB-UCF/CAPSAS_Documentation/blob/main/CAPSAS%20Physical%20Parts/CAPSAS%20BOM.csv) of the CAPSAS is around $1000 USD, assuming access to a 3D printer and laser cutter. The EMG and kinematics data tracking are also not included in that price, but the LSL can be configured for other devices too. 

Don't want to build the CAPSAS but still want to use our dimensions? We created a [PDF poster](https://github.com/LIMB-UCF/CAPSAS_Documentation/blob/main/CAPSAS_Poster.pdf) of the CAPSAS for easy use!
