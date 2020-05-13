#include "CARC.h"

/**
 *  @brief		Default constructor of the class.
 */
CArc::CArc()
{
	SOMnDestination = NULL;
}

/**
 *  @brief		Comfort constructor of the class.
 *	@throws		Destination can not be negative.
 *  @param		nDest	Destination.
 *	@example	CArc myArc = 1;
 */
CArc::CArc(unsigned int nDest)
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

	SOMnDestination = nDest;

}

/**
 *  @brief  Copy constructor of the class.
 *  @param  ARCParam  CArc to copy.
 *	@example CArc myArc2 = myArc;
 */
CArc::CArc(CArc &ARCParam)
{
	SOMnDestination = ARCParam.SOMnDestination;
}

/**
 *  @brief		Modify the arc's destination.
 *	@throws		Destination can not be negative.
 *  @param		nDest	Destination.
 *	@example	myArc.ARCModify(1);
 */
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

	SOMnDestination = nDest;
}

/**
 *  @brief		Return the destination of the arc.
 *	@example	myArc.ARCget();
 */
unsigned int CArc::ARCget() const
{
	return SOMnDestination;
}