#include "CGRAPH.h"

CGraph::CGraph() {

}
CGraph::CGraph(CParser &PARparser) {

}
CGraph::CGraph(CGraph &GRAgraph) {

}
void CGraph::GRAaddSommet() {
	VECSOMSommetVector.VECpush(new CSommet());
}

void CGraph::GRAaddSommet(CSommet & SOMparam)
{
	VECSOMSommetVector.VECpush(new CSommet(SOMparam));
}

void CGraph::GRAaddSommet(int nNum, CArc ** arrivant, unsigned int uSizeA, CArc ** partant, unsigned int uSizeP)
{
	VECSOMSommetVector.VECpush(new CSommet(nNum, arrivant, uSizeA, partant, uSizeP));
}
void CGraph::GRAdelSommet(int nNum)
{
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		if (VECSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nNum)
		{
			//ajouter Vector::delElement();
		}
	}
}
const CSommet& CGraph::GRAgetSommetById(unsigned int nNum) const
{
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		if (VECSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nNum) return *VECSOMSommetVector.VECgetElement(nGraphIterator);
	}
}
CGraph::~CGraph()
{
}
