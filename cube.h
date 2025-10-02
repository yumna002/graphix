#pragma once
#include "point.h"
#include "color.h"

class cube
{
public:
	point p1,p2,p3,p4;
	float hight;
	int photo;

	cube(void);

	cube(point p11,point p22,point p33,point p44,float hightt,int photoo);
	void draw(void);
	void draw2(int controllTable,int controllTableSide);
	void draw_with_color(color c);

	~cube(void);
};

