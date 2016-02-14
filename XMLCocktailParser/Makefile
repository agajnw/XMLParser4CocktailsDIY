all: TestProgram.out

TestProgram.out: parserDriver.o parserParser.o parserScanner.o TestProgram.o Cocktail.o Ingredient.o CocktailParser.o

	g++ -o TestProgram.out parserDriver.o parserParser.o parserScanner.o TestProgram.o Cocktail.o Ingredient.o CocktailParser.o

parserDriver.o: parserDriver.cc parserDriver.hh parserParser.hh Cocktail.h

	g++ -c parserDriver.cc

parserParser.o: parserParser.cc parserParser.hh parserDriver.hh Cocktail.h

	g++ -c parserParser.cc

parserParser.cc parserParser.hh: parserParser.yy

	bison --defines=parserParser.hh -oparserParser.cc parserParser.yy

parserScanner.o: parserScanner.cc parserParser.hh parserDriver.hh Cocktail.h

	g++ -c parserScanner.cc

parserScanner.cc: parserScanner.ll

	flex -o parserScanner.cc parserScanner.ll

CocktailParser.o: CocktailParser.cpp CocktailParser.h parserDriver.hh Cocktail.h

	g++ -c CocktailParser.cpp

Cocktail.o: Cocktail.cpp Cocktail.h Ingredient.h

	g++ -c Cocktail.cpp

Ingredient.o: Ingredient.cpp Ingredient.h

	g++ -c Ingredient.cpp

TestProgram.o: TestProgram.cc

	g++ -c TestProgram.cc

.PHONY: clean

clean:

	-rm *.o parserParser.hh parserParser.cc parserScanner.cc TestProgram.out
