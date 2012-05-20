#!/bin/bash
######################################################
# Compute the number of lines contained in           #
# .C and .h extension of the project                 #
# //Ising Model Project part of M1 computing project #
# Copyright (c) 2012 Rémi Eté                        #
# All Right Reserved.                                #
######################################################

nblines=0
tmp=0
for f in $(find . -type f -iname '*.[Ch]')
do
	(( tmp = $(wc -l $f | cut -f 1,1 -d ' ') ))
	(( nblines = nblines + tmp ))
done

echo 'Nombre de lignes du projet : ' $nblines

#end#