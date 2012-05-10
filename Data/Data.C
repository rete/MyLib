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


#include "Data.h"

using namespace std ;

Data::Data()
{
	//default constructor
}

Data::Data(string t , string n)
{
	type = t ;
	name = n ;
}

Data::Data(Data const &data)
{
	/*
	 * Copy constructor
	 */
	type = data.type ;
	name = data.name ;
	option = data.option ;
}

Data::~Data()
{
	// default destructor
}

void Data::setType(string t)
{
	type = t ;
}

void Data::setName(string n)
{
	name = n ;
}

void Data::addKeyWithValue(string k, string v)
{
	/*
	 * Add a key in the datum block with key k and value v.
	 */
	option[k] = v ;
}

string Data::getType()
{
	return type ;
}

string Data::getName()
{
	return name ;
}

map <string,string> Data::getOptionMap() const
{
	return option ;
}


bool Data::hasTypeAndName(string t, string n)
{
	/*
	 * Return true if the type and name are same as given.
	 */
	if(type==t && name==n) return true ;
	else return false ;
}

bool Data::hasKey(string k)
{
	/*
	 * Return true if the datum block has a key k.
	 */
	map <string,string>::iterator it ;
	for (it=option.begin() ; it!=option.end() ; it++)
		if(it->first==k) return true ;
	return false ;
}

string Data::getValueWithKey(string k)
{
	/*
	 * Return the value which has the key k.
	 */
	map <string,string>::iterator it ;
	for (it=option.begin() ; it!=option.end() ; it++)
		if(it->first==k) return it->second ;
	return "" ;
}

bool Data::isEmpty()
{
	/*
	 * Return true if the datum block is empty.
	 */
	if((type=="") && (name=="") && (option.size()==0)) return true ;
	else return false ;
}

void Data::printData(ostream& flux)
{
	/*
	 * List all parameters of the datum block in the flux.
	 * Flux can be cout or anything which inherit from ostream.
	 */
	if(isEmpty()) flux << "Data is empty" << endl ;
	else
	{
		flux << "Option type : " << type << endl ;
		flux << "Option name : " << name << endl ;
		map <string,string>::iterator it ;
		if(option.size() != 0)
			for(it=option.begin() ; it!=option.end() ; it++)
				flux << "key : '" << (*it).first << "' with value : '" << (*it).second << "'" << endl ;
	}
}

const Data operator+ (Data const& data1, Data const& data2)
{
	/*
	 * Define the operation '+' for datum block.
	 * Return datum block without type and name.
	 * This block has keys and values of both data.
	 */
	Data returnData ;
	map <string,string> map1 = data1.getOptionMap() ;
	map <string,string> map2 = data2.getOptionMap() ;
	map <string,string>::iterator it1 ;
		for (it1=map1.begin() ; it1!=map1.end() ; it1++)
			returnData.addKeyWithValue((*it1).first,(*it1).second) ;
	map <string,string>::iterator it2 ;
		for (it2=map2.begin() ; it2!=map2.end() ; it2++)
			returnData.addKeyWithValue((*it2).first,(*it2).second) ;
	return returnData ;
}
