#pragma once
#include "CARC.h"
#include <iostream>

using namespace std;


class CSommet
{

	private:
		unsigned int nNumero;
		CArc** ARCARCarrivant;
		unsigned int nArrivantSize;
		CArc** ARCARCpartant;
		unsigned int nPartantSize;
	public:
		CSommet();
		CSommet(CSommet &param);
		CSommet(unsigned int nNum);
		CSommet(int nNum, CArc ** arrivant, unsigned int uSizeA, CArc ** partant, unsigned int uSizeP);
		~CSommet();


		void SOMsetNumero(unsigned int nNum);
		unsigned int SOMgetNumero();
		unsigned int SOMgetSizeArrivant(); 
		unsigned int SOMgetSizePartant();
		void SOMsetSizeArrivant(unsigned int nSize);
		void SOMsetSizePartant(unsigned int nSize);
		CArc** SOMgetArrivant();
		CArc** SOMgetPartant();
		void SOMsetArrivant(CArc** ARCARCarriv);
		void SOMsetPartant(CArc** ARCARCpart);
		void SOMreverseArc();

		bool operator==(CSommet SOMsommet);
		bool operator!=(CSommet SOMsommet);
		void operator=(CSommet SOMsommet);





	
};

