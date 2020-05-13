#pragma once
#include "CARC.h"
#include <iostream>

using namespace std;


class CSommet
{
	public:

		//constructors
		CSommet();
		CSommet(unsigned int nNum);
		CSommet(int nNum, CArc **  ppARCarrivant, unsigned int nSizeA, CArc **  ppARCpartant, unsigned int nSizeP);
		CSommet(CSommet &param);

		//mutators
		void SOMsetNumero(unsigned int nNum);
		void SOMsetSizeArrivant(unsigned int nSize);
		void SOMsetSizePartant(unsigned int nSize);
		void SOMsetArrivant(CArc** pARCpARCarriv);
		void SOMsetPartant(CArc** pARCpARCpart);

		//accessors
		unsigned int SOMgetNumero() const;
		unsigned int SOMgetSizeArrivant() const;
		unsigned int SOMgetSizePartant() const;
		CArc** SOMgetArrivant();
		CArc** SOMgetPartant();

		//destructor
		~CSommet();

		private:
			unsigned int SOMnNumero;
			CArc** SOMppARCarrivant;
			unsigned int SOMnArrivantSize;
			CArc** SOMppARCpartant;
			unsigned int SOMnPartantSize;
	
};

