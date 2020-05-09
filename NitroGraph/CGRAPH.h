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
		void GRAaddSommet(unsigned int nNum);
		void GRAaddSommet(CSommet &SOMparam);
		void GRAaddSommet(unsigned int nNum, CArc ** arrivant, unsigned int uSizeA, CArc ** partant, unsigned int uSizeP);
		void GRAmodifySommet(unsigned int nCurrentNum,unsigned int nNewNum);
		void GRAdelSommet(unsigned int nNum);
		void GRAaddArcTo(unsigned int nFromId , unsigned int nToId);
		void GRAremoveArc(unsigned int nFromId, unsigned int nToId);
		void modifyArc(unsigned int nFromId , unsigned int nToId, unsigned int nFromNewId, unsigned int nToNewId);



		//accessors
		CSommet& GRAgetSommetById(unsigned int nNum) const;// no const bc couldn't create pointer to edit incoming and outgoing arc

		//destructors
		~CGraph();



	private:
		CVector<CSommet*> VECSOMSommetVector;
		unsigned int GRAnSommetCount;

};

