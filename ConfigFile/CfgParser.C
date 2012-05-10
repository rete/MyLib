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

using namespace std ;

#include "CfgParser.h"

//////////////////////////////////////////////////////////////////////////
////////////// DON'T TOUCH IF DON'T KNOW WHAT YOU ARE DOING //////////////
//////////////////////////////////////////////////////////////////////////
//
//                     / \  //\
//      |\___/|      /   \//  \\
//      /0  0  \__  /    //  | \ \
//     /     /  \/_/    //   |  \  \
//     @_^_@'/   \/_   //    |   \   \
//     //_^_/     \/_ //     |    \    \
//  ( //) |        \///      |     \     \
//( / /) _|_ /   )  //       |      \     _\
//( // /) '/,_ _ _/  ( ; -.    |    _ _\.-~        .-~~~^-.
//(( / / )) ,-{        _      `-.|.-~-.           .~         `.
//(( // / ))  '/\      /                 ~-. _ .-~      .-~^-.  \
//(( /// ))      `.   {            }                   /      \  \
//(( / ))     .----~-.\        \-'                 .~         \  `. \^-.
//       ///.----..>        \             _ -~             `.  ^-`  ^-_
//         ///-._ _ _ _ _ _ _}^ - - - - ~                     ~-- ,.-~
//                                                            /.-~

CfgParser::CfgParser()
{
	errorMessage = "**************************\n" ;
	errorMessage += "Configuration Parser Message : \n" ;
}

CfgParser::CfgParser(string cfgFileName)
{
	errorMessage = "**************************\n" ;
	errorMessage = "Configuration Parser Message : \n" ;
	configFileName = cfgFileName ;
}

CfgParser::~CfgParser()
{
	// Default Destructor
}

bool CfgParser::readOptionLine(string l, Data& dat)
{
	/*
	 * Called by fillAllDataa() method.
	 * Analyze Option line in configuration file and fill the datum block.
	 */
	string line = l ;
	line = line.substr(1) ;
	istringstream iss(line) ;
	string option = "" ;
	iss >> option ;
	string optionName = "" ;
	string temp ;
	while(!iss.eof())
	{
		iss >> temp ;
		optionName += temp ;
		optionName += " " ;
	}

	if(optionName=="")
	{
		errorMessage += "error : No option name set for '" ;
		errorMessage += option ;
		errorMessage += "' . Option name expected \n" ;
		return true ;
	}
	if(optionName[0]!='"')
	{
		errorMessage += "error : option '" ;
		errorMessage += option ;
		errorMessage += "' must begin with '\"' character \n";
		return true ;
	}
	if(optionName[optionName.size()-3]!='"')
	{
		errorMessage += "error : option '" ;
		errorMessage += option ;
		errorMessage += "' must end with '\"' character \n";
		return true ;
	}
	if(optionName[optionName.size()-2]!=']')
	{
		errorMessage += "error : ']' expected after option '" ;
		errorMessage += option ;
		errorMessage += "' \n";
		return true ;
	}
	optionName = optionName.substr(1,optionName.size()-4) ;
	dat.setType(option) ;
	dat.setName(optionName) ;
	return false ;
}

bool CfgParser::readValues(string l, Data& dat)
{
	/*
	 * Called by fillAllData() method.
	 * Analyze a key / value line and fill the datum block.
	 * Return true if an error had been detected.
	 */
	string line = l ;
	string key ;
	string value ;
	string eg ;
	line = line.substr(1) ;
	istringstream iss(line) ;
	iss >> key ;
	iss >> eg ;
	if(eg != "=")
	{
		errorMessage += "error : no 'equal' sign after key '";
		errorMessage += key ;
		errorMessage += "'. Key must have only one word \n" ;
		return true ;
	}
	string temp ;

	while(!iss.eof())
	{
		iss >> temp ;
		value += temp ;
		value += " " ;
	}
	value = value.substr(0,value.size()-1) ;
	if (value == "")
	{
		errorMessage += "error : no value set for key '";
		errorMessage += key ;
		errorMessage += "'. Value must be set for each key \n" ;
		return true ;
	}
	dat.addKeyWithValue(key,value) ;
	return false ;
}

