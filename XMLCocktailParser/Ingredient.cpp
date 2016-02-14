#include "Ingredient.h"

using namespace std;

Ingredient::Ingredient()
{
    important = false;
}

Ingredient::Ingredient(string n, string q, bool i)
{
    name = n;
    quantity = q;
    important = i;
}

Ingredient::~Ingredient()
{
}

string Ingredient::getName()
{
    return name;
}

string Ingredient::getQuantity()
{
    return quantity;
}

bool Ingredient::isImportant()
{
    return important;
}

void Ingredient::setName(std::string n)
{
    name = n;
}

void Ingredient::setQuantity(std::string q)
{
    quantity = q;
}

void Ingredient::setImportance(bool i)
{
    important = i;
}
