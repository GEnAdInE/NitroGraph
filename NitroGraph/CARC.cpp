#include "CARC.h"

CArc::CArc()
{
	SOMdestination = NULL;

}

CArc::CArc(unsigned int ndest)
{
	try
	{
		if (ndest < 0)throw (const char *)"Arc: can't set a number inferior to 0";

	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}

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
	try
	{
		if (nDest < 0)throw (const char *)"Arc: can't set a number inferior to 0";

	}
	catch (const char *e)
	{
		cout << e << endl;
		return;
	}

	SOMdestination = nDest;
}

unsigned int CArc::ARCget()
{
	return SOMdestination;
}
