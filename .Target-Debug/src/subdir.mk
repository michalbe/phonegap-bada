################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/badaJS.cpp \
../src/badaJSEntry.cpp 

OBJS += \
./src/badaJS.o \
./src/badaJSEntry.o 

CPP_DEPS += \
./src/badaJS.d \
./src/badaJSEntry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: bada C++ Compiler'
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"D:/programowanie/bada/1.0.0b3/include" -I"D:/programowanie/bada/1.0.0b3/IDE/workspace/Phonegap/inc" -O0 -g -Wall -fpic -fshort-wchar -mcpu=cortex-a8 -mfpu=vfpv3 -mfloat-abi=hard -mlittle-endian -mthumb-interwork -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	arm-samsung-nucleuseabi-g++ -D_DEBUG -DSHP -I"D:/programowanie/bada/1.0.0b3/include" -I"D:/programowanie/bada/1.0.0b3/IDE/workspace/Phonegap/inc" -O0 -g -Wall -fpic -fshort-wchar -mcpu=cortex-a8 -mfpu=vfpv3 -mfloat-abi=hard -mlittle-endian -mthumb-interwork -E -o"D:/programowanie/bada/1.0.0b3/IDE/workspace/repository/Phonegap/Target-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


