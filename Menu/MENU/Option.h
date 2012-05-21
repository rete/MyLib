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
	std::string getDescription() ;

	// Setters
	void setOptionArgument(std::string arg) ;
	void setGiven(bool b) ;

	// Other methods
	bool isGiven() ;
	void printUsageLine() ;
};

#endif  // OPTION_H
