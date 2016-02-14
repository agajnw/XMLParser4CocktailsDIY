#line 11471 "./doc/bison.texi"
#include <iostream>
#include "CocktailParser.h"
#include "parserDriver.hh"
using namespace std;


void printCocktail(Cocktail* c)
{
    if (!c)
        return;
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
}


int
main (int argc, char *argv[])
{
    CocktailParser* parser = new CocktailParser();

    if (argc<2)
        return 0;

    if (parser->importCocktailFromFile(argv[1]))
    {
        std::cout << "Import successfull\n";

        printCocktail(parser->getCocktail());

        if (argc>2)
        {
            if (!parser->exportCocktailToFile(argv[2]))
                std::cout << "Unable to write to file: " << argv[2] << endl;
            else
                std::cout << "Written to file: " << argv[2] << endl;
        }

    }

    return 0;
}

