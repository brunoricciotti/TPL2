################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DR_myPINSEL.c \
../src/MyDR_ADC.c \
../src/MyDR_DAC.c \
../src/TPL2_IIR_butterworth.c \
../src/arm_biquad_cascade_df1_init_q31.c \
../src/arm_biquad_cascade_df1_q31.c \
../src/arm_float_to_q31.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/math_helper.c 

C_DEPS += \
./src/DR_myPINSEL.d \
./src/MyDR_ADC.d \
./src/MyDR_DAC.d \
./src/TPL2_IIR_butterworth.d \
./src/arm_biquad_cascade_df1_init_q31.d \
./src/arm_biquad_cascade_df1_q31.d \
./src/arm_float_to_q31.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/math_helper.d 

OBJS += \
./src/DR_myPINSEL.o \
./src/MyDR_ADC.o \
./src/MyDR_DAC.o \
./src/TPL2_IIR_butterworth.o \
./src/arm_biquad_cascade_df1_init_q31.o \
./src/arm_biquad_cascade_df1_q31.o \
./src/arm_float_to_q31.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/math_helper.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"D:\Documentos\TC2\TPL2\IIR_butterworth\inc" -I"D:\Documentos\TC2\TPL2\IIR_butterworth\inc\inc" -I"D:\Documentos\TC2\TPL2\IIR_butterworth\CMSIS\DSP\Include" -I"D:\Documentos\TC2\TPL2\IIR_butterworth\CMSIS\Core\Include" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/DR_myPINSEL.d ./src/DR_myPINSEL.o ./src/MyDR_ADC.d ./src/MyDR_ADC.o ./src/MyDR_DAC.d ./src/MyDR_DAC.o ./src/TPL2_IIR_butterworth.d ./src/TPL2_IIR_butterworth.o ./src/arm_biquad_cascade_df1_init_q31.d ./src/arm_biquad_cascade_df1_init_q31.o ./src/arm_biquad_cascade_df1_q31.d ./src/arm_biquad_cascade_df1_q31.o ./src/arm_float_to_q31.d ./src/arm_float_to_q31.o ./src/cr_startup_lpc175x_6x.d ./src/cr_startup_lpc175x_6x.o ./src/crp.d ./src/crp.o ./src/math_helper.d ./src/math_helper.o

.PHONY: clean-src

