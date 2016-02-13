/*
 * Ingredient.h
 *
 *  Created on: 05-05-2014
 *      Author: agnieszka
 */

#ifndef INGREDIENT_H_
#define INGREDIENT_H_

#include <string>

class Ingredient
{
public:
    Ingredient();
    Ingredient(std::string, std::string, bool);
    virtual ~Ingredient();

    std::string getName();
    std::string getQuantity();
    bool isImportant();

    void setName(std::string);
    void setQuantity(std::string);
    void setImportance(bool);

private:
    std::string name;
    std::string quantity;
    bool important;
};

#endif /* INGREDIENT_H_ */
