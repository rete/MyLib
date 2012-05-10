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

#include <iostream>
#include <string>
#include "menu.h"
#include "Option.h"
#include "OptionLayout.h"

using namespace std ;

int main(int argc, char * argv[])
{

	Menu menu ;
	menu.addOption("x","execute","Execute the program") ;
	menu.setExecutable("SoftTest") ;
	menu.setExampleLine("'SoftTest -xyz' will start the program") ;
	menu.setEmailAdress("remi.ete@gmail.com") ;
	menu.setSourceCodeAdress("https://github.com/rete/SoftTest") ;
	menu.Usage() ;

	return 0 ;
}
