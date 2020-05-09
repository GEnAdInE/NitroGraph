#include "CGRAPH.h"

CGraph::CGraph() 
{
	GRAnSommetCount = 0;
}
CGraph::CGraph(CParser &PARparser) 
{

}
CGraph::CGraph(CGraph &GRAgraph) 
{

}
void CGraph::GRAaddSommet(unsigned int nNum) 
{
	VECSOMSommetVector.VECpush(new CSommet(nNum));
	GRAnSommetCount++;
}

void CGraph::GRAaddSommet(CSommet & SOMparam)
{
	VECSOMSommetVector.VECpush(new CSommet(SOMparam));
	GRAnSommetCount++;
}

void CGraph::GRAaddSommet(unsigned int nNum, CArc ** arrivant, unsigned int uSizeA, CArc ** partant, unsigned int uSizeP)
{
	VECSOMSommetVector.VECpush(new CSommet(nNum, arrivant, uSizeA, partant, uSizeP));
	GRAnSommetCount++;
}
void CGraph::GRAmodifySommet(unsigned int nCurrentNum , unsigned int nNewNum)
{
	GRAgetSommetById(nCurrentNum).SOMsetNumero(nNewNum);
	//changer les numeros des arcs lié a ce sommet
}
void CGraph::GRAdelSommet(unsigned int nNum)
{
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		if (VECSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nNum)
		{
			//ajouter Vector::delElement();
			GRAnSommetCount--;
			//prendre inspi du destrcteur 
			//bien detruire tout les arcs (partant et arrivant)
		}
	}
}

//ARC related function
void CGraph::GRAaddArcTo(unsigned int nFromId,unsigned int nToId)
{
	CSommet *pSOMfrom = &GRAgetSommetById(nFromId);
	CSommet *pSOMdest = &GRAgetSommetById(nToId);

	if (pSOMfrom->SOMgetPartant() == NULL)
	{
		pSOMfrom->SOMsetPartant((CArc**)malloc(sizeof(CArc*)));
		pSOMfrom->SOMgetPartant()[0] = new CArc(nToId); //
	}
	else
	{
		pSOMfrom->SOMsetPartant((CArc**)realloc(pSOMfrom->SOMgetPartant(), sizeof(CArc)*(pSOMfrom->SOMgetSizePartant() + 1)));
		pSOMfrom->SOMgetPartant()[pSOMfrom->SOMgetSizePartant()] = new CArc(nToId); //
	}
	pSOMfrom->SOMsetSizePartant(pSOMfrom->SOMgetSizePartant()+1);
	if (pSOMdest->SOMgetArrivant() == NULL)
	{
		pSOMdest->SOMsetArrivant((CArc**)malloc(sizeof(CArc*)));
		pSOMdest->SOMgetArrivant()[0] = new CArc(nFromId);
	}
	else
	{
		pSOMdest->SOMsetArrivant((CArc**)realloc(pSOMdest->SOMgetArrivant(), sizeof(CArc)*(pSOMdest->SOMgetSizeArrivant() + 1)));
		pSOMdest->SOMgetArrivant()[pSOMdest->SOMgetSizeArrivant()] = new CArc(nFromId);//
	}
	pSOMdest->SOMsetSizeArrivant(pSOMdest->SOMgetSizeArrivant()+1);
}

void CGraph::GRAremoveArc(unsigned int nFromId, unsigned int nToId)
{
	CSommet *pSOMfrom = &GRAgetSommetById(nFromId);
	CSommet *pSOMdest = &GRAgetSommetById(nToId);

	for (unsigned int nIterator = 0; nIterator < pSOMfrom->SOMgetSizePartant();nIterator++)
	{
		if (pSOMfrom->SOMgetPartant()[nIterator]->ARCget() == nToId)
		{
			delete pSOMfrom->SOMgetPartant()[nIterator];

			for (unsigned int nIteratorNewTab = nIterator; nIteratorNewTab < pSOMfrom->SOMgetSizePartant() - 1; nIteratorNewTab++)
			{
				pSOMfrom->SOMgetPartant()[nIterator] = pSOMfrom->SOMgetPartant()[nIterator + 1];
				
			}
			pSOMfrom->SOMsetSizePartant(pSOMfrom->SOMgetSizePartant() - 1);

		}
	}
	for (unsigned int nIterator = 0; nIterator < pSOMdest->SOMgetSizeArrivant(); nIterator++)
	{
		if (pSOMdest->SOMgetArrivant()[nIterator]->ARCget() == nFromId)
		{
			delete pSOMdest->SOMgetArrivant()[nIterator];
			
			for (unsigned int nIteratorNewTab = nIterator; nIteratorNewTab < pSOMdest->SOMgetSizeArrivant() - 1; nIteratorNewTab++)
			{

				pSOMdest->SOMgetArrivant()[nIterator] = pSOMdest->SOMgetArrivant()[nIterator + 1];
				
			}
			pSOMdest->SOMsetSizeArrivant(pSOMdest->SOMgetSizeArrivant() - 1);
		}
	}

}

void CGraph::modifyArc(unsigned int nFromId, unsigned int nToId, unsigned int nFromNewId, unsigned int nToNewId)
{
	GRAremoveArc(nFromId, nToId);
	GRAaddArcTo(nFromNewId, nToNewId);
}

//Getter of sommet 
CSommet& CGraph::GRAgetSommetById(unsigned int nNum) const {
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		if (VECSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nNum) return *VECSOMSommetVector.VECgetElement(nGraphIterator);
	}
	//faire un truc pour le warning ici
	
}

//Destructor
CGraph::~CGraph()
{

	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		CSommet *current = VECSOMSommetVector.VECgetElement(nGraphIterator);
		for (unsigned int nSommetIterator = 0; nSommetIterator < current->SOMgetSizePartant(); nSommetIterator++)
		{
			unsigned int dest = current->SOMgetPartant()[nSommetIterator]->ARCget();
			unsigned int from = current->SOMgetNumero();
			GRAremoveArc(from, dest);
		}
	}
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		delete VECSOMSommetVector.VECgetElement(nGraphIterator);
	}

}
