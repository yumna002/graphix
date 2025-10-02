#include "foodTable.h"
#include "chair2.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "point.h"
#include "color.h"
#include "cube.h"


foodTable::foodTable(void)
{
}

foodTable::foodTable(point i1,point i2,point i3,point i4,point x1,point x2,point x3,point x4,
		float width,float hight,float thick,int foodTableWood,int foodTableFabric)
{
	this->i1=i1; this->i2=i2; this->i3=i3; this->i4=i4;
	this->x1=x1; this->x2=x2; this->x3=x3; this->x4=x4;
	this->width=width; this->hight=hight; this->thick=thick;
	this->foodTableWood=foodTableWood; this->foodTableFabric=foodTableFabric;

	chair2 ch(i1,i2,i3,i4,hight,width,thick,foodTableFabric,foodTableWood);
	this->ch=ch;
}

void foodTable::draw(float foodTableX,float foodTableY,float foodTableZ)
{
	/////////////////////////////////////////drawing chairs
	glPushMatrix();

	//draw first pair of chairs
	glPushMatrix();
	ch.draw_pair2(ch);
	glPopMatrix();

	//draw second pair of chairs
	glPushMatrix();
	glTranslated(0,0,-6);
	glTranslated(foodTableX,foodTableY,foodTableZ);
	ch.draw_pair2(ch);
	glPopMatrix();

	glPopMatrix();
	/////////////////////////////////////////////////////////


	/////////////////////////////////////////////drawing table
	glPushMatrix();
	glTranslated(3,0,-8);

	hight+=1;
	point x1(0,0,0),x2(thick,0,0),x3(thick,0,-thick),x4(0,0,-thick);
	cube Tleg(x1,x2,x3,x4,hight,foodTableWood);
	
	point x5=x1,x6=x2,x7=x3,x8=x4;
	x5.x-=width/4; x6.x+=width/4; x5.z+=width/4; x6.z+=width/4;
	x8.x-=width/4; x7.x+=width/4; x7.z-=width/4; x8.z-=width/4;
	cube q(x5,x6,x7,x8,thick,foodTableWood);
	
	x5=x1,x6=x2,x7=x3,x8=x4;
	x5.x-=2*width; x6.x+=2*width; x5.z+=width; x6.z+=width;
	x8.x-=2*width; x7.x+=2*width; x7.z-=width; x8.z-=width;
	x5.y+=hight; x6.y+=hight; x7.y+=hight; x8.y+=hight;
	cube table(x5,x6,x7,x8,thick,foodTableFabric);
	
	glPushMatrix();
	Tleg.draw();
	glPopMatrix();

	glPushMatrix();
	table.draw();
	glPopMatrix();

	glPushMatrix();
	q.draw();
	glPopMatrix();

	glPopMatrix();
	//////////////////////////////////////////////////////////
}

foodTable::~foodTable(void)
{
}
