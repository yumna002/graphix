#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"
#include "chair2.h"

class foodTable
{
public:
	float width,hight,thick;
	point i1,i2,i3,i4;
	point x1,x2,x3,x4;
	chair2 ch;
	int foodTableWood,foodTableFabric;

	foodTable(void);
	
	foodTable(point i1,point i2,point i3,point i4,point x1,point x2,point x3,point x4,
		float width,float hight,float thick,int foodTableWood,int foodTableFabric);
	void draw(float foodTableX,float foodTableY,float foodTableZ);
	
	~foodTable(void);
};

/*
/////////////////////////////////////////drawing foodTables
	glPushMatrix();

	float width=1.4,hight=3.4,thick=0.3;
	point i1(0,0,0),i2(thick,0,0),i3(thick,0,-thick),i4(0,0,-thick);
	point x1(0,0,0),x2(thick,0,0),x3(thick,0,-thick),x4(0,0,-thick);

	foodTable fd(i1,i2,i3,i4,x1,x2,x3,x4,width,hight,thick,chairWood,chairFabric);

	if(keys['V']){
		foodTableZ=-2;
	}
	if(keys['B']){
		foodTableZ=0;
	}

	fd.draw(foodTableX,foodTableY,foodTableZ);

	glPopMatrix();
	///////////////////////////////////////////////////////////////////////////////

*/