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

#ifndef CFGPARSER_H
#define CFGPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <map>
#include "../Data/Data.h"


class CfgParser
{
	/*
	 * Configuration file Parser.
	 * Read a configuration file in a specific syntax.
	 * Store all data given in Data object.
	 * See getters to use it.
	 */
protected :
	// protected functions
	bool stockFileInMap() ;
	bool readOptionLine(std::string l,Data& dat) ;
	bool readValues(std::string l, Data& dat) ;
	bool fillAllData() ;
	bool optionsAlreadyExists(std::string t, std::string n) ;

	// Attributs
	std::fstream configFile ;
	std::string configFileName ;
	std::list <Data> dataList ;
	std::map <int,std::string> idLine ;
	std::string optionRead ;
	std::string errorMessage ;

public :
	CfgParser(std::string cfgFileName) ;
	CfgParser() ;
	~CfgParser() ;
	void setConfigFileName(std::string fileName) ;
	void readConfigFile() ;
	std::list <Data> getDataListWithType(std::string t) ;
	Data getDataWithTypeAndName(std::string t, std::string n) ;
	void printDataList(std::ostream& flux) ;
};


#endif  // CFGPARSER_H
