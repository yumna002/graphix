#include "person.h"
#include "skybox.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "point.h"
#include "color.h"
#include "cube.h"

person::person(void)
{
}

person::person(point a1,point a2,point a3,point a4,float hight,float width,int steve_body,int steve_head,int steve_hand)
{
	this->a1=a1; this->a2=a2; this->a3=a3; this->a4=a4;
	this->hight=hight; this->width=width;
	this->steve_body=steve_body; this->steve_head=steve_head; this->steve_hand=steve_hand;

	cube body(a1,a2,a3,a4,hight,steve_body);
	
	point a5=a1,a6=a2,a7=a3,a8=a4;
	a5.x+=width/4; a8.x+=width/4; a7.x-=width/4; a6.x-=width/4;
	a5.y=hight; a6.y=hight; a7.y=hight; a8.y=hight;
	cube head(a5,a6,a7,a8,hight/4,steve_head);

	point a11=a1,a22=a1,a33=a1,a44=a1;
	a11.x-=width/4; a44.x-=width/4;
	a33.z=a4.z; a44.z=a4.z;
	a11.y=hight/2; a22.y=hight/2; a33.y=hight/2; a44.y=hight/2;
	cube hand(a11,a22,a33,a44,hight/2,steve_hand);

	this->body=body; this->head=head; this->hand=hand;
}

void person::draw()
{
	body.draw(); head.draw();
	hand.draw();

	glPushMatrix();
	glTranslated((1.25)*width,0,0);
	hand.draw();
	glPopMatrix();
}

person::~person(void)
{
}
