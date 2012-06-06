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

#ifndef OPTIONLAYOUT_H
#define OPTIONLAYOUT_H

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include "Option.h"

class OptionLayout
{
protected :
	std::list<Option> optionList ;
	std::string title ;
	int getMaximumOptionLength() ;

public :
	OptionLayout(std::string t) ;
	~OptionLayout() ;
	void addOption(Option opt) ;
	void addOption(std::string sh, std::string lg, std::string des) ;
	void printOptions() ;
	int listSize() ;
	std::string intToStrBlank(int i) ;
};

#endif  // OPTIONLAYOUT_H
