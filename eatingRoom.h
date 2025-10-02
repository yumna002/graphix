#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"
#include "chair2.h"
#include "trailer.h"
#include "foodTable.h"

class eatingRoom
{
public:
	int trainColor,trainGlass,trainDoor,food_trainFloor,food_trainInside,foodTableFabric,foodTableWood,food_wallDec;
	color c;
	point P1,P2,P3,P4,P5,P6,P7,P8;
	point p1,p2,p3,p4;
	trailer room;
	point x1,x2,x3,x4,i1,i2,i3,i4,z1,z2,z3,z4;
	foodTable fd;
	float hight,width,thick,hi,wi,thi;
	cube portraite;

	eatingRoom(void);
	
	eatingRoom(point P1,point P2,point P3,point P4,point P5,point P6,point P7,point P8,
		point p1,point p2,point p3,point p4,color c,
		point x1,point x2,point x3,point x4,point i1,point i2,point i3,point i4,point z1,point z2,point z3,point z4,
		int trainColor,int trainGlass,int trainDoor,int food_trainFloor,int food_trainInside,int foodTableWood,int foodTableFabric,
		int food_wallDec,
		float hight,float width,float thick,float hi,float wi,float thi);
	
	void draw(float doorX,float doorY,float doorZ,float foodTableX,float foodTableY,float foodTableZ);
	
	
	bool in_collision(float minX,float maxX,float minZ,float maxZ,point cam);
	bool out_collision(float minX,float maxX,float minZ,float maxZ,point cam);
	bool eatingRoomCollision(point cam,point tranz,bool openDoor);

	~eatingRoom(void);
};


/*

	/////////////////////////////////////////////////////////////draw eating room
	glPushMatrix();

	point P1(0,0,0),P2(15,0,0),P3(15,10,0),P4(0,10,0),P5(0,0,-40),P6(15,0,-40),P7(15,10,-40),P8(0,10,-40);
	color c(0,0,1);
	point p1(6,0,0),p2(10,0,0),p3(10,6,0),p4(6,6,0);
	float width=1.4,hight=3.4,thick=0.3;
	point i1(0,0,0),i2(thick,0,0),i3(thick,0,-thick),i4(0,0,-thick);
	point x1(0,0,0),x2(thick,0,0),x3(thick,0,-thick),x4(0,0,-thick);
	float hi=4,thi=0.2,wi=5;
	point z1(0,0,0),z2(thi,0,0),z3(thi,0,-wi),z4(0,0,-wi);

	eatingRoom EATING_ROOM(P1,P2,P3,P4,P5,P6,P7,P8,
		p1,p2,p3,p4,c,
		x1,x2,x3,x4,i1,i2,i3,i4,z1,z2,z3,z4,
		trainColor,trainGlass,trainDoor,food_trainFloor,food_trainInside,foodTableWood,foodTableFabric,food_wallDec,
		hight,width,thick,hi,wi,thi);

	if(keys['N']){
		doorX=4; openDoor=true;
	}
	if(keys['M']){
		doorX=0; openDoor=false;
	}

	if(keys['V']){
		foodTableZ=-2;
	}
	if(keys['B']){
		foodTableZ=0;
	}

	EATING_ROOM.draw(doorX,doorY,doorZ,foodTableX,foodTableY,foodTableZ);

	glPopMatrix();
	//////////////////////////////////////////////////////////////////////////////

*/