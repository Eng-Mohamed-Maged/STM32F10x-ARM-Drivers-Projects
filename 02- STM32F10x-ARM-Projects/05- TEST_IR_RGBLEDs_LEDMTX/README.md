# STM32F10x Testing for LED Matrix, IR Remote, and RGB LED
**This code aims to perform a comprehensive test on an 8x8 LED Matrix with IR Remote using the STM32F10x microcontroller.**
This Code consists of :
**1- Hardware Abatraction Layer [HAL] :** LED MATRIX - IR REMOTE - RGB LED
**2- Microcontroller Abstraction Layer [MCAL] :** RCC - GPIO - NVIC - AFIO - EXTI - SysTick - TIMERS    
**3- Library Layer [LIB] :** STD TYPES - BIT MATH 
In this code i used [IR REMOTE] for controlling on :
# LED MATRIX : 
1) TO TURN ON AND DISPLAY "HELLO"
2) SPEED UP THE DISPLAYED TEXT 
3) SLOW DOWN THE DISPLAYED TEXT
4) DISPLAY A MAN BOUNCING A BALL

# RGB LED :
1) TURN ON/OFF GREEN LED
2) TURN ON/OFF BLUE LED
3) TURN ON/OFF RED LED

In this code i used [RCC] for:
1) Clock Initialization for used ports and peripherals


In this code i used [GPIO] for:
1) Setting the directions and the values for used ports and pins

In this code i used [NVIC] for:
1) To Enable EXTI8 for REMOTE DRIVER .

In this code i used [EXTI] for:
1) To Enable EXTI LINE 8
2) Setting Signal Latch to Falling Edge Mode


In this code i used [AFIO] for:
1) Mapping EXTI8 PIN TO A8 .


In this code i used [SysTick] for:
1) Handling the Delay which used in LED MATRIX 

In this code i used [TIMERS] => **TIMER 2** for:
1) Handling the Delay which used in [IR REMOTE] Recieving FRAME









# Table of Contents
- Introduction
- Testing Video
- Getting Started
- Connect with me

# Introduction
The STM32F10x-ARM microcontroller is a powerful and widely used microcontroller in embedded systems development. This repository aims to provide a collection of custom drivers written in C for this microcontroller, making it easier to develop applications and interact with various peripherals.

# Testing Video

[![IMAGE ALT TEXT HERE](https://github.com/Eng-Mohamed-Maged/STM32F10x-ARM-Drivers-Projects/blob/main/02-%20STM32F10x-ARM-Projects/04-%20TEST_LED_MATRIX_DRIVER/32.png)](https://www.youtube.com/watch?v=VlsqEy3nn9k)

# Getting Started
To get started with using these drivers in your STM32F10x-ARM project, follow these steps:
1. Clone or download this repository to your development environment.
2. Copy the required driver files from the repository to your project directory.
3. Include the necessary driver header files in your source code.
4. Configure the microcontroller's peripherals and initialize the drivers as needed.
5. Build and flash your project onto the STM32F10x-ARM microcontroller.


<h3 align="left">Connect with me:</h3>
<p align="left">
<a href="https://www.linkedin.com/in/mohamed-maged-1237981b4" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="https://www.linkedin.com/in/mohamed-maged-1237981b4" height="30" width="40" /></a>
<a href="https://www.youtube.com/channel/UCqFdD_fUftFl9dtfEshGGYg" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/youtube.svg" alt="@mohamedmaged7686" height="35" width="40" /></a>
<a href="https://mail.google.com/mail/?view=cm&fs=1&to=mohamed.maged.khalil1@gmail.com" target="blank"><img align="center" src="https://github.com/Eng-Mohamed-Maged/Eng-Mohamed-Maged/blob/main/gmail.svg" height="38" width="40" /></a>
</p>