bool CfgParser::stockFileInMap()
{
	/*
	 * Copy the file in a map.
	 * Key map = number of the line , value map = line contains.
	 * Return true if an error had been detected.
	 */
	const char * configfile = configFileName.c_str() ;
	configFile.open(configfile,ios::in) ;
	bool errorReturnStatut = false ;

	// Check if the file is opened
	if (configFile == NULL)
	{
		errorMessage += "error : configuration file could not be opened! \n" ;
		errorReturnStatut = true ;
		configFile.close() ;
	}
	else
	{
		int i = 1 ;
		bool endLinePresent = false ;
		while(!configFile.eof())
		{
			getline(configFile,idLine[i]) ;
			if(idLine[i]=="#end#") endLinePresent = true ;
			i++ ;
		}
		if(!endLinePresent)
		{
			errorReturnStatut = true ;
			errorMessage += "error : #end# is not present at ned of file. #end# expected \n" ;
		}
		configFile.close() ;
	}
	return errorReturnStatut ;

}

bool CfgParser::fillAllData()
{
	/*
	 * Fill data block contained in the configuration file.
	 * Return true if an error had been detected.
	 */
	string junk ;
	string line ;
	bool optionError =  false ;
	bool valueError =  false ;
	bool errorStatut = false ;
	bool returnErrorStatut = false ;
	for(int i=1 ; idLine[i]!="#end#" ; i++)
	{
		line = idLine[i] ;

		if(line[0]=='[')
		{
			valueError = false ;
			errorStatut = false ;
			Data data ;
			optionError = readOptionLine(line,data) ;
			if(optionError)
			{
				optionError = false ;
				errorStatut = true ;
				returnErrorStatut = true ;
				continue ;
			}
			if(optionsAlreadyExists(data.getType(),data.getName())) break ;
			unsigned int j = i+1 ;
			if(j<idLine.size())
			{
				if(idLine[j][0]=='[' || idLine[j].substr(0,5)=="#end#")
				{
					errorMessage += "warning : data given but no option inside!\n" ;
					errorStatut = true ;
				}
				else
				{
					int compt = 0 ;
					while( (idLine[j][0]!='[') && (idLine[j]!="#end#") )
					{

						if((idLine[j])[0]=='	')
						{
							compt++ ;
							valueError = readValues(idLine[j],data) ;
						}
						if(valueError)
						{
							errorStatut = true ;
							returnErrorStatut = true ;
							break ;
						}
						j++ ;
					}
					if(compt==0) valueError = true ;
				}
			}
			if(!errorStatut) dataList.push_back(data) ;
		}
	}
	return returnErrorStatut ;
}

bool CfgParser::optionsAlreadyExists(string t, string n)
{
	/*
	 * Called by fillAllData() method.
	 * Return true if two Options has the Type and the same Name.
	 */
	if(dataList.size()!=0)
	{
	list<Data>::iterator it ;
	for(it=dataList.begin() ; it!=dataList.end() ; it++)
		if((*it).hasTypeAndName(t,n))
			return true ;
		else return false ;
	}
	else return false ;
}

void CfgParser::setConfigFileName(string fileName)
{
	configFileName = fileName ;
}


void CfgParser::readConfigFile()
{
	/*
	 * Launch the whole reading file.
	 * Call stockFileInMap() and fillAllData() to copy the file and fill all valid data.
	 */
	bool dataError = false ;
	bool fileError = false ;
	if(configFileName != "")
	{
		fileError = stockFileInMap() ;
		if(!fileError) dataError = fillAllData() ;
	}
	errorMessage += "**************************\n" ;
	if (fileError || dataError) cout << errorMessage ;
}

list <Data> CfgParser::getDataListWithType(string t)
{
	/*
	 * Return a list of data which contains the same type.
	 */
	list <Data>::iterator it ;
	list <Data> dataL ;
	for(it=dataList.begin() ; it!=dataList.end() ; it++)
	{
		if((*it).getType()==t)  dataL.push_back(*it) ;
	}
	return dataL ;
}

Data CfgParser::getDataWithTypeAndName(string t, string n)
{
	/*
	 * Return a datum which contains the same type and the same name.
	 */
	list <Data>::iterator it ;
	if(dataList.size() != 0)
		for(it=dataList.begin() ; it!=dataList.end() ; it++)
			if(((*it).getType()==t) && (((*it).getName()==n)) )
				if((*it).getOptionMap().size() != 0) return (*it) ;
	Data emptyDataObject ;
	return emptyDataObject ;
}

void CfgParser::printDataList(ostream& flux)
{
	/*
	 * Print all Data contained in the data list after reading.
	 * Do nothing if the configuration file had not been read.
	 */
	list <Data>::iterator it ;
	if(dataList.size() != 0)
	{
		cout << "**** Data List From Cfg Parser ****" << endl ;
		for(it=dataList.begin() ; it!=dataList.end() ; it++)
			{
			(*it).printData(flux) ;
			cout << endl ;
			}
		cout << "********* End of Data List ********" << endl ;
	}
	else flux << "Warning : Data list is empty! " << endl ;
}
