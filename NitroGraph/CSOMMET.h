#pragma once
#include "CARC.h"


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
		CSommet(int nNum, CArc ** arrivant, unsigned int uSizeA, CArc ** partant, unsigned int uSizeP);
		~CSommet();


		void SOMsetNumero(unsigned int nNum);
		unsigned int SOMgetNumero();
		unsigned int SOMgetSizeArrivant(); 
		unsigned int SOMgetSizePartant();









		// cadeau pour nico 
		void SOMaddArcTo(CSommet *SOMdest); 
		void SOMaddArcFrom(CSommet *SOMcoming);
		bool SOMarcAlreadyExist(CSommet *from, CSommet *to); //fonction caca inutile pour l'instant  mais peux servir (pas sur ca marche a 100%)


		void SOMremoveARc(CArc arrivant , CArc partant);
		void SOMmodifyArc(CArc OLDarrivant, CArc OLDpartant, CArc NEWarrivant, CArc NEWpartant);
};

