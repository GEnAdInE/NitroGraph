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
		void GRAaddSommet(int nNum, CArc ** arrivant, unsigned int uSizeA, CArc ** partant, unsigned int uSizeP);
		void GRAdelSommet(int nNum);
		void GRAaddArcTo(unsigned int nFromId , unsigned int nToId);
		void GRAremoveArc(unsigned int nIdFrom, unsigned int nIdTo);
		void modifyArc(/*what do put here */);


		//accessors
		CSommet& GRAgetSommetById(unsigned int nNum) const;// no const bc couldn't create pointer to edit incoming and outgoing arc
		bool GRAarcAlreadyExist;// ?

		//destructors
		~CGraph();//NEED TO BE DONE ASAP



	private:
		CVector<CSommet*> VECSOMSommetVector;
		unsigned int GRAnSommetCount;

};

