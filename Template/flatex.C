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
#include <ctime>
#include <fstream>

using namespace std ;


int main(int argc, char* argv[])
{
	if(argc==2)
	{

		time_t rawtime ;
		struct tm * timeinfo ;
		time ( &rawtime ) ;
		timeinfo = localtime ( &rawtime ) ;
		fstream latexfile(argv[1],ios::out) ;


		latexfile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl ;
		latexfile << "%%%%% Latex file template generated by flatex" << endl ;
		latexfile << "%%%%% Creation date : " << asctime (timeinfo) ;
		latexfile << "%%%%% CopyRight R. Eté" << endl ;
		latexfile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl ;
		latexfile << "" << endl ;
		latexfile << "" << endl ;
		latexfile << "\\documentclass[a4paper,12pt]{article}" << endl ;
		latexfile << "\\usepackage[francais]{babel}" << endl ;
		latexfile << "%\\usepackage[latin1]{inputenc}" << endl ;
		latexfile << "\\usepackage[T1]{fontenc}" << endl ;
		latexfile << "\\usepackage{textcomp}" << endl ;
		latexfile << "\\usepackage[utf8]{inputenc}" << endl ;
		latexfile << "\\usepackage[T1]{fontenc}" << endl ;
		latexfile << "\\usepackage{picins}" << endl ;
		latexfile << "\\usepackage{wrapfig}" << endl ;
		latexfile << "\\usepackage[pdftex]{graphicx}" << endl ;
		latexfile << "\\usepackage{graphicx}" << endl ;
		latexfile << "\\usepackage[section]{placeins}" << endl ;
		latexfile << "\\usepackage{lscape}" << endl ;
		latexfile << "\\usepackage{float} " << endl ;
		latexfile << "\\usepackage{amssymb}" << endl ;
		latexfile << "\\usepackage[nottoc, notlof, notlot]{tocbibind}" << endl ;
		latexfile << "\\usepackage{fancyhdr}" << endl ;
		latexfile << "\\author{\\begin{flushleft}Eté Rémi\\end{flushleft}}" << endl ;
		latexfile << "\\date\\today" << endl ;
		latexfile << "" << endl ;
		latexfile << "" << endl ;
		latexfile << "\\voffset -0.95in" << endl ;
		latexfile << "\\textheight 24cm" << endl ;
		latexfile << "" << endl ;
		latexfile << "%\\setlength{\\marginparwidth}{0cm}" << endl ;
		latexfile << "%\\setlength{\\marginparsep}{0cm}" << endl ;
		latexfile << "%\\setlength{\\oddsidemargin}{-0.25cm}" << endl ;
		latexfile << "%\\setlength{\\evensidemargin}{-0.5cm}" << endl ;
		latexfile << "\\setlength{\\textwidth}{14cm}" << endl ;
		latexfile << "" << endl ;
		latexfile << "" << endl ;
		latexfile << "\\pagestyle{fancy}" << endl ;
		latexfile << "\\begin{document}" << endl ;
		latexfile << "" << endl ;
		latexfile << "" << endl ;
		latexfile << "" << endl ;
		latexfile << "\\newpage" << endl ;
		latexfile << "\\tableofcontents" << endl ;
		latexfile << "\\newpage" << endl ;
		latexfile << "" << endl ;
		latexfile << "" << endl ;
		latexfile << "" << endl ;
		latexfile << "\\end{document}" << endl ;
		latexfile << "" << endl ;

		latexfile.close() ;
	}

	return 0 ;
}
