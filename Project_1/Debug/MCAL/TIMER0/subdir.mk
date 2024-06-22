################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER0/TIMER0_Program.c \
../MCAL/TIMER0/TIMER0_cfg.c 

OBJS += \
./MCAL/TIMER0/TIMER0_Program.o \
./MCAL/TIMER0/TIMER0_cfg.o 

C_DEPS += \
./MCAL/TIMER0/TIMER0_Program.d \
./MCAL/TIMER0/TIMER0_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER0/%.o: ../MCAL/TIMER0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL\EEPROM" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\HAL\LCD" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\LIB" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\ADC" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\DIO" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\GIE" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\TIMER0" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\TWI" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL\DIO" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\LIB" -I"D:\embedded system diploma\AMIT_Graduation_Project\Project_1\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


