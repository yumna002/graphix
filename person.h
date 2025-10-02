#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"

class person
{
public:
	point a1,a2,a3,a4;
	float hight,width;
	int steve_body,steve_head,steve_hand;
	cube body,head,hand;

	person(void);
	
	person(point a1,point a2,point a3,point a4,float hight,float width,int steve_body,int steve_head,int steve_hand);
	void draw(void);
	
	~person(void);
};


/*
	/////////////////////////////////////////////////draw person for 3rd camera
	glPushMatrix();

	if(keys['U']){
		rd3_view=true;
	}
	if(keys['I']){
		rd3_view=false;
	}

	float hight=4.5,width=2;
	point a1(0,0,0),a2(width,0,0),a3(width,0,-0.5),a4(0,0,-0.5);

	glRotated(cam.RotatedY,0,1,0);
	glTranslated(cam.Position.x-width/2,cam.Position.y-hight/4,cam.Position.z+hight/2);	

	person p(a1,a2,a3,a4,hight,width,steve_body,steve_head,steve_hand);
	p.draw();
	
	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////
*/