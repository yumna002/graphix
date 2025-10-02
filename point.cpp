#include "point.h"


point::point(void)
{
}

point::point(float xx,float yy,float zz)
{
	x=xx; y=yy; z=zz;
}

void point::init(float xx,float yy,float zz)
{
	x=xx; y=yy; z=zz;
}

point::~point(void)
{
}
