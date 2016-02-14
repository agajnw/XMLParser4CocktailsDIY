%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>
# include "parserDriver.hh"
# include "parserParser.hh"
using namespace std;

//work around an incompatibility in flex
# undef yywrap
# define yywrap() 1

// define yyterminate as this instead of NULL
#define yyterminate() return( yy::parserParser::make_END(loc) )

// location of the current token
static yy::location loc;
%}

%option noyywrap nounput batch debug noinput


%{
  // code run each time a pattern is matched
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{
  // code run each time yylex is called
  loc.step ();
%}

[\n]+      			loc.lines (yyleng); loc.step ();
[\t]          			loc.step ();
"yes"				{ return yy::parserParser::make_YES(loc); }
"no"				{ return yy::parserParser::make_NO(loc); }
"<image>"			{ return yy::parserParser::make_IMAGE1(loc); }
"</image>"			{ return yy::parserParser::make_IMAGE2(loc); }
"<base>"			{ return yy::parserParser::make_BASE1(loc); }
"</base>"			{ return yy::parserParser::make_BASE2(loc); }
"<optional>"			{ return yy::parserParser::make_OPTIONAL1(loc); }
"</optional>"			{ return yy::parserParser::make_OPTIONAL2(loc); }
"<recipe>"			{ return yy::parserParser::make_RECIPE1(loc); } 
"</recipe>"			{ return yy::parserParser::make_RECIPE2(loc); }
"<name>"			{ return yy::parserParser::make_NAME1(loc); }
"</name>"			{ return yy::parserParser::make_NAME2(loc); }
"<quantity>"			{ return yy::parserParser::make_QUANTITY1(loc); }
"</quantity>"			{ return yy::parserParser::make_QUANTITY2(loc); }
"<important>"			{ return yy::parserParser::make_IMPORTANT1(loc); }
"/important>"			{ return yy::parserParser::make_IMPORTANT2(loc); }
"<ingredient>"			{ return yy::parserParser::make_INGREDIENT1(loc);	 }
"/ingredient>"			{ return yy::parserParser::make_INGREDIENT2(loc); }
"<ingredients>"			{ return yy::parserParser::make_INGREDIENTS1(loc); }
"</ingredients>"		{ return yy::parserParser::make_INGREDIENTS2(loc); }
"<cocktail>"			{ return yy::parserParser::make_COCKTAIL1(loc);}
"</cocktail>"			{ return yy::parserParser::make_COCKTAIL2(loc); }

[a-zA-Z0-9\ \.\,\?\!\\/\\\-\+\_\@\#\$\%\^\&\:\;\(\)\[\{\]\}\|\=\*\"\']+    { 
						return yy::parserParser::make_STRING(yytext, loc);}
.                				;
%%

void
parserDriver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      error ("cannot open " + file + ": " + strerror(errno));
      exit (EXIT_FAILURE);
    }
}



void
parserDriver::scan_end ()
{
  fclose (yyin);
}

