################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Avion.cpp \
../src/AvionHidrante.cpp \
../src/AvionPasajeros.cpp \
../src/Ejercicio411.cpp 

OBJS += \
./src/Avion.o \
./src/AvionHidrante.o \
./src/AvionPasajeros.o \
./src/Ejercicio411.o 

CPP_DEPS += \
./src/Avion.d \
./src/AvionHidrante.d \
./src/AvionPasajeros.d \
./src/Ejercicio411.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


