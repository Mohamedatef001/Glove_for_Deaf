#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"

volatile u16 Digital_Values[5] = {0}; // Array to store ADC values for each channel
volatile u8 current_channel = 0; // Index to keep track of the current ADC channel

// List of channels to be sampled
ADC_channel channels[] = {0, 1, 2, 3, 4}; // Example channels for flex sensors


void ADC_Complete_Callback(void) {
    // Store the ADC result (10-bit value)
    Digital_Values[current_channel] = (int)ADCL + (int)ADCH * 256;

    // Move to the next channel
    current_channel++;
    if (current_channel >= sizeof(channels) / sizeof(channels[0])) {
        current_channel = 0; // Reset to the first channel
    }
    // Start the next ADC conversion
    ADMUX = (ADMUX & 0xE0) | channels[current_channel]; // Select the next channel
    SET_BIT(ADCSRA, ADSC); // Start ADC conversion
}
void displayMessage(const char* message) {
    LCD_VoidClearScreen();
    LCD_VoidWriteString(message);
}

int main(void) {

	LCD_VoidInit();
    // Initialize GPIO pins
    DIO_VoidSetPinDirection(DIO_PINA0, INPUT);
    DIO_VoidSetPinDirection(DIO_PINA1, INPUT);
    DIO_VoidSetPinDirection(DIO_PINA2, INPUT);
    DIO_VoidSetPinDirection(DIO_PINA3, INPUT);
    DIO_VoidSetPinDirection(DIO_PINA4, INPUT);
//    DIO_VoidSetPortDirection(2, 0xFF);
    DIO_VoidSetPortDirection(3, 0xFF);
    // Initialize ADC with internal voltage reference
    ADC_INIT(Internal_Voltage_Reference);

    // Set the ADC complete callback function
    ADC_VoidCallBack(ADC_Complete_Callback);


    // Enable global interrupts
    M_GIE_VoidEnable();

    // Start the first ADC conversion
    ADMUX = (ADMUX & 0xE0) | channels[current_channel]; // Select the first channel
       SET_BIT(ADCSRA, ADSC); // Start ADC conversion
       char* lastMessage = "";

       while (1)
       {
              // Process the ADC values set by the interrupt
//              if (Digital_Values[0] > 127)
//                  DIO_VoidSetPinValue(DIO_PINC7, DIO_HIGH);
//              else
//                  DIO_VoidSetPinValue(DIO_PINC7, DIO_LOW);
//              if (Digital_Values[1] > 381)
//                  DIO_VoidSetPinValue(DIO_PINC6, DIO_HIGH);
//              else
//                  DIO_VoidSetPinValue(DIO_PINC6, DIO_LOW);
//              if (Digital_Values[2] > 640)
//                  DIO_VoidSetPinValue(DIO_PINC5, DIO_HIGH);
//              else
//                  DIO_VoidSetPinValue(DIO_PINC5, DIO_LOW);
//              if (Digital_Values[3] > 890)
//                  DIO_VoidSetPinValue(DIO_PINC4, DIO_HIGH);
//              else
//                  DIO_VoidSetPinValue(DIO_PINC4, DIO_LOW);
//              if (Digital_Values[4] > 1016)
//                  DIO_VoidSetPinValue(DIO_PINC3, DIO_HIGH);
//              else
//                  DIO_VoidSetPinValue(DIO_PINC3, DIO_LOW);

    	   char* currentMessage = "";

    	   if(Digital_Values[0] > 837   && Digital_Values[2] > 837  && Digital_Values[3] > 837 && Digital_Values[4] < 837 && Digital_Values[1] < 837)
    	   {
    		   currentMessage = "This is terrible";
    	   }else if( Digital_Values[2] > 837  && Digital_Values[3] > 837 && Digital_Values[0] < 837 && Digital_Values[1] < 837 && Digital_Values[4] < 837)
    	   {
    		   currentMessage = "I Love You";
    	   }else if(Digital_Values[3] > 837 && Digital_Values[0] < 837 && Digital_Values[1] < 837 && Digital_Values[2] < 837 && Digital_Values[4] < 837)
    	   {
    		   currentMessage = "I Really Love You";
    	   }else if(Digital_Values[1] > 837 && Digital_Values[2] > 837 && Digital_Values[3] > 837 && Digital_Values[4] > 837&& Digital_Values[0] < 837)
    	   {
    		   currentMessage = "Good Job";
    	   }else if(Digital_Values[0] > 837 && Digital_Values[3] > 837 && Digital_Values[4] > 837 && Digital_Values[2] < 837 && Digital_Values[1] < 837)
    	   {
    		   currentMessage = "I'm watching you";
    	   }else if(Digital_Values[0] > 837 && Digital_Values[3] > 837 && Digital_Values[4] > 837 && Digital_Values[2] > 837 && Digital_Values[1] < 837)
    	   {
    		   currentMessage = "You";
    	   }else
    	   {
    		   LCD_VoidClearScreen();
    	   }



    	   if (strcmp(lastMessage, currentMessage) != 0)
    	   {
    	               displayMessage(currentMessage);
    	               lastMessage = currentMessage;
    	   }
       }

    return 0;
}
