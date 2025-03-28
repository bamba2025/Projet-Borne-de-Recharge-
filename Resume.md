Electric Vehicle Charging Station Management (C++)
This project implements a simplified electric vehicle charging station management system in C++. It is designed according to a provided specification to simulate the operation of a charging station. The system enables safe and efficient charging of electric vehicles and includes functionalities such as user authentication via badge reading, real-time status indication, and communication with a simulation environment.

Overview
The charging station system allows an electric vehicle to connect for charging in a controlled manner. The station is equipped with one or two socket ports that are protected by a lockable flap, LED indicators for status (Available, Fault, Charge, Socket), push buttons (Charge and Stop), and a badge reader for client identification. The overall operation adheres to the Mode 3 charging process defined in IEC 61851-1, ensuring a safe and reliable charging experience.

Features
User Authentication:
The system reads a client’s badge via a card reader to authenticate the user before charging.

Real-Time Simulation:
A simulation environment (sim_borne) is used to emulate the charging station. The simulation displays:

A left panel showing the charging station (LEDs, buttons, actuators such as the AC contactor and flap lock).

A right panel showing the state of a connected electric vehicle.

State Management:
The system manages multiple charging states:

State A: Vehicle not connected (charging LED red with a +12V signal).

State B: Vehicle connected but power unavailable (voltage drops to +9V).

State C: Vehicle connected with power available (a square wave signal is sent to close the contactor).

State D: Signal modulation (PWM) indicates the maximum available charging current.

State E: Charging complete (voltage returns to +9V/-12V, charging LED turns green).

State F: Post-charge reset (return to +12V when the vehicle is disconnected).

Shared Memory Interface:
The project uses a shared memory segment (defined in donnees_borne.h) for communication between the charging station application and the simulation interface. This allows real-time updates of LED statuses, button states, and other parameters.

Card Reader Integration:
Functions provided in lcarte.h manage the card reader to:

Initialize ports.

Wait for badge insertion and removal.

Read the card’s identification number.

Hardware & Software Requirements : You need to be a student in Toulouse University :) .
