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
	 * Short options are one-letter arguments like 'n' or 'b'.
	 * Long options are many-letters arguments like 'size' or 'bibou'.
	 */
protected :
	std::list <Option> optionList ;
	void fillOptionArgument(std::string opt, std::string arg) ;
	void setOptionGiven(std::string opt, bool b) ;
	std::string executable ;
	std::string exampleLine ;
	std::string emailAdress ;
	std::string srcAdress ;

public:
	Menu() ;
	~Menu() ;
	void Usage() ;
	std::string getOption(std::string opt) ;
	int CommandAnalysis(int argc, char *argv[]) ;
	bool optionSet(std::string opt) ;
	Option getOptionWithShortOption(std::string shOpt) ;
	Option getOptionWithLongOption(std::string longOpt) ;
	void addOption(std::string sh, std::string lg, std::string des) ;
	void setExecutable(std::string exec) ;
	void setExampleLine(std::string ex) ;
	void setEmailAdress(std::string email) ;
	void setSourceCodeAdress(std::string src) ;
};

#endif //MENU_H
