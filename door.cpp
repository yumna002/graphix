#include "door.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "point.h"
#include "color.h"
#include "cube.h"

door::door(void)
{
}

door::door(point p1,point p2,point p3,point p4,float hight,int photoo)
{
	photo=photoo;
	cube cc(p1,p2,p3,p4,hight,photo);
	c=cc;
}

void door::draw()
{
	c.draw();
}

door::~door(void)
{
}
