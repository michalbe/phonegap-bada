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
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"D:/programowanie/bada/1.0.0b3/include" -I"D:/programowanie/bada/1.0.0b3/IDE/workspace/Phonegap/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	i686-mingw32-g++ -D_DEBUG -DSHP -DBUILD_DLL -I"D:/programowanie/bada/1.0.0b3/include" -I"D:/programowanie/bada/1.0.0b3/IDE/workspace/Phonegap/inc" -O0 -g3 -Wall -E -fmessage-length=0 -o"D:/programowanie/bada/1.0.0b3/IDE/workspace/repository/Phonegap/Simulator-Debug/$(notdir $(basename $@).i)" "$<"
	@echo 'Finished building: $<'
	@echo ' '


