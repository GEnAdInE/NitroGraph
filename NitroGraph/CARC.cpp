#include "CARC.h"

CArc::CArc()
{
	nDestination = NULL;

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

	nDestination = ndest;

}


CArc::CArc(CArc &param)
{
	nDestination = param.nDestination;
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

	nDestination = nDest;
}

unsigned int CArc::ARCget()
{
	return nDestination;
}

bool CArc::operator==(CArc arc)
{
	if (nDestination == arc.nDestination)
	{
		return true;
	}
	return false;
}

bool CArc::operator!=(CArc arc)
{
	if (nDestination != arc.nDestination)
	{
		return true;
	}
	return false;
}

void CArc::operator=(CArc arc)
{

	nDestination = arc.nDestination;

}
