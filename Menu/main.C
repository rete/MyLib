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
#include <cassert>
#include "MENU/menu.h"
#include "MENU/Option.h"
#include "MENU/OptionLayout.h"

using namespace std ;

int main(int argc, char * argv[])
{

	Menu menu ;

	// OptionLayout
	OptionLayout fileLayout("File Options") ;
	fileLayout.addOption("x","execute","Execute the program") ;
	fileLayout.addOption("f","file","Set input file") ;
	fileLayout.addOption("c","configuration","Set configuration file") ;

	OptionLayout analysisLayout("Analysis Options") ;
	analysisLayout.addOption("s","size","Set the size of the system") ;
	analysisLayout.addOption("p","params","Display all analysis params") ;

	// Options
	menu.addLayout(fileLayout) ;
	menu.addLayout(analysisLayout) ;

	// All other things that can be set
	menu.setExecutable("SoftTest") ;
	menu.setExampleLine("'SoftTest -xyz' will start the program") ;
	menu.setEmailAdress("remi.ete@gmail.com") ;
	menu.setSourceCodeAdress("https://github.com/rete/SoftTest") ;

	// Display all
	menu.Usage() ;

	assert(1==0) ;
	return 0 ;
}
