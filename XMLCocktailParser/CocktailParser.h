/*
 * coctailparser.h
 *
 *  Created on: 05-05-2014
 *      Author: agnieszka
 */

#ifndef COCTAILPARSER_H_
#define COCTAILPARSER_H_

#include <iostream>
#include "Cocktail.h"
#include "CocktailParserFiles.h"
#include "CocktailParserLexical.h"
#include "CocktailParserSyntaxial.h"

class CocktailParser {
public:
	CocktailParser();
	virtual ~CocktailParser();

	void importCocktailFromFile(std::string filename);
	bool exportCocktailToFile(std::string filename);
	void createCocktail(std::string);
	void createCocktail(std::string, std::string, std::string, std::string);
	void setName(std::string name);
	void setImagePath(std::string path);
	void setBaseRecipe(std::string base);
	void setOptionalRecipe(std::string optional);
	void addIngredient(std::string name, std::string quantity, bool important);
	void changeIngredient(std::string name, std::string quantity,std::string important);
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
};

#endif /* COCTAILPARSER_H_ */
