/*
 *
 * CfgParserException.h header template generated by fclass
 * Creation date : Sun May 20 21:27:54 2012
 * Copyright (c) 2012 Rémi Eté
 * All Right Reserved.
 *
 * Use and copying of these libraries and preparation of derivative works
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 *
 * Written by : R. Eté
 */


#ifndef CFGPARSEREXCEPTION_H
#define CFGPARSEREXCEPTION_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <exception>


class CfgParserException : public std::exception
{

protected :

public :
	CfgParserException() throw() ;
	virtual ~CfgParserException() throw() ;
	virtual const char* what() const throw() = 0 ;

};

#endif  // CFGPARSEREXCEPTION_H