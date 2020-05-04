#pragma once
#include "CARC.h"

class CSommet
{

	private:
		unsigned int nNumero;
		CArc** ARCARCarrivant;
		CArc** ARCARCpartant;
	public:
		CSommet();
		CSommet(CSommet &param);
		CSommet(int nNumero, CArc **arrivant, CArc **partant);
		~CSommet();

};

