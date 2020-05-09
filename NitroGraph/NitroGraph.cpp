// NitroGraph.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CGRAPH.h"

int main()
{
    
	
	CGraph test;
	test.GRAaddSommet(0);
	test.GRAaddSommet(1);
	test.GRAaddSommet(2);
	test.GRAaddSommet(3);
	test.GRAaddArcTo(0, 1);
	test.GRAaddArcTo(0, 2);
	test.GRAaddArcTo(1, 2);
	test.GRAaddArcTo(2, 3);
	test.GRAaddArcTo(3, 0);
	test.GRAremoveArc(0, 2);
	
	

	printf("test");


	return 0;

}

