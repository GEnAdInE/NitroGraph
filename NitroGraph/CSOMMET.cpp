#include "CSOMMET.h"
//realoc obligatoire 


CSommet::CSommet()
{
	nNumero = 0;
	ARCARCarrivant = (CArc**) malloc(sizeof(CArc));
	ARCARCpartant = (CArc**)malloc(sizeof(CArc));


}

CSommet::CSommet(CSommet & param)
{
	nNumero = param.nNumero;
	ARCARCarrivant = (CArc**)malloc(sizeof(param.ARCARCarrivant));
	ARCARCpartant = (CArc**)malloc(sizeof(ARCARCpartant));
	for (int iIterator = 0; iIterator < sizeof(ARCARCarrivant); iIterator++)
	{
		ARCARCarrivant[iIterator] = param.ARCARCarrivant[iIterator];
	}
	for (int iIterator = 0; iIterator < sizeof(ARCARCpartant); iIterator++)
	{
		ARCARCpartant[iIterator] = param.ARCARCpartant[iIterator];
	}
	

}

CSommet::CSommet(int nNum, CArc ** arrivant, CArc ** partant)
{
	nNumero = nNum;
	ARCARCarrivant = (CArc**)malloc(sizeof(arrivant));
	ARCARCpartant = (CArc**)malloc(sizeof(partant));
	for (int iIterator = 0; iIterator < sizeof(ARCARCarrivant); iIterator++)
	{
		ARCARCarrivant[iIterator] = arrivant[iIterator];
	}
	for (int iIterator = 0; iIterator < sizeof(ARCARCpartant); iIterator++)
	{
		ARCARCpartant[iIterator] = partant[iIterator];
	}
	

}

CSommet::~CSommet()
{

	free(ARCARCarrivant);
	free(ARCARCpartant);

}
