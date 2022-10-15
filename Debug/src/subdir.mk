################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/arm_fir_data.c \
../src/arm_fir_init_q31.c \
../src/arm_fir_q31.c \
../src/arm_float_to_q31.c \
../src/arm_q31_to_float.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/fir_eq_ripp.c \
../src/math_helper.c 

C_DEPS += \
./src/arm_fir_data.d \
./src/arm_fir_init_q31.d \
./src/arm_fir_q31.d \
./src/arm_float_to_q31.d \
./src/arm_q31_to_float.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/fir_eq_ripp.d \
./src/math_helper.d 

OBJS += \
./src/arm_fir_data.o \
./src/arm_fir_init_q31.o \
./src/arm_fir_q31.o \
./src/arm_float_to_q31.o \
./src/arm_q31_to_float.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/fir_eq_ripp.o \
./src/math_helper.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"D:\Documentos\TC2\TPL2\CMSIS\DSP\Include" -I"D:\Documentos\TC2\TPL2\CMSIS\Core\Include" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/arm_fir_data.d ./src/arm_fir_data.o ./src/arm_fir_init_q31.d ./src/arm_fir_init_q31.o ./src/arm_fir_q31.d ./src/arm_fir_q31.o ./src/arm_float_to_q31.d ./src/arm_float_to_q31.o ./src/arm_q31_to_float.d ./src/arm_q31_to_float.o ./src/cr_startup_lpc175x_6x.d ./src/cr_startup_lpc175x_6x.o ./src/crp.d ./src/crp.o ./src/fir_eq_ripp.d ./src/fir_eq_ripp.o ./src/math_helper.d ./src/math_helper.o

.PHONY: clean-src

