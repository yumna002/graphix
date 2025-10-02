#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"

class chair2
{
public:
	point p1,p2,p3,p4;
	float width,hight,thick;
	int chairWood,chairFabric;

	chair2(void);
	
	chair2(point p1,point p2,point p3,point p4,float hight,float width,float thick,int chairFabric,int chairWood);
	
	void draw(void);
	void draw2(void);

	void draw_pair(chair2 ch);
	void draw_pair2(chair2 ch);
	
	~chair2(void);
};

/*
float width=3.2,hight=2.1,thick=0.3;
point i1(0,0,0),i2(thick,0,0),i3(thick,0,-thick),i4(0,0,-thick);
chair2 ch(i1,i2,i3,i4,hight,width,thick,chairFabric,chairWood);


//type2
float width=2,hight=3.5,thick=0.4;
point i1(0,0,0),i2(thick,0,0),i3(thick,0,-thick),i4(0,0,-thick);
chair2 ch(i1,i2,i3,i4,hight,width,thick,chairFabric,chairWood);
	
ch.draw2();
*/