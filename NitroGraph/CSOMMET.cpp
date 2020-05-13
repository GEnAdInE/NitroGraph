#include "CSOMMET.h"
//realoc obligatoire 


CSommet::CSommet()
{
	nNumero = 0;
	ARCARCarrivant = NULL;
	ARCARCpartant = NULL;
	nArrivantSize = 0;
	nPartantSize = 0;

}

CSommet::CSommet(CSommet & param)
{
	nNumero = param.nNumero;
	nArrivantSize = param.nArrivantSize;
	nPartantSize = param.nPartantSize;

	ARCARCarrivant = (CArc**)malloc(sizeof(CArc*)*nArrivantSize);
	ARCARCpartant = (CArc**)malloc(sizeof(CArc*)*nPartantSize);
	for (unsigned int nIterator = 0; nIterator < SOMgetSizeArrivant(); nIterator++)
	{
		ARCARCarrivant[nIterator] = new CArc(*param.ARCARCarrivant[nIterator]);
	}
	for (unsigned int nIterator = 0; nIterator < SOMgetSizePartant(); nIterator++)
	{
		ARCARCpartant[nIterator] = new CArc(*param.ARCARCpartant[nIterator]);
	}
	

}

CSommet::CSommet(unsigned int nNum)
{
	nNumero = nNum;
	ARCARCarrivant = NULL;
	ARCARCpartant = NULL;
	nArrivantSize = 0;
	nPartantSize = 0;
}



CSommet::CSommet(int nNum, CArc ** arrivant,unsigned int nSizeA ,CArc ** partant,unsigned int nSizeP)
{
	try
	{
		if (nSizeA < 0)throw (const char *)"Sommet: can't set a SizeA < 0";
		if (nSizeP < 0)throw (const char *)"Sommet: can't set a SizeP < 0";
	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}



	nNumero = nNum;
	nPartantSize = nSizeP;
	nArrivantSize = nSizeA;
	
	ARCARCarrivant = (CArc**)malloc(sizeof(CArc*)*nArrivantSize);
	ARCARCpartant = (CArc**)malloc(sizeof(CArc*)*nPartantSize);
	for (unsigned int nIterator = 0; nIterator < SOMgetSizeArrivant(); nIterator++)
	{
		ARCARCarrivant[nIterator] = new CArc(*arrivant[nIterator]);
	}
	for (unsigned int nIterator = 0; nIterator < SOMgetSizePartant(); nIterator++)
	{
		ARCARCpartant[nIterator] = new CArc(*partant[nIterator]);
	}
	

}

CSommet::~CSommet()
{
	if (nArrivantSize != 0)
	{
		for (unsigned int nIterator = 0; nIterator < nArrivantSize; nIterator++)
		{
			delete ARCARCarrivant[nIterator];
		}
	}
	if (nPartantSize != 0)
	{
		for (unsigned int nIterator = 0; nIterator < nPartantSize; nIterator++)
		{
			delete ARCARCpartant[nIterator];
		}
	}
	
	free(ARCARCarrivant);
	free(ARCARCpartant);

}



void CSommet::SOMsetNumero(unsigned int nNum)
{
	try
	{
		if (nNum < 0)throw (const char *)"Sommet: can't set a number inferior to 0";
		
	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}
	nNumero = nNum;

}

const unsigned int CSommet::SOMgetNumero()
{
	return nNumero;
}

const unsigned int CSommet::SOMgetSizeArrivant()
{
	return nArrivantSize;
}

const unsigned int CSommet::SOMgetSizePartant()
{
	return nPartantSize;
}

void CSommet::SOMsetSizeArrivant(unsigned int nSize)
{
	try
	{
		if (nSize < 0)throw (const char *)"Sommet: can't set a number inferior to 0";

	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}
	nArrivantSize = nSize;
}

void CSommet::SOMsetSizePartant(unsigned int nSize)
{
	try
	{
		if (nSize < 0)throw (const char *)"Sommet: can't set a number inferior to 0";

	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}
	nPartantSize = nSize;
}

CArc ** CSommet::SOMgetArrivant()
{
	return ARCARCarrivant;
}

CArc ** CSommet::SOMgetPartant()
{
	return ARCARCpartant;
}


void CSommet::SOMsetArrivant(CArc ** ARCARCarriv)
{
	ARCARCarrivant = ARCARCarriv;
}

void CSommet::SOMsetPartant(CArc ** ARCARCpart)
{
	ARCARCpartant = ARCARCpart;
}








//POUR NICO
/*

void CSommet::SOMaddArcTo(CSommet *SOMdest)
{
	if (ARCARCpartant == NULL)
	{
		ARCARCpartant = (CArc**)malloc(sizeof(CArc*));
		ARCARCpartant[0] = new CArc(SOMdest);
	}
	else
	{
		
		ARCARCpartant = (CArc**)realloc(ARCARCpartant, sizeof(CArc)*(SOMgetSizePartant()+1));
		ARCARCpartant[SOMgetSizePartant()] = new CArc(SOMdest);
	}
	nPartantSize++;
	if (SOMdest->ARCARCarrivant == NULL)
	{
		SOMdest->ARCARCarrivant = (CArc**)malloc(sizeof(CArc*));
		SOMdest->ARCARCarrivant[0] = new CArc(this);
	}
	else
	{
		
		SOMdest->ARCARCarrivant = (CArc**)realloc(SOMdest->ARCARCarrivant, sizeof(CArc)*(SOMgetSizeArrivant() + 1));
		SOMdest->ARCARCarrivant[SOMgetSizeArrivant()] = new CArc(this);
	}
	SOMdest->nArrivantSize++;

}

void CSommet::SOMaddArcFrom(CSommet *SOMcoming)
{

	if (ARCARCarrivant == NULL)
	{
		ARCARCarrivant = (CArc**)malloc(sizeof(CArc));
		ARCARCarrivant[0] = new CArc(SOMcoming);
	}
	else
	{
	
		ARCARCarrivant = (CArc**)realloc(ARCARCarrivant, sizeof(CArc)*(SOMgetSizeArrivant() + 1));
		ARCARCarrivant[SOMgetSizeArrivant()] = new CArc(SOMcoming);
	}
	nArrivantSize++;
	if (SOMcoming->ARCARCpartant == NULL)
	{
		SOMcoming->ARCARCpartant = (CArc**)malloc(sizeof(CArc));
		SOMcoming->ARCARCpartant[0] = new CArc(this);
	}
	else
	{
		
		SOMcoming->ARCARCpartant = (CArc**)realloc(SOMcoming->ARCARCpartant, sizeof(CArc)*(SOMgetSizePartant() + 1));
		SOMcoming->ARCARCpartant[SOMgetSizePartant()] = new CArc(this);
	}
	SOMcoming->nPartantSize++;
}

bool CSommet::SOMarcAlreadyExist(CSommet * from, CSommet * to)
{
	for (unsigned int nIteratorFrom = 0; nIteratorFrom < from->SOMgetSizePartant(); nIteratorFrom++)
	{
		if (ARCARCpartant[nIteratorFrom]->ARCget() == to)
		{
			for (unsigned int nIteratorTo = 0; nIteratorTo < to->SOMgetSizeArrivant(); nIteratorTo++)
			{
				if (ARCARCarrivant[nIteratorTo]->ARCget() == from)
				{
					return true;
				}
			}
			return false;
		}
		
	}
	
	
	return false;
}
*/
