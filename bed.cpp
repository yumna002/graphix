#include "bed.h"
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

bed::bed(void)
{
}

bed::bed(point x1,point x2,point x3,point x4,float hight,float width,float thick,int bedWood,int bedSleep,int bedHead)
{
	this->x1=x1; this->x2=x2; this->x3=x3;this->x4=x4;
	this->hight=hight; this->width=width; this->thick=thick;
	this->bedWood=bedWood; this->bedSleep=bedSleep; this->bedHead=bedHead;
}

void bed::draw()
{
	//////////////////////////////////////////////////////////draw bed
	glPushMatrix();

	cube sit_df(x1,x2,x3,x4,hight,bedWood);
	sit_df.draw();

	point z1=x1,z2=x1,z3=x4,z4=x4;
	z1.x-=thick; z4.x-=thick;
	cube df(z1,z2,z3,z4,2*hight,bedWood);

	//draw left df
	glPushMatrix();
	glTranslated(0,-1,0);
	df.draw();
	glPopMatrix();
	
	//draw right df
	glPushMatrix();
	glTranslated(0,-1,0);
	glTranslated(width+thick,0,0);
	df.draw();
	glPopMatrix();


	point i1=x1,i2=x2,i3=x3,i4=x4;
	i1.y+=hight; i2.y+=hight; i3.y+=hight; i4.y+=hight;
	cube sleep(i1,i2,i3,i4,thick,bedSleep);
	sleep.draw();


	point y1=i2,y2=i2,y3=i3,y4=i3;
	y1.x-=(width/4); y4.x-=(width/4);
	y1.y+=thick; y2.y+=thick; y3.y+=thick; y4.y+=thick;
	cube head(y1,y2,y3,y4,2*thick,bedHead);
	head.draw();


	glPopMatrix();
	////////////////////////////////////////////////////////////////////

}

void bed::draw_pair(bed b)
{
	//////////////////////////////draw pair of beds
	glPushMatrix();
	
	//down bed
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(0,0,0);
	glTranslated(-8.1,1,0);
	b.draw();
	glPopMatrix();
	
	//top bed
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(0,0,0);
	glTranslated(-8.1,1,0);
	glTranslated(0,4.4,0);
	b.draw();
	glPopMatrix();

	glPopMatrix();
	

	glPopMatrix();
	///////////////////////////////////////////////////
}

bed::~bed(void)
{
}
