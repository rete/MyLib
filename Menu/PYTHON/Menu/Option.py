#!/usr/bin/python

#//SummerDev libraries for python usage
#All Right Reserved.
#
#Use and copying of these libraries and preparation of derivative works
#based upon these libraries are permitted. Any copy of these libraries
#must include this copyright notice.

"""
This module define an Option of the Command line passed to the program via Menu class.

Example usage :

>>> from Menu.Option import Option
>>> opt = Option()
>>> opt.setShortOption("a")
>>> opt.setLongOption("all")
>>> opt.setDescription("Launch the program for all file in the directory")

All these settings can be set otherwise :

>>> opt = Option("a","all","Launch the program for all files in the directory")

Must be used with Menu class.


@author: R. Ete
@email: remi.ete@gmail.com
@copyright: R. Ete
"""

from types import *

class Option(object) :
    """ Option class. Define an option you can pass to your program.
    You can pass a short option like 'a' or a long option like 'all'
    """
    
    def __init__(self ,shortOption = "" ,longOption = "" ,description = "") :
        object.__init__(self)
        self.shortOption = shortOption
        self.longOption = longOption
        self.description = description
        self.optionArg = ""
        self.given = False
        
    def setGiven(self,bool) :
        """ Set the option as given.
        """
        if type(bool) is BooleanType :
            self.given = bool
    
    
    def setOptionArgument(self, arg) :
        """ If the option can have an argument, set the argument of the 
        """
        if type(arg) is StringType :
            optionArg = arg
    
    
    def getShortOption(self) :
        return shortOption
    
    
    def getLongOption(self) :
        return longOption
    
    
    def getOptionArgument(self) :
        return optionArg
    
    
    def getDescription(self) :
        return description
    
    
    def isGiven(self) :
        return given
