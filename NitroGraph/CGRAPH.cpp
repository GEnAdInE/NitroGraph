#include "CGRAPH.h"

/**
 *  @brief		Default constructor of the class.
 */
CGraph::CGraph() 
{
	GRAnSommetCount = 0;
	GRAnArcCount = 0;
}

/**
 *  @brief		Comfort constructor of the class.
 *  @param		PARparser	parser.
 *	@example	CGrapg myGraph(myParser);
 */
CGraph::CGraph(CParser &PARparser) 
{
	CString STRnbSommets = PARparser.PARgetValueOfKey("NBSommets");
	CString STRnbArcs = PARparser.PARgetValueOfKey("NBArcs");
	CString STRsommetsArray = PARparser.PARgetValueOfKey("Sommets");
	CString STRarcsArray = PARparser.PARgetValueOfKey("Arcs");

	CVector<CString*> VECpSTRsommetsVector = PARparser.PARparseArray(STRsommetsArray, '\n');
	CVector<CString*> VECpSTRarcsVector = PARparser.PARparseArray(STRarcsArray, '\n');

	GRAnSommetCount = STRnbSommets.STRtoInt();
	GRAnArcCount = STRnbArcs.STRtoInt();

	for (unsigned int nSomIterator = 0; nSomIterator < GRAnSommetCount; nSomIterator++)
	{
		size_t delPos = VECpSTRsommetsVector.VECgetElement(nSomIterator)->STRfind('=');
		CString STRsommetNb = VECpSTRsommetsVector.VECgetElement(nSomIterator)->STRsubstr(delPos+1);
		unsigned int nSommetNb = STRsommetNb.STRtoInt();
		unsigned int nArrivantSize = 0;
		unsigned int nPartantSize = 0;

		GRAVECpSOMSommetVector.VECpush(new CSommet(nSommetNb));

		

		for (unsigned int nArcIterator = 0; nArcIterator < GRAnArcCount; nArcIterator++)
		{
			CVector<CString*> VECarcVec = PARparser.PARparseArray(*VECpSTRarcsVector.VECgetElement(nArcIterator), ',');

			size_t delPosArrivant = VECarcVec.VECgetElement(0)->STRfind('=');
			size_t delPosPartant = VECarcVec.VECgetElement(1)->STRfind('=');

			CString STRdestPartantNb = VECarcVec.VECgetElement(0)->STRsubstr(delPosArrivant + 1);
			CString STRdestArrivantNb = VECarcVec.VECgetElement(1)->STRsubstr(delPosPartant + 1);


			if (STRdestArrivantNb.STRtoInt() == GRAVECpSOMSommetVector.VECgetElement(nSomIterator)->SOMgetNumero()) {
				nArrivantSize++;
			}
			if (STRdestPartantNb.STRtoInt() == GRAVECpSOMSommetVector.VECgetElement(nSomIterator)->SOMgetNumero()) {
				nPartantSize++;
			}
			VECarcVec.VECdelete();
		}

		CArc **ARCarcArrivants = (CArc**)malloc(sizeof(CArc*)*nPartantSize);
		CArc **ARCarcPartants = (CArc**)malloc(sizeof(CArc*)*nArrivantSize);


		unsigned int nArcPartantIterator = 0;
		unsigned int nArcArrivantIterator = 0;

		for (unsigned int nArcIterator = 0; nArcIterator < GRAnArcCount; nArcIterator++)
		{
			CVector<CString*> VECarcVec = PARparser.PARparseArray(*VECpSTRarcsVector.VECgetElement(nArcIterator), ',');

			size_t delPosArrivant = VECarcVec.VECgetElement(0)->STRfind('=');
			size_t delPosPartant = VECarcVec.VECgetElement(1)->STRfind('=');

			CString STRdestPartantNb = VECarcVec.VECgetElement(0)->STRsubstr(delPosArrivant + 1);
			CString STRdestArrivantNb = VECarcVec.VECgetElement(1)->STRsubstr(delPosPartant + 1);

			unsigned int nDestPartantNb = STRdestPartantNb.STRtoInt();
			unsigned int nDestArrivantNb = STRdestArrivantNb.STRtoInt();




			if (nDestArrivantNb == GRAVECpSOMSommetVector.VECgetElement(nSomIterator)->SOMgetNumero()) {
				ARCarcArrivants[nArcArrivantIterator] = new CArc(nDestPartantNb);
				nArcArrivantIterator++;
			}
			if (nDestPartantNb == GRAVECpSOMSommetVector.VECgetElement(nSomIterator)->SOMgetNumero()) {
				ARCarcPartants[nArcPartantIterator] = new CArc(nDestArrivantNb);
				nArcPartantIterator++;
			}
			VECarcVec.VECdelete();

		}

		GRAVECpSOMSommetVector.VECgetElement(nSomIterator)->SOMsetArrivant(ARCarcArrivants);
		GRAVECpSOMSommetVector.VECgetElement(nSomIterator)->SOMsetSizeArrivant(nArcArrivantIterator);
		GRAVECpSOMSommetVector.VECgetElement(nSomIterator)->SOMsetPartant(ARCarcPartants);
		GRAVECpSOMSommetVector.VECgetElement(nSomIterator)->SOMsetSizePartant(nArcPartantIterator);
	}
	VECpSTRsommetsVector.VECdelete();
	VECpSTRarcsVector.VECdelete();
}

