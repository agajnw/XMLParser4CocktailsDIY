#ifndef parserDriver_HH
# define parserDriver_HH
# include <string>
# include <map>
# include "parserParser.hh"
# include "Cocktail.h"
// tell Flex the lexer's prototype
# define YY_DECL \
  yy::parserParser::symbol_type yylex (parserDriver& driver)

YY_DECL;

class parserDriver
{
public:
    parserDriver ();
    virtual ~parserDriver ();

    Cocktail *c;

    //helper variables for making Ingredient
    Ingredient *ingredient;
    std::string ingredientName;
    std::string ingredientQuantity;
    bool ingredientImportant;

    int result;

    // Handling the scanner.
    void scan_begin ();
    void scan_end ();
    bool trace_scanning;

    // Run the parser on file F.
    // Return 0 on success.
    int parse (const std::string& f, Cocktail* ck);
    // The name of the file being parsed.
    // Used later to pass the file name to the location tracker.
    std::string file;
    // Whether parser traces should be generated.
    bool trace_parsing;

    // Error handling.
    void error (const yy::location& l, const std::string& m);
    void error (const std::string& m);
};
#endif //  parserDriver_HH
