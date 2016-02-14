#include <algorithm>
#include <iostream>
#include <fstream>
#include "CocktailParser.h"

using namespace std;

CocktailParser::CocktailParser()
{
    cocktail = new Cocktail();

    if (TRACE_PARSING)
        driver.trace_parsing = true;
    else if (TRACE_SCANNING)
        driver.trace_scanning = true;
}

CocktailParser::~CocktailParser()
{
    if (cocktail)
        delete cocktail;
}

int CocktailParser::importCocktailFromFile(string filename)
{

    if (driver.parse(filename, cocktail))
    {
        std::cout << driver.result << std::endl;
        std::cout << "parser error\n";
        return 0;
    }
    else
        return 1;
}

bool CocktailParser::exportCocktailToFile(string file)
{
    if (file.empty())
        return false;
    fstream fileToParse(file.c_str(), ios::out | ios::in | ios::trunc);
    if (!fileToParse.is_open())
        return false;
    fileToParse << "<cocktail>\n";
    fileToParse << "<name>" << cocktail->getName() << "</name>\n";
    fileToParse << "<image>" << cocktail->getImagePath() << "</image>\n";
    fileToParse << "<recipe>\n";
    fileToParse << "<base>" << cocktail->getBaseRecipe() << "</base>\n";
    fileToParse << "<optional>" << cocktail->getOptionalRecipe() << "</optional>\n";
    fileToParse << "</recipe>\n";
    fileToParse << "<ingredients>\n";

    list<Ingredient*> list = cocktail->getIngredientList();
    while (!list.empty())
    {
        Ingredient* i =  list.front();
        fileToParse << "<ingredient>\n";
        fileToParse << "<name>" << i->getName() << "</name>\n";
        fileToParse << "<quantity>" << i->getQuantity() << "</quantity>\n";

        if (i->isImportant())
            fileToParse << "<important>yes</important>\n";
        else
            fileToParse << "<important>no</important>\n";

        fileToParse << "</ingredient>\n";

        list.pop_front();
    }

    fileToParse << "</ingredients>\n";
    fileToParse << "</cocktail>\n";

    fileToParse.close();
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

void CocktailParser::addIngredient(Ingredient *i)
{
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
