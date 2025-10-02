#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"

class bed
{
public:
	point x1,x2,x3,x4;
	float hight,width,thick;
	int bedWood,bedSleep,bedHead;


	bed(void);
	
	bed(point x1,point x2,point x3,point x4,float hight,float width,float thick,int bedWood,int bedSleep,int bedHead);
	void draw(void);
	void draw_pair(bed b);
	
	~bed(void);
};

