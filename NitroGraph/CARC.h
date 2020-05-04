



#include <stdio.h>
#include <stdlib.h>   

class CSommet;

class CArc
{
	private : 
		CSommet* SOMdestination;

	public:

		CArc();
		CArc(CSommet* SOMdest);
		CArc(CArc &param);
		~CArc();

	
		void ARCmodify(CSommet* SOMdest);
		CSommet* ARCget();



};

