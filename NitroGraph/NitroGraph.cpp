// NitroGraph.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CGRAPH.h"

int main()
{
    
	
	CGraph test;
	test.GRAaddSommet(0);
	test.GRAaddSommet(3);
	test.GRAaddSommet(2);
	test.GRAaddArcTo(0, 3);
	test.GRAaddArcTo(0, 2);
	if (test.GRAgetSommetById(0) == test.GRAgetSommetById(1))
	{
		std::cout << "test" << endl;
	}
	test.GRAreverseAllArc();
	


	return 0;

}

