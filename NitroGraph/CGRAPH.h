#pragma once

#include "CARC.h"
#include "CSOMMET.h"
#include "CPARSER.h"
#include "CVECTOR.h"

class CGraph
{

	public :

		//constructors
		CGraph();
		CGraph(CParser &PARparser);
		CGraph(CGraph &GRAgraph);

		//mutators
		void GRAaddSommet();
		void GRAaddSommet(CSommet &SOMparam);
		void GRAaddSommet(int nNum, CArc ** arrivant, unsigned int uSizeA, CArc ** partant, unsigned int uSizeP);
		void GRAdelSommet(int nNum);

		//accessors
		const CSommet& GRAgetSommetById(unsigned int nNum) const;

		//destructors
		~CGraph();



	private:
		CVector<CSommet*> VECSOMSommetVector;
		unsigned int GRAnSommetCount;

};

