#include "chair.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "point.h"
#include "color.h"
#include "cube.h"

chair::chair(void)
{
}

chair::chair(point p1,point p2,point p3,point p4,float hight,int fabricPhoto,int woodPhoto)
{
	i1=p1; i2=p2; i3=p3; i4=p4;

	point pb1=p4,pb2=p3,pb3=pb2,pb4=pb1; float hightb=2*hight;
	pb3.z-=0.7; pb4.z-=0.7;
	
	point pr1=p2,pr2=pr1,pr3=p3,pr4=p3; float hightr=2*(hightb/3);
	pr2.x+=0.3; pr3.x+=0.3;
	
	point pl1=p1,pl2=p1,pl3=p4,pl4=p4; float hightl=2*(hightb/3);
	pl1.x-=0.3; pl4.x-=0.3;

	cube Sit(p1,p2,p3,p4,hight,fabricPhoto),Back(pb1,pb2,pb3,pb4,hightb,woodPhoto),
		Left(pl1,pl2,pl3,pl4,hightl,woodPhoto),Right(pr1,pr2,pr3,pr4,hightr,woodPhoto);

	sit=Sit; back=Back; left=Left; right=Right;
}

void chair::draw_pair(chair ch1)
{
	chair ch2=ch1;
	ch1.draw();

	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(-4.2,0,7);
	ch2.draw();
	glPopMatrix();
}

void chair::draw()
{
	sit.draw(); back.draw();
	left.draw(); right.draw();
}

chair::~chair(void)
{
}
