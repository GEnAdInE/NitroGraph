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
		bool GRAdelSommetById(unsigned int nId);
		void GRAaddArcTo(unsigned int nFromId , unsigned int nToId);
		void GRAremoveArc(unsigned int nFromId, unsigned int nToId);
		void GRAmodifyArc(unsigned int nFromId , unsigned int nToId, unsigned int nFromNewId, unsigned int nToNewId);
		void GRAreverseArc(unsigned int nFromId, unsigned int nToId);
		CGraph* GRAreverseAllArc();


		//accessors
		CSommet* GRAgetSommetById(unsigned int nNum) const;
		bool GRASommetAlreadyExist(unsigned int nNum) const;//attention risque d'erreur si on verifie pas que le sommet exist 
		bool GRAarcAlreadyExist(unsigned int nFrom, unsigned int nTo) const;
		unsigned int GRAgetSommetCount() const;
		unsigned int GRAgetArcCount() const;
		CSommet* GRAgetSommets(unsigned int nElement) const;

		//destructors
		~CGraph();



	private:
		CVector<CSommet*> VECSOMSommetVector;
		unsigned int nSommetCount;
		unsigned int nArcCount;
};

