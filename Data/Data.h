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

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <map>

class Data
{
	/*
	 * Data class.
	 * Data is identified by its type and its name.
	 * Contains a map of key and value.
	 */
protected :
	// All informations to be stored.
	std::string type ;
	std::string name ;
	std::map <std::string,std::string> option ;
public :
	Data() ;
	Data(std::string t , std::string n) ;
	Data(Data const &data) ;
	~Data() ;

	// Setters.
	void setType(std::string t) ;
	void setName(std::string n) ;

	// Getters.
	std::string getName() ;
	std::string getType() ;
	std::string getValueWithKey(std::string k) ;
	std::map <std::string,std::string> getOptionMap() const ;
	
	// Bool methods return value.
	bool hasKey(std::string k) ;
	bool hasTypeAndName(std::string k, std::string v) ;
	bool isEmpty() ;

	// Other methods.
	void addKeyWithValue(std::string k, std::string v) ;
	void printData(std::ostream& flux) ;
};

const Data operator+ (Data const& data1, Data const& data2) ;


#endif  // DATA_H
