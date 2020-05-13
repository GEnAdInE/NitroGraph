#include "CGRAPH.h"

CGraph::CGraph() 
{
	nSommetCount = 0;
	nArcCount = 0;
}
CGraph::CGraph(CParser &PARparser) 
{
	CString STRnbSommets = PARparser.PARgetValueOfKey("NBSommets");
	CString STRnbArcs = PARparser.PARgetValueOfKey("NBArcs");
	CString STRsommetsArray = PARparser.PARgetValueOfKey("Sommets");
	CString STRarcsArray = PARparser.PARgetValueOfKey("Arcs");

	CVector<CString*> VECpSTRsommetsVector = PARparser.PARparseArray(STRsommetsArray, '\n');
	CVector<CString*> VECpSTRarcsVector = PARparser.PARparseArray(STRarcsArray, '\n');

	nSommetCount = STRnbSommets.STRtoInt();
	nArcCount = STRnbArcs.STRtoInt();

	for (unsigned int nSomIterator = 0; nSomIterator < nSommetCount; nSomIterator++)
	{
		size_t delPos = VECpSTRsommetsVector.VECgetElement(nSomIterator)->STRfind('=');
		CString STRsommetNb = VECpSTRsommetsVector.VECgetElement(nSomIterator)->STRsubstr(delPos+1);
		unsigned int nSommetNb = STRsommetNb.STRtoInt();
		unsigned int nArrivantSize = 0;
		unsigned int nPartantSize = 0;

		VECSOMSommetVector.VECpush(new CSommet(nSommetNb));

		

		for (unsigned int nArcIterator = 0; nArcIterator < nArcCount; nArcIterator++)
		{
			CVector<CString*> VECarcVec = PARparser.PARparseArray(*VECpSTRarcsVector.VECgetElement(nArcIterator), ',');

			size_t delPosArrivant = VECarcVec.VECgetElement(0)->STRfind('=');
			size_t delPosPartant = VECarcVec.VECgetElement(1)->STRfind('=');

			CString STRdestPartantNb = VECarcVec.VECgetElement(0)->STRsubstr(delPosArrivant + 1);
			CString STRdestArrivantNb = VECarcVec.VECgetElement(1)->STRsubstr(delPosPartant + 1);


			if (STRdestArrivantNb.STRtoInt() == VECSOMSommetVector.VECgetElement(nSomIterator)->SOMgetNumero()) {
				nArrivantSize++;
			}
			if (STRdestPartantNb.STRtoInt() == VECSOMSommetVector.VECgetElement(nSomIterator)->SOMgetNumero()) {
				nPartantSize++;
			}
		}

		CArc **ARCarcArrivants = (CArc**)malloc(sizeof(CArc*)*nPartantSize);
		CArc **ARCarcPartants = (CArc**)malloc(sizeof(CArc*)*nArrivantSize);


		unsigned int nArcPartantIterator = 0;
		unsigned int nArcArrivantIterator = 0;

		for (unsigned int nArcIterator = 0; nArcIterator < nArcCount; nArcIterator++)
		{
			CVector<CString*> VECarcVec = PARparser.PARparseArray(*VECpSTRarcsVector.VECgetElement(nArcIterator), ',');

			size_t delPosArrivant = VECarcVec.VECgetElement(0)->STRfind('=');
			size_t delPosPartant = VECarcVec.VECgetElement(1)->STRfind('=');

			CString STRdestPartantNb = VECarcVec.VECgetElement(0)->STRsubstr(delPosArrivant + 1);
			CString STRdestArrivantNb = VECarcVec.VECgetElement(1)->STRsubstr(delPosPartant + 1);

			unsigned int nDestPartantNb = STRdestPartantNb.STRtoInt();
			unsigned int nDestArrivantNb = STRdestArrivantNb.STRtoInt();




			if (nDestArrivantNb == VECSOMSommetVector.VECgetElement(nSomIterator)->SOMgetNumero()) {
				ARCarcArrivants[nArcArrivantIterator] = new CArc(nDestPartantNb);
				nArcArrivantIterator++;
			}
			if (nDestPartantNb == VECSOMSommetVector.VECgetElement(nSomIterator)->SOMgetNumero()) {
				ARCarcPartants[nArcPartantIterator] = new CArc(nDestArrivantNb);
				nArcPartantIterator++;
			}

		}

		VECSOMSommetVector.VECgetElement(nSomIterator)->SOMsetArrivant(ARCarcArrivants);
		VECSOMSommetVector.VECgetElement(nSomIterator)->SOMsetSizeArrivant(nArcArrivantIterator);
		VECSOMSommetVector.VECgetElement(nSomIterator)->SOMsetPartant(ARCarcPartants);
		VECSOMSommetVector.VECgetElement(nSomIterator)->SOMsetSizePartant(nArcPartantIterator);
	}
}
CGraph::CGraph(CGraph &GRAgraph) 
{
	nSommetCount = GRAgraph.nSommetCount;
	nArcCount = GRAgraph.nArcCount;

	for (unsigned int nGraphIterator = 0; nGraphIterator < nSommetCount; nGraphIterator++)
	{
		CSommet* newSommet = new CSommet(*GRAgraph.GRAgetSommets(nGraphIterator));
		VECSOMSommetVector.VECpush(newSommet);
	}
}
void CGraph::GRAaddSommet(unsigned int nNum) 
{

	try
	{
		if (GRASommetAlreadyExist(nNum))throw (const char *)"Graph: This sommet already exist";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}

	VECSOMSommetVector.VECpush(new CSommet(nNum));
	nSommetCount++;
}