/**
 *  @brief  Copy constructor of the class.
 *  @param  GRAgraph  CGraph to copy.
 *	@example CGraph myGraph2 = myGraph;
 */
CGraph::CGraph(CGraph &GRAgraph) 
{
	GRAnSommetCount = GRAgraph.GRAnSommetCount;
	GRAnArcCount = GRAgraph.GRAnArcCount;

	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		CSommet* newSommet = new CSommet(*GRAgraph.GRAgetSommets(nGraphIterator));
		GRAVECpSOMSommetVector.VECpush(newSommet);
	}
}

/**
 *  @brief  Add a sommet to the graph.
 *	@throws	Sommet already exist
 *  @param  nNum  Sommet's number.
 *	@example myGraph.GRAaddSomet(1);
 */
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

	GRAVECpSOMSommetVector.VECpush(new CSommet(nNum));
	GRAnSommetCount++;
}

/**
 *  @brief  Add a sommet to the graph.
 *	@throws	Sommet already exist
 *  @param  SOMparam  CSommet to copy.
 *	@example myGraph.GRAaddSomet(mySommet);
 */
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

	GRAVECpSOMSommetVector.VECpush(new CSommet(SOMparam));
	GRAnSommetCount++;
}

/**
 *  @brief  Add a sommet to the graph.
 *	@throws	Sommet already exist
 *  @param  nNum			Sommet's number.
 *  @param  ppARCarrivant	Incoming arcs.
 *  @param  nSizeA			Size of incoming arcs.
 *  @param  ppARCpartant	Outgoing arcs.
 *  @param  nSizeP			Size of outgoing arcs.
 *	@example myGraph.GRAaddSomet(1, myIncomingArcs, 1, myOutgoingArcs, 1);
 */
void CGraph::GRAaddSommet(unsigned int nNum, CArc ** ppARCarrivant, unsigned int nSizeA, CArc ** ppARCpartant, unsigned int nSizeP)
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
	GRAVECpSOMSommetVector.VECpush(new CSommet(nNum, ppARCarrivant, nSizeA, ppARCpartant, nSizeP));
	GRAnSommetCount++;
}

/**
 *  @brief  Modify a sommet.
 *	@throws	Sommet don't exist
 *	@throws	Sommet already exist
 *  @param  nCurrentNum		Current sommet's number.
 *  @param  nNewNum			New sommet's number.
 *	@example myGraph.GRAmodifySommet(1, 2);
 */
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

	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		CSommet *current = GRAVECpSOMSommetVector.VECgetElement(nGraphIterator);
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

/**
 *  @brief  Remove a sommet.
 *	@throws	Sommet don't exist
 *  @param  nId		Sommet's number to remove.
 *	@example myGraph.GRAdelSommet(1);
 */
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


	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		CSommet *current = GRAVECpSOMSommetVector.VECgetElement(nGraphIterator);
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
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		if (GRAVECpSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nId) {
			GRAVECpSOMSommetVector.VECdelElementPointer(nGraphIterator);
			break;
		}
	}
	GRAnSommetCount--;
	return true;
}

/**
 *  @brief  Add an arc from a sommet to another.
 *	@throws	Arc already exist
 *  @param  nFromId		Sommet's number from which the arc starts.
 *  @param  nToId		Sommet's number to which the arc ends.
 *	@example myGraph.GRAaddArcTo(1, 2);
 */
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
	GRAnArcCount++;
}

/**
 *  @brief  Remove an arc from a sommet to another.
 *	@throws	Arc don't exist
 *  @param  nFromId		Sommet's number from which the arc starts.
 *  @param  nToId		Sommet's number to which the arc ends.
 *	@example myGraph.GRAremoveArc(1, 2);
 */
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
	GRAnArcCount--;

}

