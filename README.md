/**
 * @mainpage : XC32 and PIC32 projects base
 */
# SAMD21 with MPLAB Harmony3

This project is part of ongoing experiments with the SAMD21 and FreeRTOS.

## Operation

There are three tasks in this application in this commit. ``` app()``` is the dispatcher that adds commands to the queue. The queue itself is 1 long so data is quickly overwritten. Each ``` app1() and app2() ``` will read the queue and if the command is received, they will execute an operation or turning the LED ON and OFF respectively.

Code uses Queue Peek to see if command is meant for a thread and then remove it from the queue along with appropriate LED operation.

## Changelog 
 All major changes are documented in CHANGELOG.md

## Block Diagram for Firmware

block diagram goes here
