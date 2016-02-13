/*
 * Cocktail.cpp
 *
 *  Created on: 05-05-2014
 *      Author: agnieszka
 */

#include <string>
#include "Cocktail.h"


using namespace std;

Cocktail::Cocktail()
{
}

Cocktail::Cocktail(string n)
{
    name = n;
}

Cocktail::Cocktail(string n, string path, string base, string optional)
{
    name = n;
    imagePath = path;
    baseRecipe = base;
    optionalRecipe = optional;
}

Cocktail::~Cocktail()
{
}

string Cocktail::getName()
{
    return name;
}

string Cocktail::getImagePath()
{
    return imagePath;
}

string Cocktail::getBaseRecipe()
{
    return baseRecipe;
}

string Cocktail::getOptionalRecipe()
{
    return optionalRecipe;
}

list<Ingredient*> Cocktail::getIngredientList()
{
    return ingredientList;
}

void Cocktail::setName(string n)
{
    name = n;
}

void Cocktail::setImagePath(string path)
{
    imagePath = path;
}

void Cocktail::setBaseRecipe(string base)
{
    baseRecipe = base;
}

void Cocktail::setOptionalRecipe(string optional)
{
    optionalRecipe = optional;
}

void Cocktail::setIngredientList(list<Ingredient*> list)
{
    ingredientList = list;
}

void Cocktail::addIngredient(Ingredient* ingredient)
{
    ingredientList.push_back(ingredient);
}
