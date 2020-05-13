
#pragma once 

#include <stdio.h>
#include <stdlib.h>  
#include <iostream>

using namespace std;

class CArc
{
	public:

		//constructors
		CArc();
		CArc(unsigned int nDest);
		CArc(CArc &ARCparam);
	
		//mutators
		void ARCmodify(unsigned int nDest);

		//accessors
		unsigned int ARCget() const;

	private:
		unsigned int SOMnDestination;

};

