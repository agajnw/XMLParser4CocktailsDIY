/*
 * Cocktail.h
 *
 *  Created on: 05-05-2014
 *      Author: agnieszka
 */

#ifndef COCKTAIL_H_
#define COCKTAIL_H_

#include <string>
#include <list>
#include "Ingredient.h"

class Cocktail
{
public:
    Cocktail();
    Cocktail(std::string);
    Cocktail(std::string, std::string, std::string, std::string);
    virtual ~Cocktail();

    std::string getName();
    std::string getImagePath();
    std::string getBaseRecipe();
    std::string getOptionalRecipe();
    std::list<Ingredient*> getIngredientList();

    void setName(std::string);
    void setImagePath(std::string);
    void setBaseRecipe(std::string);
    void setOptionalRecipe(std::string);
    void setIngredientList(std::list<Ingredient*>);

    void addIngredient(Ingredient*);


private:
    std::string name;
    std::string imagePath;
    std::string baseRecipe;
    std::string optionalRecipe;
    std::list<Ingredient*> ingredientList;

};

#endif /* COCKTAIL_H_ */
