/*
 * CoctailParserFiles.h
 *
 *  Created on: 05-05-2014
 *      Author: agnieszka
 */

#ifndef COCKTAILPARSERFILESMANAGEMENT_H_
#define COCKTAILPARSERFILESMANAGEMENT_H_

#include <iostream>
#include <fstream>

class CocktailParserFiles
{
public:
    CocktailParserFiles();
    virtual ~CocktailParserFiles();

    char getNextChar();
    bool openFile(std::string);
    bool closeFile();
    bool saveToFile(std::string);

private:
    std::ofstream file;

};

#endif /* COCKTAILPARSERFILES_H_ */
