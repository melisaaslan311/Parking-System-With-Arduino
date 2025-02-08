# 🚗 Smart Parking System with Arduino Uno
📌 Project Overview
This project implements a Smart Parking System using Arduino Uno, designed to manage parking availability efficiently. The system uses an ultrasonic distance sensor to detect vehicle entry, a servo motor to control the parking barrier, and an RGB LED to visually indicate parking availability. An LCD screen displays the number of available spaces, and a buzzer provides an auditory alert.

🎯 Purpose
The Smart Parking System aims to improve parking management by:
Automatically detecting and tracking available parking spots.
Controlling vehicle access using a servo-operated barrier.
Displaying real-time parking status on an LCD screen.
Providing visual feedback through an RGB LED and buzzer.
Allowing manual system reset using a button.

🔧 Components Used
Component	Specification	Purpose
Microcontroller	Arduino Uno	Controls the entire system
Motor	Servo Motor	Opens and closes the parking barrier
Sensor	Ultrasonic Distance Sensor	Detects vehicle entry and presence
RGB LED	Common Cathode	Indicates parking availability
Buzzer	Passive Buzzer	Alerts when the barrier opens/closes
LCD Screen	16x2 LCD Display	Shows available parking spaces
Potentiometer	10kΩ	Adjusts LCD brightness and RGB LED colors
Push Button	Momentary Switch	Resets the parking system

📜 Working Principle
Initial State

The parking system has a maximum capacity of 6 cars.
The LCD screen displays the number of available spaces.
The RGB LED lights up green if there are no cars.
Car Entry Detection

The ultrasonic sensor detects a vehicle within 10 cm.
If spaces are available, the barrier opens with a beep.
The LCD updates the number of available spaces.
The barrier closes after a few seconds.
If the parking lot is full, the barrier remains closed, and the LCD displays "Parking Lot Full".
Visual Parking Indicators (RGB LED & Red LED)

0 cars → RGB LED Green
1-2 cars → RGB LED Blue
3-5 cars → RGB LED Blue
6 cars (Full) → RGB LED Red + Red LED ON
Manual Adjustments

A potentiometer allows manual RGB LED color adjustment.
Another potentiometer adjusts the LCD screen brightness.
The system resets when the reset button is pressed, restoring parking capacity to 6.

📄 Code Explanation
The Arduino sketch follows these steps:
Reads ultrasonic sensor data to detect vehicles.
Controls the servo motor to open/close the barrier.
Updates the LCD display with available parking spots.
Changes the RGB LED and buzzer based on parking availability.
Waits for a button press to reset the system.

⚡ Future Improvements
Implementing an IoT feature to monitor parking availability remotely.
Adding RFID authentication for authorized vehicle entry.
Integrating a mobile app to check parking status in real time.

📷 Images & Wiring Diagram
![final_arduino_bb](https://github.com/user-attachments/assets/d091fdba-55e7-42a4-a97e-56027500f6e1)
