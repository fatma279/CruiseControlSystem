################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Ultrasonic/Ultrasonic_Prog.c 

OBJS += \
./HAL/Ultrasonic/Ultrasonic_Prog.o 

C_DEPS += \
./HAL/Ultrasonic/Ultrasonic_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Ultrasonic/%.o: ../HAL/Ultrasonic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\APP" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\HAL\BLUETOOTH" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\MCAL\UART" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\HAL\RELAY" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\HAL\LCD" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\HAL\LED" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\HAL\Ultrasonic" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\LIB" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\MCAL\ADC" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\MCAL\DIO" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\MCAL\EXTI" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\MCAL\GIE" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\MCAL\TIMER0" -I"F:\nti embdded\AVR c\workshop\Cruise_Control_System\MCAL\TIMER1" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


