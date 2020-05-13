// NitroGraph.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CGRAPH.h"

int main()
{
    
	
	CGraph test;
	test.GRAaddSommet(0);
	test.GRAaddSommet(10);
	test.GRAaddSommet(20);
	test.GRAaddArcTo(0, 10);
	test.GRAaddArcTo(10, 20);
	test.GRAaddArcTo(20, 0);

	//test.GRAmodifySommet(0, 1);
	
	test.GRAdelSommetById(10);
	
	//test.GRAreverseAllArc();
	


	return 0;

}

