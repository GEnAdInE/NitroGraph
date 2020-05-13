#pragma once

#include "CSTRING.h"
#include "CVECTOR.h"
#include "CGRAPH.h"



/**
*  @brief  Print the CString to stdout.
*	@example print(myLine);
*/
void PRIprint(const CString &STRsentence) {
	cout << STRsentence.STRbegin() << endl;
}



/**
*  @brief  Print the Vector to stdout.
*	@example print(myVector);
*/
template <class T>
void PRIprint(const CVector<T> &VECvector) {
	unsigned int nIndex = 0;
	for (nIndex; nIndex < VECvector.VECsize(); nIndex++) {
		cout << VECvector.VECgetElement(nIndex) << ' ' << endl;
	}
}



/**
*  @brief  Print the Matrix to stdout.
*	@example print(myMatrix);
*/
void PRIprint(const CGraph &GRAgraph) {
	cout << "NBSommets=" << GRAgraph.GRAgetSommetCount() << endl;
	cout << "NBArcs=" << GRAgraph.GRAgetArcCount() << endl;
	cout << "Sommets=[" << endl;
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAgraph.GRAgetSommetCount(); nGraphIterator++)
	{
		cout << "Numero=" << GRAgraph.GRAgetSommets(nGraphIterator)->SOMgetNumero() << endl;
	}
	cout << "]" << endl;
	cout << "Arcs=[" << endl;
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAgraph.GRAgetSommetCount(); nGraphIterator++)
	{
		for (unsigned int nArcPartantIterator = 0; nArcPartantIterator < GRAgraph.GRAgetSommets(nGraphIterator)->SOMgetSizePartant(); nArcPartantIterator++)
		{
			cout << "Debut=" << GRAgraph.GRAgetSommets(nGraphIterator)->SOMgetNumero() << ", Fin=" << GRAgraph.GRAgetSommets(nGraphIterator)->SOMgetPartant()[nArcPartantIterator]->ARCget() << endl;
		}
		
		
	}
	cout << "]" << endl;
}



