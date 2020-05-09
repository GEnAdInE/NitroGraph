#include "CGRAPH.h"

CGraph::CGraph() {

}
CGraph::CGraph(CParser &PARparser) {

}
CGraph::CGraph(CGraph &GRAgraph) {

}
void CGraph::GRAaddSommet(unsigned int nNum) {
	VECSOMSommetVector.VECpush(new CSommet(nNum));
	GRAnSommetCount++;
}

void CGraph::GRAaddSommet(CSommet & SOMparam)
{
	VECSOMSommetVector.VECpush(new CSommet(SOMparam));
	GRAnSommetCount++;
}

void CGraph::GRAaddSommet(int nNum, CArc ** arrivant, unsigned int uSizeA, CArc ** partant, unsigned int uSizeP)
{
	VECSOMSommetVector.VECpush(new CSommet(nNum, arrivant, uSizeA, partant, uSizeP));
	GRAnSommetCount++;
}
void CGraph::GRAdelSommet(int nNum)
{
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		if (VECSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nNum)
		{
			//ajouter Vector::delElement();
			GRAnSommetCount--;
		}
	}
}


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


CSommet& CGraph::GRAgetSommetById(unsigned int nNum) const {
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		if (VECSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nNum) return *VECSOMSommetVector.VECgetElement(nGraphIterator);
	}
	
}
CGraph::~CGraph()
{
}
