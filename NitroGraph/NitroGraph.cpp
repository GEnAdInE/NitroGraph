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
	test.GRAaddArcTo(20, 10);
	for (int i = 0; i < 2; i++)
	{
		std::cout << test.GRAgetSommetById(10)->SOMgetArrivant()[i]->ARCget() << endl;
	}
	test.GRAmodifySommet(0, 1);
	for (int i = 0; i < 2; i++)
	{
		std::cout << test.GRAgetSommetById(10)->SOMgetArrivant()[i]->ARCget() << endl;
	}
	//test.GRAreverseAllArc();
	


	return 0;

}