/**
 *  @brief  Modify an Arc.
 *  @param  nFromId			Sommet's number from which the arc starts.
 *  @param  nToId			Sommet's number to which the arc ends.
 *  @param  nNewFromId		Sommet's number from which the arc will start.
 *  @param  nNewToId		Sommet's number to which the arc will end.
 *	@example myGraph.Modify(1, 2, 2, 1);
 */
void CGraph::GRAmodifyArc(unsigned int nFromId, unsigned int nToId, unsigned int nFromNewId, unsigned int nToNewId)
{
	GRAremoveArc(nFromId, nToId);
	GRAaddArcTo(nFromNewId, nToNewId);
}

/**
 *  @brief  Reverse an arc.
 *  @param  nFromId			Sommet's number from which the arc starts.
 *  @param  nToId			Sommet's number to which the arc ends.
 *	@example myGraph.GRAreverseArc(1, 2);
 */
void CGraph::GRAreverseArc(unsigned int nFromId, unsigned int nToId)
{
	GRAremoveArc(nFromId, nToId);
	GRAaddArcTo(nToId, nFromId);
}

/**
 *  @brief  Return a pointer to a new graph with all arcs reversed.
 *	@example CGraph * myReversedGraph = myGraph.GRAreverseAllArc();
 */
CGraph * CGraph::GRAreverseAllArc()
{
	CGraph * newGraph = new CGraph(*this);

	for (unsigned int nIterator = 0; nIterator < GRAnSommetCount; nIterator++)
	{
		for (unsigned int nSomIterator = 0; nSomIterator < GRAVECpSOMSommetVector.VECgetElement(nIterator)->SOMgetSizePartant(); nSomIterator++)
		{
			unsigned int nToId = GRAVECpSOMSommetVector.VECgetElement(nIterator)->SOMgetPartant()[nSomIterator]->ARCget();
			unsigned int nFromId = GRAVECpSOMSommetVector.VECgetElement(nIterator)->SOMgetNumero();
			newGraph->GRAreverseArc(nFromId, nToId);
		}
		
	}
	return newGraph;

}

/**
 *  @brief  Return a pointer to a sommet.
 *  @param  nNum			Sommet's number to get.
 *	@example CSommet * mySommet = myGraph.GRAgetSommetById(1);
 */
CSommet* CGraph::GRAgetSommetById(unsigned int nNum) const {

	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		if (GRAVECpSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nNum) return GRAVECpSOMSommetVector.VECgetElement(nGraphIterator);
	}
	return nullptr;
}

/**
 *  @brief  Return true if the sommet already exist, false otherwise.
 *  @param  nNum			Sommet's number to check.
 *	@example myGraph.GRASommetAlreadyExist(1);
 */
bool CGraph::GRASommetAlreadyExist(unsigned int nNum) const
{
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		if (GRAVECpSOMSommetVector.VECgetElement(nGraphIterator)->SOMgetNumero() == nNum) return true;
	}

	return false;
}

/**
 *  @brief  Return true if the arc already exist, false otherwise.
 *  @param  nFromId			Sommet's number from which the arc starts.
 *  @param  nToId			Sommet's number to which the arc ends.
 *	@example myGraph.GRAarcAlreadyExist(1, 2);
 */
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

/**
 *  @brief  Return the number of sommets in the graph.
 *	@example unsigned int myGraphSommetCount = myGraph.GRAgetSommetCount();
 */
unsigned int CGraph::GRAgetSommetCount() const
{
	return GRAnSommetCount;
}

/**
 *  @brief  Return the number of arcs in the graph.
 *	@example unsigned int myGraphArcCount = myGraph.GRAgetArcCount();
 */
unsigned int CGraph::GRAgetArcCount() const
{
	return GRAnArcCount;
}

/**
 *  @brief  Return the sommet at the index specified in the vector.
 *	@example nElement	Vector index;
 */
CSommet * CGraph::GRAgetSommets(unsigned int nElement) const
{
	return GRAVECpSOMSommetVector.VECgetElement(nElement);
}

/**
 *  @brief  Destructor of the class.
 */
CGraph::~CGraph()
{
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		CSommet *current = GRAVECpSOMSommetVector.VECgetElement(nGraphIterator);
		for (unsigned int nSommetIterator = 0; nSommetIterator < current->SOMgetSizePartant(); nSommetIterator++)
		{
			unsigned int nDest = current->SOMgetPartant()[nSommetIterator]->ARCget();
			unsigned int nFrom = current->SOMgetNumero();
			GRAremoveArc(nFrom, nDest);
		}
	}
	for (unsigned int nGraphIterator = 0; nGraphIterator < GRAnSommetCount; nGraphIterator++)
	{
		delete GRAVECpSOMSommetVector.VECgetElement(nGraphIterator);
	}
}
