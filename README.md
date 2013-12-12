#Moving the robot through the maze
Library for reading from the sensors in the issued robot through the MSP430.
main.c included

## General Notes
There is no .c or .h file for this lab. It implements the motor driver and sensor libraries from the previous labs.

## Changes to Previous motor Library

- `Motor speed`
    - Motor speed changed for the right motor at 52% and the left motor at 35%
    - This lets the robot constantly turn left while going forward

- `Clear bits`
    - Cleared the bits  TA0CCTL0 and TA0CCTL1 before moving the robot because it would not switch directions once started


## Strategy

- `Left Wall Follower`
    - Follows the left wall
    -Because the right motor is faster, it will constantly turn into the left wall
    -Once the left sensor is close enough to the wall it will turn right
    -If about to hit a wall head on, it will reverse then turn right

- `Threshold values`
    - Left sensor > 0x2B5
    - Middle sensor > 0x2AF
    - Right sensor not implemented
   
## License
Anyone is free to use and modify this for any purpose, provided they pay three easy payments of $15,000

## Documentation

C2C Busho told me to clear the bits in my directions because it was not turning once going forward

