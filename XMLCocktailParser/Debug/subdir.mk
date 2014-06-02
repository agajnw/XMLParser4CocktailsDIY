################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cocktail.cpp \
../CocktailParser.cpp \
../CocktailParserFiles.cpp \
../CocktailParserLexical.cpp \
../CocktailParserSyntaxial.cpp \
../Ingredient.cpp 

OBJS += \
./Cocktail.o \
./CocktailParser.o \
./CocktailParserFiles.o \
./CocktailParserLexical.o \
./CocktailParserSyntaxial.o \
./Ingredient.o 

CPP_DEPS += \
./Cocktail.d \
./CocktailParser.d \
./CocktailParserFiles.d \
./CocktailParserLexical.d \
./CocktailParserSyntaxial.d \
./Ingredient.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -fPIC -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


