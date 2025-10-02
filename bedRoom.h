#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"
#include "bed.h"
#include "trailer.h"

class bedRoom
{
public:
	int trainColor,bed_trainGlass,trainDoor,bed_trainFloor,bed_trainInside,bedMirror,bedSleep,bedHead,bedWood;
	color c;
	point P1,P2,P3,P4,P5,P6,P7,P8;
	point p1,p2,p3,p4,p5,p6,p7,p8;
	trailer room;
	point x1,x2,x3,x4,i1,i2,i3,i4;
	bed b;
	float hight,width,thick;
	cube mirror;

	bedRoom(void);
	
	bedRoom(point P1,point P2,point P3,point P4,point P5,point P6,point P7,point P8,
		point p1,point p2,point p3,point p4,point p5,point p6,point p7,point p8,point x1,point x2,point x3,point x4,color c,
		int trainColor,int bed_trainGlass,int trainDoor,int bed_trainFloor,int bed_trainInside,int bedWood,int bedSleep,
		int bedHead,int bedMirror,
		float hight,float width,float thick,point i1,point i2,point i3,point i4);
	
	void draw(float doorX,float doorY,float doorZ);

	bool in_collision(float minX,float maxX,float minZ,float maxZ,point cam);
	bool out_collision(float minX,float maxX,float minZ,float maxZ,point cam);
	bool bedRoomCollision(point cam,point tranz,bool openDoor);
	
	~bedRoom(void);
};


/*
/////////////////////////////////////////////////////////////draw bedRoom
	glPushMatrix();

	point P1(0,0,0),P2(15,0,0),P3(15,10,0),P4(0,10,0),P5(0,0,-40),P6(15,0,-40),P7(15,10,-40),P8(0,10,-40);
	color c(0,0,1);
	point p1(9,0,0),p2(12.5,0,0),p3(12.5,6,0),p4(9,6,0),p5(15,4,-8),p6(15,4,-12),p7(15,8,-12),p8(15,8,-8);
	float hight=2.2,width=7.5,thick=0.2;
	point x1(0,0,0),x2(width,0,0),x3(width,0,-3.8),x4(0,0,-3.8);
	point i1(0,0,0),i2(4,0,-4),i3(3.9,0,-4.1),i4(0.1,0,-0.1);

	bedRoom BED_ROOM(P1,P2,P3,P4,P5,P6,P7,P8, p1,p2,p3,p4,p5,p6,p7,p8,x1,x2,x3,x4,c,
		trainColor,bed_trainGlass,trainDoor,bed_trainFloor,bed_trainInside,bedWood,bedSleep,bedHead,bedMirror,
		hight,width,thick,i1,i2,i3,i4);

	if(keys['N']){
		doorX=2.8; openDoor=true;
	}
	if(keys['M']){
		doorX=0; openDoor=false;
	}

	BED_ROOM.draw(doorX,doorY,doorZ);

	glPopMatrix();
	/////////////////////////////////////////////////////////////////////////

*/