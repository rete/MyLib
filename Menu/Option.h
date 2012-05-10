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

#ifndef OPTION_H
#define OPTION_H

#include <iostream>
#include <string>

class Option
{
	/*
	 * Option class.
	 * Represent an option of the command line.
	 */
protected :
	std::string shortOption ;
	std::string longOption ;
	std::string description ;
	std::string usageLine ;
	std::string optionArg ;
	bool given ;

public :
	Option() ;
	Option(std::string shOpt, std::string longOpt,std::string des) ;
	~Option() ;
	Option(Option const &opt) ;

	// Getters
	std::string getShortOption() ;
	std::string getLongOption() ;
	std::string getOptionArgument() ;

	// Setters
	void setUsageLine(std::string usage) ;
	void setOptionArgument(std::string arg) ;
	void setGiven(bool b) ;

	// Other methods
	bool isGiven() ;
	void printUsageLine() ;
};

#endif  // OPTION_H
