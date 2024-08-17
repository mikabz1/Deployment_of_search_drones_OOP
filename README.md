# project summary:

This project is a work for a bachelor's degree in computer science in the **object-oriented** CPP course.

**The project comes to test and create skills in the following subjects:**

*-Object-oriented design including multiple classes and multiple inheritance.*

*-data structure.*

*-Programming in CPP language.*

*-recursions.*

*-problem solving.*

*-Reading, writing and checking files.*

*-debugging.*

The project is an object-oriented simulation of a bunch of drones of different types, each of which has a slightly different behavior.
The aim of the drones is to reach a target point within a "forest" and thus end the program's run.

The drones are stored in a **binary tree data structure** which supports classic binary tree operations using *recursion*.
(*insert, *search, *min, *max, *remove, *clear, *size)

# types of drones and thair behavior:
![image](https://github.com/user-attachments/assets/09756c80-0d44-4b52-af76-ebdda611f662)



**new drone location:** 

![image](https://github.com/user-attachments/assets/e58bca51-057d-4f45-b4ef-8b8388186393)


**new drone speed:**
![image](https://github.com/user-attachments/assets/0ca2d086-edc7-4b0e-aec0-a6402e0f737b)
*Single Rotor* - 'S'.

*Multy Rotot* - 'M'.

*Fixed Wing* - 'F'.

*Hybrid* - 'H'  will move like *Single Rotor*.

![image](https://github.com/user-attachments/assets/947b69f4-12ec-4c68-9268-4800addc3b9b)

# input and output format:
*config file:* 
first line - 4 ints for forest size configuration.
second line - 2 real num for the target point cordinates.
third line - number of simulation iterations.

![image](https://github.com/user-attachments/assets/e0a4928e-77a2-43e2-a711-9d88aaf66c50)


*init file:*
first line - number of drones to be created.
other lines - 4 numbers for drone location and speed.

![image](https://github.com/user-attachments/assets/4be9c7bc-a7ed-42d1-ac9c-5f1cdceea5c9)


*output file:*
first line - number of iteration.
other lines - type of drone(char) and location.

![image](https://github.com/user-attachments/assets/74e9a131-5a2d-4467-86a6-480cae041f82)



***The names of the files passed as arguments to the program**
