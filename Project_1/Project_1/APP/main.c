/*
 * main.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Mohamed_Atef
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_init.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "LCD_Interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include "string.h"

// Array to store ADC values for each channel
volatile u16 Digital_Values[5] = {0};

// Index to keep track of the current ADC channel
volatile u8 current_channel = 0;

// List of channels to be sampled
ADC_channel channels[] = { 0, 1, 2, 3, 4 }; // Example channels for flex sensors

// ADC complete callback function
void ADC_Complete_Callback(void) {
    // Store the ADC result (10-bit value)
    Digital_Values[current_channel] = (int)ADCL | (int)(ADCH << 8);

    // Move to the next channel
    current_channel++;
    if (current_channel >= sizeof(channels) / sizeof(channels[0])) {
        current_channel = 0; // Reset to the first channel
    }
    // Start the next ADC conversion
    ADMUX = (ADMUX & 0xE0) | channels[current_channel]; // Select the next channel
    SET_BIT(ADCSRA, ADSC); // Start ADC conversion
}

int main(void) {
    // Set direction for LCD data port to output
    DIO_VoidSetPortDirection(1, OUTPUT);
    LCD_VoidInit(); // Initialize LCD
    DIO_VoidSetPinDirection(DIO_PINA0, INPUT); // Set pin A0 as input
    DIO_VoidSetPinDirection(DIO_PINA1, INPUT); // Set pin A1 as input
    DIO_VoidSetPinDirection(DIO_PINA2, INPUT); // Set pin A2 as input
    DIO_VoidSetPinDirection(DIO_PINA3, INPUT); // Set pin A3 as input
    DIO_VoidSetPinDirection(DIO_PINA4, INPUT); // Set pin A4 as input
    DIO_VoidSetPortDirection(3, 0xFF); // Set port 3 to output

    ADC_INIT(Internal_Voltage_Reference); // Initialize ADC with internal voltage reference

    ADC_VoidCallBack(ADC_Complete_Callback); // Set the ADC complete callback function

    M_GIE_VoidEnable(); // Enable global interrupts

    // Start the first ADC conversion
    start_ADC_conversion(channels[current_channel]);

    // Strings to be stored in EEPROM
    u8 lastMessage[16] = "";

    u8 message1[] = "This is terrible";
    u8 message2[] = "I Love You";
    u8 message3[] = "I Really Love You";
    u8 message4[] = "Good Job";
    u8 message5[] = "I'm watching you";
    u8 message6[] = "You";

    // Buffers to hold the read data from EEPROM
    u8 received1[16] = "";
    u8 received2[16] = "";
    u8 received3[16] = "";
    u8 received4[16] = "";
    u8 received5[16] = "";
    u8 received6[16] = "";

    // Write the strings to EEPROM starting at specific addresses
    EEPROM_WRITE_String(0, message1);
    EEPROM_WRITE_String(20, message2);
    EEPROM_WRITE_String(40, message3);
    EEPROM_WRITE_String(60, message4);
    EEPROM_WRITE_String(80, message5);
    EEPROM_WRITE_String(100, message6);
    _delay_ms(100); // Delay for EEPROM write completion

    // Read the strings from EEPROM
    EEPROM_READ_String(0, received1, sizeof(message1));
    EEPROM_READ_String(20, received2, sizeof(message2));
    EEPROM_READ_String(40, received3, sizeof(message3));
    EEPROM_READ_String(60, received4, sizeof(message4));
    EEPROM_READ_String(80, received5, sizeof(message5));
    EEPROM_READ_String(100, received6, sizeof(message6));

    // Ensure strings are null-terminated
    received1[sizeof(message1) - 1] = '\0';
    received2[sizeof(message2) - 1] = '\0';
    received3[sizeof(message3) - 1] = '\0';
    received4[sizeof(message4) - 1] = '\0';
    received5[sizeof(message5) - 1] = '\0';
    received6[sizeof(message6) - 1] = '\0';

    while (1) {
        u8 currentMessage[16] = "";

        // Check conditions based on ADC values and set the appropriate message
        //if We will use the EEPROM we will replace the messge[1-6] with received[1-6]
        if (Digital_Values[0] > 837 && Digital_Values[2] > 837 && Digital_Values[3] > 837 &&
            Digital_Values[4] < 837 && Digital_Values[1] < 837) {
            strcpy(currentMessage, message1);
        } else if (Digital_Values[2] > 837 && Digital_Values[3] > 837 &&
                   Digital_Values[0] < 837 && Digital_Values[1] < 837 && Digital_Values[4] < 837) {
            strcpy(currentMessage, message2);
        } else if (Digital_Values[3] > 837 && Digital_Values[0] < 837 &&
                   Digital_Values[1] < 837 && Digital_Values[2] < 837 && Digital_Values[4] < 837) {
            strcpy(currentMessage, message3);
        } else if (Digital_Values[1] > 837 && Digital_Values[2] > 837 && Digital_Values[3] > 837 &&
                   Digital_Values[4] > 837 && Digital_Values[0] < 837) {
            strcpy(currentMessage, message4);
        } else if (Digital_Values[0] > 837 && Digital_Values[3] > 837 && Digital_Values[4] > 837 &&
                   Digital_Values[2] < 837 && Digital_Values[1] < 837) {
            strcpy(currentMessage, message5);
        } else if (Digital_Values[0] > 837 && Digital_Values[3] > 837 && Digital_Values[4] > 837 &&
                   Digital_Values[2] > 837 && Digital_Values[1] < 837) {
            strcpy(currentMessage, message6);
        } else {
            LCD_VoidClearScreen();
        }

        // Display the message on the LCD if it has changed
        if (strcmp(lastMessage, currentMessage) != 0) {
            displayMessage(currentMessage);
            strcpy(lastMessage, currentMessage);
        }
    }

    return 0;
}
