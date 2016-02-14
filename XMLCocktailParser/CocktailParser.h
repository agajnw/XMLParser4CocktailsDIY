#ifndef COCTAILPARSER_H_
#define COCTAILPARSER_H_

#include <iostream>
#include "Cocktail.h"
#include "parserDriver.hh"

#define TRACE_SCANNING 0
#define TRACE_PARSING 0

class CocktailParser
{
public:
    CocktailParser();
    virtual ~CocktailParser();

    int importCocktailFromFile(std::string filename);
    bool exportCocktailToFile(std::string filename);
    void createCocktail(std::string);
    void createCocktail(std::string, std::string, std::string, std::string);
    void setName(std::string name);
    void setImagePath(std::string path);
    void setBaseRecipe(std::string base);
    void setOptionalRecipe(std::string optional);
    void addIngredient(std::string name, std::string quantity, bool important);
    void addIngredient(Ingredient *i);
    std::string getName();
    std::string getImagePath();
    std::string getBaseRecipe();
    std::string getOptionalRecipe();
    std::list<Ingredient*> getIngredientList();

    Cocktail* getCocktail()
    {
        return cocktail;
    }

private:
    Cocktail* cocktail;
    parserDriver driver;
};

#endif /* COCTAILPARSER_H_ */
