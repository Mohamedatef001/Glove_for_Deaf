################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TWI/TWI_Program.c \
../MCAL/TWI/TWI_cfg.c 

OBJS += \
./MCAL/TWI/TWI_Program.o \
./MCAL/TWI/TWI_cfg.o 

C_DEPS += \
./MCAL/TWI/TWI_Program.d \
./MCAL/TWI/TWI_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TWI/%.o: ../MCAL/TWI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\HAL" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\HAL\EEPROM" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\HAL\LCD" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\LIB" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\MCAL\ADC" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\MCAL\DIO" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\MCAL\GIE" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\MCAL\TIMER0" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\MCAL\TWI" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\MCAL\DIO" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\LIB" -I"D:\embedded system diploma\Glove_for_Deaf_Project\Project_1\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


