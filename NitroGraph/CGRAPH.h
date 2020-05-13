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
		void GRAmodifySommet(unsigned int nCurrentNum,unsigned int nNewNum);// a finir
		void GRAdelSommet(unsigned int nNum);// a finir
		void GRAaddArcTo(unsigned int nFromId , unsigned int nToId);
		void GRAremoveArc(unsigned int nFromId, unsigned int nToId);
		void GRAmodifyArc(unsigned int nFromId , unsigned int nToId, unsigned int nFromNewId, unsigned int nToNewId);
		void GRAreverseAllArc();


		//accessors
		CSommet* GRAgetSommetById(unsigned int nNum) const;
		bool GRASommetAlreadyExist(unsigned int nNum);//attention risque d'erreur si on verifie pas que le sommet exist 
		bool GRAarcAlreadyExist(unsigned int nFrom, unsigned int nTo);
		unsigned int GRAgetSommetNb();
		CSommet* GRAgetSommets(unsigned int nElement);

		//destructors
		~CGraph();



	private:
		CVector<CSommet*> VECSOMSommetVector;
		unsigned int nSommetCount;

};

