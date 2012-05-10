/*
 *
 * //My libraries for C++ usage
 * Copyright (c) 2012 Rémi Eté
 * All Right Reserved.
 *
 * Use and copying of these libraries and preparation of derivative works
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 *
 * Written by : R. Eté
 */

#include "Option.h"

using namespace std ;

Option::Option()
{
	/*
	 * Build an option of the command line with empty informations.
	 */
	shortOption = "" ;
	longOption = "" ;
	description = "" ;
	given = false ;
}

Option::Option(string shOpt, string longOpt, string des)
{
	/*
	 * Build an option of the command line with given arguments.
	 * shOpt : short option format.
	 * ex : 's'
	 * longOpt : long option format.
	 * ex : 'size'
	 * des : a short description of the option.
	 * ex : 'size of the given house'
	 */
	if(shOpt.length() == 1) shortOption = shOpt ;
	longOption = longOpt ;
	description = des ;
	given = false ;
}

Option::~Option()
{
	// Default destructor
}

Option::Option(Option const &opt)
{
	/*
	 * Copy constructor
	 */
	shortOption = opt.shortOption ;
	longOption = opt.longOption ;
	description = opt.description ;
	optionArg = opt.optionArg ;
	given = opt.given ;
}

/*
 * All setters
 */
void Option::setGiven(bool b)
{
	given = b ;
}

void Option::setOptionArgument(string arg)
{
	optionArg = arg ;
}

/*
 * All getters
 */
std::string Option::getShortOption()
{
	return shortOption ;
}

std::string Option::getLongOption()
{
	return longOption ;
}

string Option::getOptionArgument()
{
	return optionArg ;
}

/*
 * Other methods
 */
bool Option::isGiven()
{
	if(given) return true ;
	return false ;
}

void Option::printUsageLine()
{
	cout << description << endl ;
}
