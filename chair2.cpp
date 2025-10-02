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

chair2::chair2(void)
{
}

chair2::chair2(point p1,point p2,point p3,point p4,float hight,float width,float thick,int chairFabric,int chairWood)
{
	this->p1=p1; this->p2=p2; this->p3=p3; this->p3=p3; this->p4=p4;
	this->chairFabric=chairFabric;
	this->chairWood=chairWood;
	this->hight=hight; this->width=width; this->thick=thick;
}

void chair2::draw()
{
	//////////////////////////////////////////////draw cinema chairs
	glPushMatrix();
	cube leg(p1,p2,p3,p4,hight,chairWood);
	
	point p5=p1,p6=p2,p7=p3,p8=p4;
	p5.y+=hight; p6.y+=hight; p7.y+=hight; p8.y+=hight;
	p6.x+=width; p7.x+=width;
	p5.z+=(width/2+thick); p6.z+=(width/2+thick);

	cube sit(p5,p6,p7,p8,thick,chairFabric);

	point p9=p7,p10=p8;
	p9.z-=thick; p10.z-=thick;
	cube back(p8,p7,p9,p10,hight,chairWood);

	//front left leg
	glPushMatrix();
	leg.draw();
	glPopMatrix();
	//front right leg
	glPushMatrix();
	glTranslated(width,0,0);
	leg.draw();
	glPopMatrix();
	//back right leg
	glPushMatrix();
	glTranslated(width,0,(width/2));
	leg.draw();
	glPopMatrix();
	//back left leg
	glPushMatrix();
	glTranslated(0,0,(width/2));
	leg.draw();
	glPopMatrix();

	//sit
	glPushMatrix();
	sit.draw();
	glPopMatrix();

	//back
	glPushMatrix();
	back.draw();
	glPopMatrix();

	glPopMatrix();
	//////////////////////////////////////////////////////////////////
}

void chair2::draw2()
{
	///////////////////////////////////////draw chair2 type2
	glPushMatrix();

	cube leg(p1,p2,p3,p4,hight,chairWood);
	
	point p5=p1,p6=p2,p7=p3,p8=p4;
	p5.y+=hight; p6.y+=hight; p7.y+=hight; p8.y+=hight;
	p6.x+=width; p7.x+=width;
	p5.z+=(width/2+thick); p6.z+=(width/2+thick);

	cube sit(p5,p6,p7,p8,thick,chairFabric);

	//front left leg
	glPushMatrix();
	leg.draw();
	glPopMatrix();
	//front right leg
	glPushMatrix();
	glTranslated(width/2,0,0);
	leg.draw();
	glPopMatrix();
	//back right leg
	glPushMatrix();
	glTranslated(width/2,0,(width/2));
	leg.draw();
	glPopMatrix();
	//back left leg
	glPushMatrix();
	glTranslated(0,0,(width/2));
	leg.draw();
	glPopMatrix();

	//sit
	glPushMatrix();
	glTranslated(-width/4,0,-(thick/2));
	sit.draw();
	glPopMatrix();



	glPopMatrix();
	////////////////////////////////////////////////////////
}

void chair2::draw_pair(chair2 ch)
{
	//draw pair of chairs front-back
	glPushMatrix();

	//back chair
	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(0,0,0);
	glTranslated(3.3,0,0.7);
	ch.draw();
	glPopMatrix();

	//front chair
	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(0,0,0);
	glTranslated(3.3,0,6);
	ch.draw();
	glPopMatrix();
	
	glPopMatrix();
}

void chair2::draw_pair2(chair2 ch)
{
	///////////////draw pair of chairs left and right
	glPushMatrix();

	//left chair
	glPushMatrix();
	glTranslated(1,0,-5);
	ch.draw2();
	glPopMatrix();

	//right chair
	glPushMatrix();
	glTranslated(1,0,-5);
	glTranslated(2.7,0,0);
	ch.draw2();
	glPopMatrix();
	
	glPopMatrix();
	///////////////////////////////////
}

chair2::~chair2(void)
{
}
