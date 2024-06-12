################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/main.c 

OBJS += \
./APP/main.o 

C_DEPS += \
./APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL\7_Ssegment" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL\BTNS" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL\DC_MOTOR" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL\EEPROM" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL\KEYPAD" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL\LCD" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL\LED" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\LIB" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\ADC" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\DIO" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\EXINT" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\GIE" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\I2C" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\SPI" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\TIMER0" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\TIMER1" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\TWI" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\UART" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\WDT" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\TWI" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\DIO" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\LIB" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


