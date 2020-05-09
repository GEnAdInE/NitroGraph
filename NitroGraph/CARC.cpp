#include "CARC.h"

CArc::CArc()
{
	SOMdestination = NULL;

}

CArc::CArc(unsigned int ndest)
{

	SOMdestination = ndest;

}


CArc::CArc(CArc &param)
{
	SOMdestination = param.SOMdestination;
}

CArc::~CArc()
{
}

void CArc::ARCmodify(unsigned int nDest)
{
	SOMdestination = nDest;
}

unsigned int CArc::ARCget()
{
	return SOMdestination;
}
