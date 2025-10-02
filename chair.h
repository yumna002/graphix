#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"

class chair
{
public:
	cube sit,back,left,right;
	point i1,i2,i3,i4;

	chair(void);

	chair(point p1,point p2,point p3,point p4,float hight,int fabricPhoto,int woodPhoto);
	void draw(void);
	void draw_pair(chair ch1);

	~chair(void);
};

//float hi=1.8;
//point p1(0,0,-2),p2(5.5,0,-2),p3(5.5,0,-4),p4(0,0,-4);