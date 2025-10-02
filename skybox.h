#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"

class skybox
{
public:
	int front,back,left,right,top,down;
	point p1,p2,p3,p4,p5,p6,p7,p8;

	skybox(void);

	skybox(point p11,point p22,point p33,point p44,point p55,point p66,point p77,point p88,
		int frontt,int backk,int topp,int downn,int leftt,int rightt);
	void draw(void);
	void draw2(point i1,point i2,point i3,point i4,point i5,point i6,point i7,point i8,int ph);

	~skybox(void);
};

/*
////////////////////////////////////////////draw sky box
	glPushMatrix();
	point S1(-60,-2,0),S2(60,-2,0),S3(60,50,0),S4(-60,50,0),
		S5(-60,-2,-800),S6(60,-2,-800),S7(60,50,-800),S8(-60,50,-800);
	skybox skx(S1,S2,S3,S4,S5,S6,S7,S8,front,back,top,down,left,right);
	skx.draw();
	glPopMatrix();
	/////////////////////////////////////////////////////////

*/