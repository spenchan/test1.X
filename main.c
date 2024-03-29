/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F15376
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    channel_AND0_WPU = 0b0000000;
    WPUA = 0b0000000;
    WPUB = 0b0000000;
    WPUD = 0b0000000;
    //WPUEN = 0b0;
    TRISB = 0b0000000;
    TRISD = 0b0000000;
    
    channel_ANB0_SetLow();
    
    while (1)
    {
        int i = ADC_GetConversion(channel_ANB0);
        // Add your application code
        if(i > 100){
            IO_RA0_SetHigh();
            IO_RA1_SetHigh();
            IO_RA2_SetHigh();
            IO_RA3_SetHigh();
            IO_RA4_SetHigh();
        }
        else if(i > 80){
            IO_RA0_SetHigh();
            IO_RA1_SetHigh();
            IO_RA2_SetHigh();
            IO_RA3_SetHigh();
            IO_RA4_SetLow();
        } 
        else if(i > 60){
            IO_RA0_SetHigh();
            IO_RA1_SetHigh();
            IO_RA2_SetHigh();
            IO_RA3_SetLow();
            IO_RA4_SetLow();
        }
        else if(i > 40){
            IO_RA0_SetHigh();
            IO_RA1_SetHigh();
            IO_RA2_SetLow();
            IO_RA3_SetLow();
            IO_RA4_SetLow();
        }
        else if(i > 20){
            IO_RA0_SetHigh();
            IO_RA1_SetLow();
            IO_RA2_SetLow();
            IO_RA3_SetLow();
            IO_RA4_SetLow();
        }
        else{
            IO_RA0_SetLow();
            IO_RA1_SetLow();
            IO_RA2_SetLow();
            IO_RA3_SetLow();
            IO_RA4_SetLow();
        }
    }
}
/**
 End of File
*/