void CGraph::GRAaddSommet(CSommet & SOMparam)
{

	try
	{
		if (GRASommetAlreadyExist(SOMparam.SOMgetNumero()))throw (const char *)"Graph: This sommet already exist";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}

	VECSOMSommetVector.VECpush(new CSommet(SOMparam));
	nSommetCount++;
}

void CGraph::GRAaddSommet(unsigned int nNum, CArc ** arrivant, unsigned int nSizeA, CArc ** partant, unsigned int nSizeP)
{

	try
	{
		if (GRASommetAlreadyExist(nNum))throw (const char *)"Graph: This sommet already exist";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}
	VECSOMSommetVector.VECpush(new CSommet(nNum, arrivant, nSizeA, partant, nSizeP));
	nSommetCount++;
}
void CGraph::GRAmodifySommet(unsigned int nCurrentNum, unsigned int nNewNum)
{
	try
	{
		if (!GRASommetAlreadyExist(nCurrentNum))throw (const char *)"Graph: This sommet don't exist";
		if (GRASommetAlreadyExist(nNewNum))throw (const char *)"Graph: This sommet already exist";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}


	GRAgetSommetById(nCurrentNum)->SOMsetNumero(nNewNum);
	//changer les numeros des arcs li� a ce sommet
	for (unsigned int nGraphIterator = 0; nGraphIterator < nSommetCount; nGraphIterator++)
	{
		CSommet *current = VECSOMSommetVector.VECgetElement(nGraphIterator);
		for (unsigned int nSommetIterator = 0; nSommetIterator < current->SOMgetSizePartant(); nSommetIterator++)
		{
			if (current->SOMgetPartant()[nSommetIterator]->ARCget() == nCurrentNum)
			{
				current->SOMgetPartant()[nSommetIterator]->ARCmodify(nNewNum);
			}
		}
		for (unsigned int nSommetIterator = 0; nSommetIterator < current->SOMgetSizeArrivant(); nSommetIterator++)
		{
			if (current->SOMgetArrivant()[nSommetIterator]->ARCget() == nCurrentNum)
			{
				current->SOMgetArrivant()[nSommetIterator]->ARCmodify(nNewNum);
			}

		}

	}
}
bool CGraph::GRAdelSommetById(unsigned int nId)
{
	try
	{

		if (!GRASommetAlreadyExist(nId))throw (const char *)"Graph: This sommet don't exist";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return false;
	}


	for (unsigned int nGraphIterator = 0; nGraphIterator < nSommetCount; nGraphIterator++)
	{
		CSommet *current = VECSOMSommetVector.VECgetElement(nGraphIterator);
		for (unsigned int nSommetIterator = 0; nSommetIterator < current->SOMgetSizePartant(); nSommetIterator++)
		{
			if (current->SOMgetPartant()[nSommetIterator]->ARCget() == nId)
			{
				GRAremoveArc(current->SOMgetNumero(), nId);
			}
		}
		for (unsigned int nSommetIterator = 0; nSommetIterator < current->SOMgetSizeArrivant(); nSommetIterator++)
		{
			if (current->SOMgetArrivant()[nSommetIterator]->ARCget() == nId)
			{
				GRAremoveArc(nId, current->SOMgetNumero());
			}

		}
	}
	for (unsigned int nGraphIterator = 0; nGraphIterator < nSommetCount; nGraphIterator++)
	{
		if (VECSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nId) {
			VECSOMSommetVector.VECdelElementPointer(nGraphIterator);
			break;
		}
	}
	nSommetCount--;
	return true;
}

