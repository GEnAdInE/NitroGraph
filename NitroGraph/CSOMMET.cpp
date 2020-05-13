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

	ARCARCarrivant = (CArc**)malloc(sizeof(CArc**)*nArrivantSize);
	ARCARCpartant = (CArc**)malloc(sizeof(CArc**)*nPartantSize);
	for (unsigned int nIterator = 0; nIterator < SOMgetSizeArrivant(); nIterator++)
	{
		ARCARCarrivant[nIterator] = param.ARCARCarrivant[nIterator];
	}
	for (unsigned int nIterator = 0; nIterator < SOMgetSizePartant(); nIterator++)
	{
		ARCARCpartant[nIterator] = param.ARCARCpartant[nIterator];
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
		ARCARCarrivant[nIterator] = arrivant[nIterator];
	}
	for (unsigned int nIterator = 0; nIterator < SOMgetSizePartant(); nIterator++)
	{
		ARCARCpartant[nIterator] = partant[nIterator];
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
