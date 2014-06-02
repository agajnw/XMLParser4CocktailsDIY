/*
 * coctailparser.cpp
 *
 *  Created on: 05-05-2014
 *      Author: agnieszka
 */


#include <algorithm>
#include "CocktailParser.h"

using namespace std;

CocktailParser::CocktailParser() {
	cocktail = new Cocktail();
}

CocktailParser::~CocktailParser() {
	if (cocktail)
			delete cocktail;
}

void CocktailParser::importCocktailFromFile(string filename)
{
	//
}

bool CocktailParser::exportCocktailToFile(string filename)
{
	//
	return true;
}

void CocktailParser::createCocktail(string n)
{
	if (cocktail)
		delete cocktail;
	cocktail = new Cocktail(n);
}

void CocktailParser::createCocktail(string n, string p, string b, string o)
{
	if (cocktail)
			delete cocktail;
	cocktail = new Cocktail(n, p, b, o);
}

void CocktailParser::addIngredient(string name, string quantity, bool important)
{
	Ingredient *i = new Ingredient(name, quantity, important);
	cocktail->addIngredient(i);
}

void CocktailParser::setName(string name)
{
	cocktail->setName(name);
}

void CocktailParser::setImagePath(string path)
{
	cocktail->setImagePath(path);
}

void CocktailParser::setBaseRecipe(string base)
{
	cocktail->setBaseRecipe(base);
}

void CocktailParser::setOptionalRecipe(string optional)
{
	cocktail->setOptionalRecipe(optional);
}

void CocktailParser::changeIngredient(string name, string quantity,string important)
{
	//cocktail->changeIngredient(name, quantity, important);
}

string CocktailParser::getName()
{
	return cocktail->getName();
}

string CocktailParser::getImagePath()
{
	return cocktail->getImagePath();
}

string CocktailParser::getBaseRecipe()
{
	return cocktail->getBaseRecipe();
}

string CocktailParser::getOptionalRecipe()
{
	return cocktail->getOptionalRecipe();
}

list<Ingredient*> CocktailParser::getIngredientList()
{
	return cocktail->getIngredientList();
}