//ARC related function
void CGraph::GRAaddArcTo(unsigned int nFromId,unsigned int nToId)
{

	try
	{
		if (GRAarcAlreadyExist(nFromId,nToId))throw (const char *)"Graph: This arc already exist";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}

	CSommet *pSOMfrom = GRAgetSommetById(nFromId);
	CSommet *pSOMdest = GRAgetSommetById(nToId);

	if (pSOMfrom->SOMgetPartant() == NULL)
	{
		pSOMfrom->SOMsetPartant((CArc**)malloc(sizeof(CArc*)));
		pSOMfrom->SOMgetPartant()[0] = new CArc(nToId); 
	}
	else
	{
		pSOMfrom->SOMsetPartant((CArc**)realloc(pSOMfrom->SOMgetPartant(), sizeof(CArc)*(pSOMfrom->SOMgetSizePartant() + 1)));
		pSOMfrom->SOMgetPartant()[pSOMfrom->SOMgetSizePartant()] = new CArc(nToId); 
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
		pSOMdest->SOMgetArrivant()[pSOMdest->SOMgetSizeArrivant()] = new CArc(nFromId);
	}
	pSOMdest->SOMsetSizeArrivant(pSOMdest->SOMgetSizeArrivant()+1);
	nArcCount++;
}

void CGraph::GRAremoveArc(unsigned int nFromId, unsigned int nToId)
{
	try
	{
		if (!GRAarcAlreadyExist(nFromId, nToId))throw (const char *)"Graph: This arc don't exist";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}


	CSommet *pSOMfrom = GRAgetSommetById(nFromId);
	CSommet *pSOMdest = GRAgetSommetById(nToId);

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
	nArcCount--;

}

void CGraph::GRAmodifyArc(unsigned int nFromId, unsigned int nToId, unsigned int nFromNewId, unsigned int nToNewId)
{
	GRAremoveArc(nFromId, nToId);
	GRAaddArcTo(nFromNewId, nToNewId);
}

void CGraph::GRAreverseArc(unsigned int nFromId, unsigned int nToId)
{
	GRAremoveArc(nFromId, nToId);
	GRAaddArcTo(nToId, nFromId);
}

void CGraph::GRAreverseAllArc()
{
	for (unsigned int nIterator = 0; nIterator < nSommetCount; nIterator++)
	{
		for (unsigned int nSomIterator = 0; nSomIterator < VECSOMSommetVector.VECgetElement(nIterator)->SOMgetSizePartant(); nSomIterator++)
		{
			unsigned int nToId = VECSOMSommetVector.VECgetElement(nIterator)->SOMgetPartant()[nSomIterator]->ARCget();
			unsigned int nFromId = VECSOMSommetVector.VECgetElement(nIterator)->SOMgetNumero();
			GRAreverseArc(nFromId, nToId);
		}
		
		
	}

}

//Getter of sommet 
CSommet* CGraph::GRAgetSommetById(unsigned int nNum) const {


	//faire un try catch ici mais probleme de const

	for (unsigned int nGraphIterator = 0; nGraphIterator < nSommetCount; nGraphIterator++)
	{
		if (VECSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nNum) return VECSOMSommetVector.VECgetElement(nGraphIterator);
	}
	return nullptr;
}

bool CGraph::GRASommetAlreadyExist(unsigned int nNum) const
{
	for (unsigned int nGraphIterator = 0; nGraphIterator < nSommetCount; nGraphIterator++)
	{
		if (VECSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nNum) return true;
	}

	return false;
}

bool CGraph::GRAarcAlreadyExist(unsigned int nFom, unsigned int nTo) const
{
	
	for (unsigned int nIterator = 0; nIterator < GRAgetSommetById(nFom)->SOMgetSizePartant(); nIterator++)
	{
		if (GRAgetSommetById(nFom)->SOMgetPartant()[nIterator]->ARCget() == nTo)
		{
			return true;
		}
	}
	return false;
}

unsigned int CGraph::GRAgetSommetCount() const
{
	return nSommetCount;
}

unsigned int CGraph::GRAgetArcCount() const
{
	return nArcCount;
}

CSommet * CGraph::GRAgetSommets(unsigned int nElement) const
{
	return VECSOMSommetVector.VECgetElement(nElement);
}

//Destructor
CGraph::~CGraph()
{
	for (unsigned int nGraphIterator = 0; nGraphIterator < nSommetCount; nGraphIterator++)
	{
		CSommet *current = VECSOMSommetVector.VECgetElement(nGraphIterator);
		for (unsigned int nSommetIterator = 0; nSommetIterator < current->SOMgetSizePartant(); nSommetIterator++)
		{
			unsigned int dest = current->SOMgetPartant()[nSommetIterator]->ARCget();
			unsigned int from = current->SOMgetNumero();
			GRAremoveArc(from, dest);
		}
	}
	for (unsigned int nGraphIterator = 0; nGraphIterator < nSommetCount; nGraphIterator++)
	{
		delete VECSOMSommetVector.VECgetElement(nGraphIterator);
	}
}
