# Self Blancing Bot
This is a robot that aims to balance itself on two wheels. It can move as commanded by the user. Later we aim to make it autonomous. It utilized an IMU sensor to take inputs and balances itself using actuators(motors).

## Problem statement
“self-balancing bot is a two-wheeled robot that stays upright using sensor feedback (gyro & accelerometer) and a control algorithm like PID. It adjusts motor speed in real time to maintain balance and handle movement or disturbance”.

## Compenents required
| No. | Name                 | Quantity |
|-----|----------------------|----------|
| 1   | ESP 32               | 1        |
| 2   | MPU 6050             | 1        |
| 3   | L298                 | 1        |
| 4   | BO Motor             | 2        |
| 5   | Battery              | 2        |
| 6   | Wheels               | 2        |
| 7   | Buck Converter       | 1        |
| 8   | Battery Holder       | 2        |
| 9   | Switch               | 1        |
| 10  | F2F Jumper Wire      | 1 Set    |
| 11  | BO Motor Encoder     | 1        |
| 12  | Charging Module      | 2        |

## Concepts used
### PID tuning 
PID is a control system mechanism that is used to control a system parameter to obtain a desired result. It does so by constantly evaluating the difference between the process variable(current value) and the set point(desired value). PID stands for proportional, integral, derivative. The error goes through three types of control, as the name suggests.

## Future Scope
### Obstacle avoidance 
We can make the bot autonomous in future such that it can avoid the obstacles on its own and steer smoothly.
### Pick and drop  
This project can be a great help in picking and dropping objects when implemented on a larger scale. Such applications can be implemented on future versions.
###Remote control  
In the nearest future remote control via Bluetooth/WiFi is our first goal. Our goal is to implement this functionality first and then move to an autonomous bot.
