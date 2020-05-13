// NitroGraph.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CGRAPH.h"
#include "CPRINTER.h"

int main(unsigned int argc, const char* argv[])
{
	if (argc == 1) {
		cout << "NO INPUT FILE ENTERED ... EXITING" << endl;
		return 1;
	}
	for (unsigned int argvIterator = 1; argvIterator < argc; argvIterator++) {

		const char* pcFiles = argv[argvIterator];
		CParser parser(pcFiles, '\n', '=', false);
		CGraph parsed(parser);
		cout << "GRAPH DE BASE:" << endl << endl;
		PRIprint(parsed);
		CGraph reverseGraph = *parsed.GRAreverseAllArc();
		cout << endl << "GRAPH DE BASE AVEC ARCS INVERSES:" << endl << endl;
		PRIprint(reverseGraph);
	}	
	



	return 0;

}

