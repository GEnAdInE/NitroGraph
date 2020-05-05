#include "CARC.h"

CArc::CArc()
{
	SOMdestination = NULL;

}

CArc::CArc(CSommet * SOMdest)
{

	SOMdestination = SOMdest;

}


CArc::CArc(CArc &param)
{
	SOMdestination = param.SOMdestination;
}

CArc::~CArc()
{
}

void CArc::ARCmodify(CSommet *SOMdest)
{
	SOMdestination = SOMdest;

}

CSommet * CArc::ARCget()
{
	return SOMdestination;
}
