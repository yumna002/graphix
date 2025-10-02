#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"
#include "chair.h"
#include "trailer.h"

class sittingRoom
{
public:
	int trainColor,trainGlass,trainDoor,trainFloor,trainInside,chairFabric,chairWood;
	color c;
	point P1,P2,P3,P4,P5,P6,P7,P8;
	point p1,p2,p3,p4,p5,p6,p7,p8;
	trailer room;
	point x1,x2,x3,x4;
	chair ch1;

	sittingRoom(void);
	
	sittingRoom(point P1,point P2,point P3,point P4,point P5,point P6,point P7,point P8,
		point p1,point p2,point p3,point p4,point p5,point p6,point p7,point p8,point x1,point x2,point x3,point x4,color c,
		int trainColor,int trainGlass,int trainDoor,int trainFloor,int trainInside,int chairFabric,int chairWood);
	
	void draw(float doorX,float doorY,float doorZ);
	
	bool in_collision(float minX,float maxX,float minZ,float maxZ,point cam);
	bool out_collision(float minX,float maxX,float minZ,float maxZ,point cam);
	bool sittingRoomCollision(point cam,point tranz,bool openDoor);

	~sittingRoom(void);
};

/*
/////////////////////////////drawing sitting room in main
	glPushMatrix();
	
	point P1(0,0,0),P2(15,0,0),P3(15,10,0),P4(0,10,0),P5(0,0,-40),P6(15,0,-40),P7(15,10,-40),P8(0,10,-40);
	color c(0,0,1);
	point p1(6,0,0),p2(10,0,0),p3(10,6,0),p4(6,6,0),p5(15,4,-8),p6(15,4,-12),p7(15,8,-12),p8(15,8,-8);
	point x1(0,0,0),x2(4,0,0),x3(4,0,-2.7),x4(0,0,-2.7);

	sittingRoom SITTING_ROOM(P1,P2,P3,P4,P5,P6,P7,P8,p1,p2,p3,p4,p5,p6,p7,p8,x1,x2,x3,x4,c,
		trainColor,trainGlass,trainDoor,trainFloor,trainInside,chairFabric,chairWood);
	
	if(keys['N']){
		doorX=4; openDoor=true;
	}
	if(keys['M']){
		doorX=0; openDoor=false;
	}

	SITTING_ROOM.draw(doorX,doorY,doorZ);

	glPopMatrix();
	//////////////////////////////////////////////////
*/