#!/usr/bin/python

#//SummerDev libraries for python usage
#All Right Reserved.
#
#Use and copying of these libraries and preparation of derivative works
#based upon these libraries are permitted. Any copy of these libraries
#must include this copyright notice.

"""
This module define a layout for Options within the menu.

Exemple usage:

>>> from Menu.OptionLayout import OptionLayout
>>> optLayout = OptionLayout("File Options")
>>> optLayout.addOption("r","recursive","Execute the command in recursive mode")

You can also add an option by instanciate it :

>>> opt = Option("a","all","Execute the command for all files")
>>> optLayout.addOption(opt)

or simply :

>>> optLayout.addOption( Option("s","size","Set the size of the square lattice") )

To see what you have append to your layout :

>>> optLayout.printOptions()

This method is used in Usage() method of Menu class

@author: R. Ete
@email: remi.ete@gmail.com
@copyright: R. Ete
"""

from Menu.Option import Option

class OptionLayout (object) :
    """ OptionLayout Class, a layout for option object
    Positions a list of options with a 'title' in the menu
    """
    def __init__(self,title) :
         object.__init__(self)
         self.optionList = []
         self.title = str(title)
         
         
    def _getMaximumOptionLength(self) :
        """ Return the maximum string length among all options.
        Used to format the option display in printOptions() method
        """
        lMax = 0
        for item in self.optionList :
            if item.getLongOption().size() > lMax :
                 lMax = item.getLongOption().size()
        return lMax
    
    
    def intToStrBlank(self, i) :
        """ Return a string with i space
        Ex : if i = 4 the method return "    "
        """
        str = ""
        for j in range(i) :
            str += " "
        return str


    def listSize(self) :
        """ Return the list length.
        """
        return len(optionList)


    def addOption(self,opt) :
        """ Append an option to the layout.
        """
        optionList.append(opt)
    
    
    def addOption(self , sh , lg , des ) :
        """ Append an new option with by instantiation
        """
        newOption = Option(sh,lg,des)
        optionList.append(newOption)
        
        
    def printOptions(self) :
        """ Print all options with a format
        """
        print self.title + " :"
        lMax = getMaximumOptionLength()
        for item in self.optionList :
            space = intToStrBlank(lMax - len(item.getLongOption()) + 2)
            print " -" \
            + item.getShortOption() \
            + " ,  --" \
            + item.getLongOption() \
            + space + item.getDescription() \
            + "\n"

