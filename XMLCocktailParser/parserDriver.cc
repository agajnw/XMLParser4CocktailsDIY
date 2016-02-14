#include "parserDriver.hh"
#include "parserParser.hh"
#include "Cocktail.h"

parserDriver::parserDriver ()
    : trace_scanning (false), trace_parsing (false)
{
}

parserDriver::~parserDriver ()
{
}

int
parserDriver::parse (const std::string &f, Cocktail* ck)
{
    file = f;
    c = ck;
    scan_begin ();
    yy::parserParser parser (*this);
    parser.set_debug_level (trace_parsing);
    int res = parser.parse ();
    scan_end ();
    return res;
}

void
parserDriver::error (const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void
parserDriver::error (const std::string& m)
{
    std::cerr << m << std::endl;
}
