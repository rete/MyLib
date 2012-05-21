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

#include "OptionLayout.h"

using namespace std ;

OptionLayout::OptionLayout(string t)
{
	title = t ;
}

OptionLayout::~OptionLayout()
{
	// Default Destructor
}

int OptionLayout::listSize()
{
	return optionList.size() ;
}

void OptionLayout::addOption(Option opt)
{
	optionList.push_back(opt) ;
}


void OptionLayout::addOption(string sh, string lg, string des)
{
	Option newOption(sh,lg,des) ;
	optionList.push_back(newOption) ;
}

void OptionLayout::printOptions()
{
	cout << title << " :" << endl ;
	list<Option>::iterator it ;
	int lMax = getMaximumOptionLength() ;
	for(it=optionList.begin() ; it!=optionList.end() ; it++)
	{
		string space = intToStrBlank(lMax - (*it).getLongOption().size() + 2) ;
		cout << "  -" << (*it).getShortOption() << " ,  --" << (*it).getLongOption()
				<< space << (*it).getDescription() << endl ;
	}
}

int OptionLayout::getMaximumOptionLength()
{
	unsigned int lMax = 0 ;
	list<Option>::iterator it ;
	for(it=optionList.begin() ; it!=optionList.end() ; it++)
	{
		if((*it).getLongOption().size()>lMax) lMax = (*it).getLongOption().size() ;
	}
	return lMax ;
}

string OptionLayout::intToStrBlank(int i)
{
	string str = "" ;
	for(int j=1 ; j<=i ; j++) str.push_back(' ') ;
	return str ;
}
