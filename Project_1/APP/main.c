#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"

volatile u16 Digital_Values[5] = { 0 }; // Array to store ADC values for each channel
volatile u8 current_channel = 0; // Index to keep track of the current ADC channel

// List of channels to be sampled
ADC_channel channels[] = { 0, 1, 2, 3, 4 }; // Example channels for flex sensors

void ADC_Complete_Callback(void) {
	// Store the ADC result (10-bit value)
	Digital_Values[current_channel] = (int) ADCL + (int) ADCH * 256;

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

	DIO_VoidSetPortDirection(1, OUTPUT);
	LCD_VoidInit();
	DIO_VoidSetPinDirection(DIO_PINA0, INPUT);
	DIO_VoidSetPinDirection(DIO_PINA1, INPUT);
	DIO_VoidSetPinDirection(DIO_PINA2, INPUT);
	DIO_VoidSetPinDirection(DIO_PINA3, INPUT);
	DIO_VoidSetPinDirection(DIO_PINA4, INPUT);
	DIO_VoidSetPortDirection(3, 0xFF);
	// Initialize ADC with internal voltage reference
	ADC_INIT(Internal_Voltage_Reference);

	// Set the ADC complete callback function
	ADC_VoidCallBack(ADC_Complete_Callback);

	// Enable global interrupts
	M_GIE_VoidEnable();

	start_ADC_conversion(channels[current_channel]);

	u8 lastMessage[16] = "";

	u8 message1[] = "This is terrible";
	u8 message2[] = "I Love You";
	u8 message3[] = "I Really Love You";
	u8 message4[] = "Good Job";
	u8 message5[] = "I'm watching you";
	u8 message6[] = "You";

	u8 received1[16] = ""; // Ensure this buffer is large enough to hold the read data
	u8 received2[16] = "";
	u8 received3[16] = "";
	u8 received4[16] = "";
	u8 received5[16] = "";
	u8 received6[16] = "";
	// Write the string to EEPROM starting at address 0x0000
//	EEPROM_WRITE_String(0, message1);
//	EEPROM_WRITE_String(20, message2);
//	EEPROM_WRITE_String(40, message3);
//	EEPROM_WRITE_String(60, message4);
//	EEPROM_WRITE_String(80, message5);
//	EEPROM_WRITE_String(100, message6);
	_delay_ms(100);

//	EEPROM_READ_String(0, received1, sizeof(message1));
//	EEPROM_READ_String(20, received1, sizeof(message2));
//	EEPROM_READ_String(40, received1, sizeof(message3));
//	EEPROM_READ_String(60, received1, sizeof(message4));
//	EEPROM_READ_String(80, received1, sizeof(message5));
//	EEPROM_READ_String(100, received1, sizeof(message6));

//	received1[sizeof(message1) - 1] = '\0';
//	received2[sizeof(message2) - 1] = '\0';
//	received3[sizeof(message3) - 1] = '\0';
//	received4[sizeof(message4) - 1] = '\0';
//	received5[sizeof(message5) - 1] = '\0';
//	received6[sizeof(message6) - 1] = '\0';

	while (1) {
		u8 currentMessage[16] = "";

		if (Digital_Values[0] > 837 && Digital_Values[2] > 837
				&& Digital_Values[3] > 837 && Digital_Values[4] < 837
				&& Digital_Values[1] < 837) {
			strcpy(currentMessage, received1);
		} else if (Digital_Values[2] > 837 && Digital_Values[3] > 837
				&& Digital_Values[0] < 837 && Digital_Values[1] < 837
				&& Digital_Values[4] < 837) {
			strcpy(currentMessage, received2);
		} else if (Digital_Values[3] > 837 && Digital_Values[0] < 837
				&& Digital_Values[1] < 837 && Digital_Values[2] < 837
				&& Digital_Values[4] < 837) {
			strcpy(currentMessage, received3);
		} else if (Digital_Values[1] > 837 && Digital_Values[2] > 837
				&& Digital_Values[3] > 837 && Digital_Values[4] > 837
				&& Digital_Values[0] < 837) {
			strcpy(currentMessage, received4);
		} else if (Digital_Values[0] > 837 && Digital_Values[3] > 837
				&& Digital_Values[4] > 837 && Digital_Values[2] < 837
				&& Digital_Values[1] < 837) {
			strcpy(currentMessage, received5);
		} else if (Digital_Values[0] > 837 && Digital_Values[3] > 837
				&& Digital_Values[4] > 837 && Digital_Values[2] > 837
				&& Digital_Values[1] < 837) {
			strcpy(currentMessage, received6);
		} else {
			LCD_VoidClearScreen();
		}

		if (strcmp(lastMessage, currentMessage) != 0) {
			displayMessage(currentMessage);
			strcpy(lastMessage, currentMessage);
		}
	}

	return 0;
}
