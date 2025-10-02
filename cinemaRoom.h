#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"
#include "chair2.h"
#include "trailer.h"

class cinemaRoom
{
public:
	int trainColor,trainGlass,trainDoor,trainFloor,trainInside,chairFabric,chairWood,tv_screen,tv_screen2;
	color c;
	point P1,P2,P3,P4,P5,P6,P7,P8;
	point p1,p2,p3,p4;
	trailer room;
	point x1,x2,x3,x4,i1,i2,i3,i4;
	chair2 ch;
	float hight,width,thick;
	cube tv,tv2;
	
	cinemaRoom(void);
	
	cinemaRoom(point P1,point P2,point P3,point P4,point P5,point P6,point P7,point P8,
		point p1,point p2,point p3,point p4,point x1,point x2,point x3,point x4,color c,
		int trainColor,int trainGlass,int trainDoor,int trainFloor,int trainInside,int chairFabric,int chairWood,int tv_screen,
		int tv_screen2,
		float hight,float width,float thick,point i1,point i2,point i3,point i4);
	
	void draw(float doorX,float doorY,float doorZ,float TV);

	bool in_collision(float minX,float maxX,float minZ,float maxZ,point cam);
	bool out_collision(float minX,float maxX,float minZ,float maxZ,point cam);
	bool cinemaRoomCollision(point cam,point tranz,bool openDoor);

	~cinemaRoom(void);
};


/*

	//////////////////////////////////////////////draw cinema room
	glPushMatrix();

	point P1(0,0,0),P2(15,0,0),P3(15,10,0),P4(0,10,0),P5(0,0,-40),P6(15,0,-40),P7(15,10,-40),P8(0,10,-40);
	color c(0,0,1);
	point p1(9,0,0),p2(12.5,0,0),p3(12.5,6,0),p4(9,6,0);

	float width=3.2,hight=2.1,thick=0.3;
	point x1(0,0,0),x2(thick,0,0),x3(thick,0,-thick),x4(0,0,-thick);

	point i1(0,0,0),i2(0.3,0,0),i3(0.3,0,-25),i4(0,0,-25);

	cinemaRoom CINEMA_ROOM(P1,P2,P3,P4,P5,P6,P7,P8,p1,p2,p3,p4,x1,x2,x3,x4,c,
		trainColor,trainGlass,trainDoor,cinema_trainFloor,cinema_trainInside,cinema_chairFabric,cinema_chairWood,tv,tv2,
		hight,width,thick,i1,i2,i3,i4);

	if(keys['N']){
		doorX=2.8; openDoor=true;
	}
	if(keys['M']){
		doorX=0; openDoor=false;
	}

	if(keys['J']){
		TV=2;
	}
	if(keys['K']){
		TV=1;
	}
	
	CINEMA_ROOM.draw(doorX,doorY,doorZ,TV);

	glPopMatrix();
	//////////////////////////////////////////////////////////////

*/