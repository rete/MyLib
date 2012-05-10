/*
 *
 * //Ising Model Project part of M1 computing project
 * Copyright (c) 2012 Rémi Eté
 * All Right Reserved.
 *
 * Use and copying of this software and preparation of derivative works
 * based upon this software are permitted. Any copy of this software or
 * of any derivative work must include this paragraph.
 *
 * Written by : R. Eté
 *
 */

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include "Option.h"

class Menu
{
	/*
	 * Menu class.
	 * Manage the command line arguments of the program.
	 * All parameters are stored in Option type object.
	 * Short options are one-letter arguments like 'n' or 'j'.
	 * Long options are many-letters arguments like 'size' or 'bibou'.
	 */
protected :
	std::list <Option> optionList ;
	void fillOptionArgument(std::string opt, std::string arg) ;
	void setOptionGiven(std::string opt, bool b) ;

public:
	Menu() ;
	~Menu() ;
	void Usage() ;
	std::string getOption(std::string opt) ;
	int CommandAnalysis(int argc, char *argv[]) ;
	bool optionSet(std::string opt) ;
	Option getOptionWithShortOption(std::string shOpt) ;
	Option getOptionWithLongOption(std::string longOpt) ;
};

#endif //MENU_H
