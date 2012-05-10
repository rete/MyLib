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

#include "menu.h"

using namespace std ;


Menu::Menu()
{
	/*
	 * Set all attributes to empty.
	 */
	executable = "" ;
	exampleLine = "" ;
	emailAdress = "" ;
	srcAdress = "" ;
}

Menu::~Menu()
{
	/*
	 * Default destructor
	 */
}

void Menu::addOption(string sh, string lg, string des)
{
	Option newOption(sh, lg, des) ;
	optionList.push_back(newOption) ;
}

Option Menu::getOptionWithShortOption(std::string shOpt)
{
	/*
	 * Return an Option object with a given short option.
	 * Example of short option : "n" , "a" , etc...
	 */
	list<Option>::iterator it ;
	for(it = optionList.begin() ; it!= optionList.end() ; it++)
		if((*it).getShortOption()==shOpt) return *it ;
	Option opt ;
	return opt ;
}

Option Menu::getOptionWithLongOption(std::string longOpt)
{
	/*
	 * Return an Option object with a given long option.
	 * Example of long option : "size" , "height" , etc...
	 */
	list<Option>::iterator it ;
	for(it = optionList.begin() ; it!= optionList.end() ; it++)
		if((*it).getLongOption()==longOpt) return *it ;
	Option opt ;
	return opt ;
}

void Menu::Usage()
{
	/*
	 * Display command usage
	 */

	list<Option>::iterator it ;
	if(executable!="") cout << "Usage: " << executable << " <OPTION>" << endl ;
	if(exampleLine!="") cout << "Example : " << exampleLine << endl ;
	cout << "Options :" << endl ;
	for(it = optionList.begin() ; it != optionList.end() ; it++)
		(*it).printUsageLine() ;
	if(emailAdress!="") cout << "Report bug to " << emailAdress << endl ;
	if(srcAdress!="") cout << "Source code can be downloaded on : <"<<srcAdress<<">" <<endl ;

}

void Menu::setExecutable(std::string exec)
{
	executable = exec ;
}

void Menu::setExampleLine(std::string ex)
{
	exampleLine = ex ;
}

void Menu::setEmailAdress(std::string email)
{
	emailAdress = email ;
}

void Menu::setSourceCodeAdress(std::string src)
{
	srcAdress = src ;
}

int Menu::CommandAnalysis(int argc, char * argv[])
{
	/*
	 * Analyze the command line.
	 * Fill all Option objects with respect to argv[].
	 * Return 0 if everthing is OK else return value is 1.
	 */
	char c ;
	for (int i=1 ; i<argc ; i++)
	{
		char * cmd = argv[i] ;
		if (*cmd == '-')  // It's an option
		{
			cmd++ ;
			if (*cmd == '-')  // It's a word option
			{
				cmd++ ;
				string word = "" ;
				while ( ((c=*cmd++)!=0) )
				{
					if(c=='=') break ;
					word.push_back(c) ;
				}
				if (word == "help")
				{
					Usage() ;
					return 0 ;
				}
				else if (word == "graphic") setOptionGiven("graphic",true) ;
				else if (word == "display") setOptionGiven("display",true) ;
				else if (word == "execute") setOptionGiven("execute",true) ;
				else if (word == "config")
				{
					string arg ;
					while ( ((c=*cmd++)!=0) )
					{
						arg.push_back(c) ;
					}
					fillOptionArgument("f",arg) ;
					setOptionGiven("execute",true) ;
				}
				else
				{
					cout << "Error : argument passed \'" << word << "\' to command line does not exists!" << endl ;
					return 1 ;
				}
			}
			else
			{
				while ((c=*cmd++)!=0)	//else it's a character option
				{
					switch (c)
					{
					case 'g' :
						setOptionGiven("g",true) ;
						break ;
					case 'x' :
						setOptionGiven("x",true) ;
						break ;
					case 'h' :
						Usage() ;
						return 0 ;
					case 'd' :
						setOptionGiven("d",true) ;
						break ;
					case 'f' :
						setOptionGiven("f",true) ;
						fillOptionArgument("f",string(argv[i+1])) ;
						break ;
					default :
						cout << "Error : argument passed \'" << c << "\' to command line does not exists!" << endl ;
						return 1 ;
					} // switch
				} // while
			} // else
		} // if for option
	} // for

	return 0 ;
}

void Menu::fillOptionArgument(string opt, string arg)
{
	/*
	 * Fill the argument of an option.
	 * ex : ./exec -n 2
	 * -> the argument of short option will be 2.
	 */
	list<Option>::iterator it ;
	for(it = optionList.begin() ; it!= optionList.end() ; it++)
	{
		if((*it).getShortOption()==opt) (*it).setOptionArgument(arg) ;
		if((*it).getLongOption()==opt) (*it).setOptionArgument(arg) ;
	}
}

bool Menu::optionSet(string opt)
{
	/*
	 * Return true if the option opt (short or long) has been given.
	 * Else return false.
	 */
	if(getOptionWithLongOption(opt).isGiven()) return true ;
	else if(getOptionWithShortOption(opt).isGiven()) return true ;
	else return false ;

}

void Menu::setOptionGiven(string opt, bool b)
{
	/*
	 * Called by CommandAnalysis() method.
	 * Set the option as 'given'.
	 * ex : ./exec -n
	 * -> 'n' option will be set as 'given'
	 */
	list<Option>::iterator it ;
	for(it = optionList.begin() ; it!= optionList.end() ; it++)
	{
		if((*it).getShortOption()==opt) (*it).setGiven(b) ;
		if((*it).getLongOption()==opt) (*it).setGiven(b) ;
	}
}
