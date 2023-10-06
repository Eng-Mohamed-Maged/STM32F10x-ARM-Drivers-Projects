# STM32F10x Testing for LED Matrix, IR Remote, and RGB LED

# Table of Contents
- Introduction
- Testing Video
- Getting Started
- Connect with me

# Introduction
This code aims to perform a comprehensive test on an 8x8 LED Matrix with IR Remote using the STM32F10x microcontroller.
The code is structured as follows:
## Hardware Abstraction Layer (HAL):
- LED Matrix
- IR Remote
- RGB LED
## Microcontroller Abstraction Layer (MCAL):
- RCC (Reset and Clock Control)
- GPIO (General Purpose Input/Output)
- NVIC (Nested Vector Interrupt Controller)
- AFIO (Alternate Function Input/Output)
- EXTI (External Interrupt/Event Controller)
- SysTick
- Timers
## Library Layer (LIB):
- STD TYPES
- BIT MATH

## The IR Remote is utilized in this code to control the following functionalities:
### For LED Matrix:
1) TO TURN ON AND DISPLAY "HELLO"
2) SPEED UP THE DISPLAYED TEXT 
3) SLOW DOWN THE DISPLAYED TEXT
4) DISPLAY A MAN BOUNCING A BALL

### For RGB LED :
1) TURN ON/OFF GREEN LED
2) TURN ON/OFF BLUE LED
3) TURN ON/OFF RED LED

### The RCC is used in this code for:
- Initializing the clock for the relevant ports and peripherals

### The GPIO is used in this code for:
- Configuring the directions and values for the used ports and pins

### The NVIC is used in this code to:
- Enable EXTI8 for the remote driver

### The EXTI is used in this code to:
- Enable EXTI LINE 8
- Set the signal latch to Falling Edge Mode

### The AFIO is used in this code for:
- Mapping EXTI8 pin to A8
  
### The SysTick is used in this code to:
- Handle the delay used in the LED Matrix

### The Timers (specifically **TIMER 2**) are used in this code to:
- Handle the delay used in receiving the IR Remote frame.


# Testing Video

[![IMAGE ALT TEXT HERE](https://github.com/Eng-Mohamed-Maged/STM32F10x-ARM-Drivers-Projects/blob/main/02-%20STM32F10x-ARM-Projects/05-%20TEST_IR_RGBLEDs_LEDMTX/0.png)](https://www.youtube.com/watch?v=VlsqEy3nn9k)

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
