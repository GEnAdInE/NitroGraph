#include "CSOMMET.h"

/**
 *  @brief		Default constructor of the class.
 */
CSommet::CSommet()
{
	SOMnNumero = 0;
	SOMppARCarrivant = NULL;
	SOMppARCpartant = NULL;
	SOMnArrivantSize = 0;
	SOMnPartantSize = 0;

}

/**
 *  @brief		Comfort constructor of the class.
 *  @param		nNum	Sommet number.
 *	@example	CSommet mySommet = 1;
 */
CSommet::CSommet(unsigned int nNum)
{
	SOMnNumero = nNum;
	SOMppARCarrivant = NULL;
	SOMppARCpartant = NULL;
	SOMnArrivantSize = 0;
	SOMnPartantSize = 0;
}

/**
 *  @brief		Comfort constructor of the class.
 *  @param		nNum			Sommet number.
 *  @param		ppARCarrivant	Incoming arcs.
 *  @param		nSizeA			Size of incoming arcs.
 *  @param		ppARCpartant	Outgoing arcs.
 *  @param		nSizeP			Size of Outgoing arcs.
 *	@example	CSommet mySommet(1, arcsA, 1, arcsP, 1);
 */
CSommet::CSommet(int nNum, CArc ** ppARCarrivant,unsigned int nSizeA ,CArc ** ppARCpartant,unsigned int nSizeP)
{
	SOMnNumero = nNum;
	SOMnPartantSize = nSizeP;
	SOMnArrivantSize = nSizeA;
	
	SOMppARCarrivant = (CArc**)malloc(sizeof(CArc*)*SOMnArrivantSize);
	SOMppARCpartant = (CArc**)malloc(sizeof(CArc*)*SOMnPartantSize);
	for (unsigned int nIterator = 0; nIterator < SOMgetSizeArrivant(); nIterator++)
	{
		SOMppARCarrivant[nIterator] = new CArc(*ppARCarrivant[nIterator]);
	}
	for (unsigned int nIterator = 0; nIterator < SOMgetSizePartant(); nIterator++)
	{
		SOMppARCpartant[nIterator] = new CArc(*ppARCpartant[nIterator]);
	}
}

/**
 *  @brief  Copy constructor of the class.
 *  @param  SOMParam  CSommet to copy.
 *	@example CSommet mySommet2 = mySommet;
 */
CSommet::CSommet(CSommet & SOMParam)
{
	SOMnNumero = SOMParam.SOMnNumero;
	SOMnArrivantSize = SOMParam.SOMnArrivantSize;
	SOMnPartantSize = SOMParam.SOMnPartantSize;

	SOMppARCarrivant = (CArc**)malloc(sizeof(CArc*)*SOMnArrivantSize);
	SOMppARCpartant = (CArc**)malloc(sizeof(CArc*)*SOMnPartantSize);
	for (unsigned int nIterator = 0; nIterator < SOMgetSizeArrivant(); nIterator++)
	{
		SOMppARCarrivant[nIterator] = new CArc(*SOMParam.SOMppARCarrivant[nIterator]);
	}
	for (unsigned int nIterator = 0; nIterator < SOMgetSizePartant(); nIterator++)
	{
		SOMppARCpartant[nIterator] = new CArc(*SOMParam.SOMppARCpartant[nIterator]);
	}
	

}

/**
 *  @brief  Set	Sommet's number.
 *  @param  nNum	Sommet's number.
 *	@example mySommet.SOMsetNumero(1);
 */
void CSommet::SOMsetNumero(unsigned int nNum)
{
	SOMnNumero = nNum;

}

/**
 *  @brief  Set	incoming arcs size.
 *  @param  nSize	Size.
 *	@example mySommet.SOMsetSizeArrivant(1);
 */
void CSommet::SOMsetSizeArrivant(unsigned int nSize)
{
	SOMnArrivantSize = nSize;
}

/**
 *  @brief  Set	outgoing arcs size.
 *  @param  nSize	Size.
 *	@example mySommet.SOMsetSizePartant(1);
 */
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
	SOMnPartantSize = nSize;
}

/**
 *  @brief  Set	incoming arcs.
 *  @param  ppARCarriv	incoming arcs.
 *	@example mySommet.SOMsetArrivant(myIncomingArcs);
 */
void CSommet::SOMsetArrivant(CArc ** ppARCarriv)
{
	SOMppARCarrivant = ppARCarriv;
}

/**
 *  @brief  Set	outgoing arcs.
 *  @param  ppARCpart	outgoing arcs.
 *	@example mySommet.SOMsetPartant(myOutgoingArcs);
 */
void CSommet::SOMsetPartant(CArc ** ARCARCpart)
{
	SOMppARCpartant = ARCARCpart;
}

/**
 *  @brief  Return the size of incoming arcs.
 *	@example mySommet.SOMgetSizeArrivant();
 */
unsigned int CSommet::SOMgetSizeArrivant() const
{
	return SOMnArrivantSize;
}

/**
 *  @brief  Return the size of outgoing arcs.
 *	@example mySommet.SOMgetSizePartant();
 */
unsigned int CSommet::SOMgetSizePartant() const
{
	return SOMnPartantSize;
}

/**
 *  @brief  Return the Sommet's number.
 *	@example mySommet.SOMgetNumero();
 */
unsigned int CSommet::SOMgetNumero() const
{
	return SOMnNumero;
}

/**
 *  @brief  Return the Sommet's incoming arcs.
 *	@example mySommet.SOMgetArrivant();
 */
CArc ** CSommet::SOMgetArrivant()
{
	return SOMppARCarrivant;
}

/**
 *  @brief  Return the Sommet's outgoing arcs.
 *	@example mySommet.SOMgetPartant();
 */
CArc ** CSommet::SOMgetPartant()
{
	return SOMppARCpartant;
}

/**
 *  @brief  Destructor of the class.
 */
CSommet::~CSommet()
{
	if (SOMnArrivantSize != 0)
	{
		for (unsigned int nIterator = 0; nIterator < SOMnArrivantSize; nIterator++)
		{
			delete SOMppARCarrivant[nIterator];
		}
	}
	if (SOMnPartantSize != 0)
	{
		for (unsigned int nIterator = 0; nIterator < SOMnPartantSize; nIterator++)
		{
			delete SOMppARCpartant[nIterator];
		}
	}

	free(SOMppARCarrivant);
	free(SOMppARCpartant);

}