#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"

class door
{
public:
	cube c;
	int photo;

	door(void);

	door(point p1,point p2,point p3,point p4,float hight,int photoo);
	void draw(void);

	~door(void);
};

//point p1(0,0,-4),p2(4,0,-4),p3(4,0,-4.2),p4(0,0,-4.2);
//float hi=6.5;