%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0"
%defines
%define parser_class_name {parserParser}

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires
{
# include <string>
class parserDriver;
}

// the parsing context
%param { parserDriver& driver }

%locations
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.file;
};

//enable location tracking
%define parse.trace
%define parse.error verbose

%code
{
# include "parserDriver.hh"
}

%define api.token.prefix {TOK_}
%token 
  END  		0  "end of file"
  YES 		"yes"
  NO  		"no"
  IMAGE1	"<image>"
  IMAGE2	"</image>"
  NAME1 	"<name>"
  NAME2 	"</name>"
  BASE1		"<base>"
  BASE2		"</base>"
  OPTIONAL1	"<optional>"
  OPTIONAL2	"</optional>"
  RECIPE1	"<recipe>"
  RECIPE2 	"</recipe>"
  QUANTITY1	"<quantity>"
  QUANTITY2	"</quantity>"
  IMPORTANT1	"<important>"
  IMPORTANT2	"/important>"
  INGREDIENT1	"<ingredient>"
  INGREDIENT2	"/ingredient>"
  INGREDIENTS1	"<ingredients>"
  INGREDIENTS2	"</ingredients>"
  COCKTAIL1	"<cocktail>"
  COCKTAIL2	"</cocktail>"
;

%token <std::string> STRING "string"
%token <int> NUMBER "number"


%printer { yyoutput << $$; } <*>;

%%
//file
file:	
	comment COCKTAIL1 cocktaildata COCKTAIL2 END |
	comment COCKTAIL1 cocktaildata COCKTAIL2 comment END |
	COCKTAIL1 cocktaildata COCKTAIL2 END
	END
	;

//cocktaildata
cocktaildata:
	name image recipe ingredients
	;

name:
	NAME1 STRING NAME2 {driver.c->setName($2);}
	| comment NAME1 STRING NAME2 {driver.c->setName($3);}
	;

image:
	IMAGE1 STRING IMAGE2 { driver.c->setImagePath($2);}
	| comment IMAGE1 STRING IMAGE2 { driver.c->setImagePath($3);}
	;

//recipe
recipe:
	RECIPE1 base optional RECIPE2	
	| comment RECIPE1 base optional RECIPE2
	;
base:
	BASE1 STRING BASE2 { driver.c->setBaseRecipe($2);}
	| comment BASE1 STRING BASE2 { driver.c->setBaseRecipe($3);}
	;

optional:
	OPTIONAL1 STRING OPTIONAL2 { driver.c->setOptionalRecipe($2);}
	| comment OPTIONAL1 STRING OPTIONAL2 { driver.c->setOptionalRecipe($3);}
	;

//ingredients
ingredients:
	INGREDIENTS1 ingredient INGREDIENTS2
	| comment INGREDIENTS1 ingredient INGREDIENTS2
	;

ingredient:
	ingredient INGREDIENT1 { driver.ingredient = new Ingredient(); } inName quantity important  INGREDIENT2 {driver.c->addIngredient(driver.ingredient);}
	| ingredient comment INGREDIENT1 { driver.ingredient = new Ingredient(); } inName quantity important  INGREDIENT2 {driver.c->addIngredient(driver.ingredient);}
	| INGREDIENT1 { driver.ingredient = new Ingredient(); } inName quantity important  INGREDIENT2 {driver.c->addIngredient(driver.ingredient);}
	| comment INGREDIENT1 { driver.ingredient = new Ingredient(); } inName quantity important  INGREDIENT2 {driver.c->addIngredient(driver.ingredient);}
	;

inName:
	NAME1 STRING NAME2 { driver.ingredient->setName($2);}
	| comment NAME1 STRING NAME2 { driver.ingredient->setName($3);}
	;
 
quantity:
	QUANTITY1 STRING QUANTITY2 { driver.ingredient->setQuantity($2); }
	| comment QUANTITY1 STRING QUANTITY2 { driver.ingredient->setQuantity($3); }
	;

important:
	comment IMPORTANT1 YES IMPORTANT2 { driver.ingredient->setImportance(true); }
	| IMPORTANT1 YES IMPORTANT2 { driver.ingredient->setImportance(true); }
	| comment IMPORTANT1 NO IMPORTANT2 { driver.ingredient->setImportance(false); }
	| IMPORTANT1 NO IMPORTANT2 { driver.ingredient->setImportance(false); }
	;

comment:
	comment STRING 
	| STRING

%%

void
yy::parserParser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
