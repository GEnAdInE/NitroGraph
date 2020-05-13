
#pragma once 

#include <stdio.h>
#include <stdlib.h>  
#include <iostream>

using namespace std;

class CArc
{
	private : 
		unsigned int SOMdestination;

	public:

		CArc();
		CArc(unsigned int dest);
		CArc(CArc &param);
		~CArc();

	
		void ARCmodify(unsigned int SOMdest);
		unsigned int ARCget();



};

