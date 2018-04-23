################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bfs.cpp \
../src/connection.cpp \
../src/dfs.cpp \
../src/graph.cpp \
../src/line.cpp \
../src/parsing.cpp \
../src/tram_stop.cpp \
../src/tree.cpp 

OBJS += \
./src/bfs.o \
./src/connection.o \
./src/dfs.o \
./src/graph.o \
./src/line.o \
./src/parsing.o \
./src/tram_stop.o \
./src/tree.o 

CPP_DEPS += \
./src/bfs.d \
./src/connection.d \
./src/dfs.d \
./src/graph.d \
./src/line.d \
./src/parsing.d \
./src/tram_stop.d \
./src/tree.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


