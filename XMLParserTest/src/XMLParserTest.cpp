//============================================================================
// Name        : XMLParserTest.cpp
// Author      : Agnieszka Janowicz
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CocktailParser.h"
#include "Cocktail.h"

using namespace std;

void printCocktail(Cocktail* c)
{
	if (!c)
		return;
	cout << "____________________" << endl;
	if (!c->getName().empty())
		cout << "Name: " << c->getName() << endl;
	if (!c->getImagePath().empty())
		cout << "Image path: " << c->getImagePath() << endl;
	if (!c->getBaseRecipe().empty())
		cout << "Base recipe: " << c->getBaseRecipe() << endl;
	if (!c->getOptionalRecipe().empty())
		cout << "Optional recipe: " << c->getOptionalRecipe() << endl;
	if (!c->getIngredientList().empty())
	{
		list<Ingredient*> list = c->getIngredientList();
		cout << "Ingredients: " << list.size() << endl;
		while (!list.empty())
		{
			Ingredient* i =  list.front();
			cout << i->getName() << " " << i->getQuantity() << " " << i->isImportant() << endl;
			list.pop_front();
		}
	}
	cout << "____________________" << endl;
}

int main() {
	cout << "Hello World" << endl; // prints Hello World

	CocktailParser* parser = new CocktailParser();
	parser->createCocktail("drink");
	parser->setImagePath("path/to/file");
	parser->setBaseRecipe("This is the base recipe");
	parser->setOptionalRecipe("This is the optional recipe");
	parser->addIngredient("vodka", "100ml", true);
	parser->addIngredient("blue couracao", "100ml", true);
	parser->addIngredient("sprite", "200ml", true);
	parser->addIngredient("lemon", "half", false);

	printCocktail(parser->getCocktail());

	return 0;
}
