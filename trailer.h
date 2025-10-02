#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"

class trailer
{
public:
	point P1,P2,P3,P4,P5,P6,P7,P8;
	int trainColor,trainInside,trainGlass,trainFloor,trainDoor;
	color c;

	trailer(void);
	
	trailer(point p1,point p2,point p3,point p4,point p5,point p6,point p7,point p8,int traincolor,int traininside,int trainglass,int trainfloor,int traindoor,color cc);

	void draw(point p1,point p2,point p3,point p4,point p5,point p6,point p7,point p8,float doorX,float doorY,float doorZ);
	void draw2(point p1,point p2,point p3,point p4,float doorX,float doorY,float doorZ);
	void draw3(point p1,point p2,point p3,point p4,point p5,point p6,point p7,point p8,float doorX,float doorY,float doorZ);

	void draw_head(point p1,point p2,point p3,point p4,float hight,float width,float doorX,float doorY,float doorZ,int controllTable,int controllTableSide,int trainChimney);

	bool in_collision(float minX,float maxX,float minZ,float maxZ,point cam);
	bool out_collision(float minX,float maxX,float minZ,float maxZ,point cam);
	bool headRoomCollision(point cam,point tranz,bool openDoor);

	~trailer(void);
};


/*
point P1(0,0,0),P2(15,0,0),P3(15,10,0),P4(0,10,0),P5(0,0,-40),P6(15,0,-40),P7(15,10,-40),P8(0,10,-40);
	color c(0,0,1);
	point p1(6,0,0),p2(10,0,0),p3(10,6,0),p4(6,6,0),p5(15,4,-8),p6(15,4,-12),p7(15,8,-12),p8(15,8,-8);

	trailer room(P1,P2,P3,P4,P5,P6,P7,P8,trainColor,trainInside,trainGlass,trainFloor,trainDoor,c);
	room.draw(p1,p2,p3,p4,p5,p6,p7,p8,doorX,doorY,doorZ);
*/


/*
//////////////////////////////////////////////////////////////////////////////////////drawing train head
	glPushMatrix();

	color c(0,0,1);
	point P1(0,0,0),P2(15,0,0),P3(15,10,0),P4(0,10,0),P5(0,0,-15),P6(15,0,-15),P7(15,10,-15),P8(0,10,-15);
	trailer HEAD_ROOM(P1,P2,P3,P4,P5,P6,P7,P8,trainColor,trainInside,trainGlass,trainFloor,trainDoor,c);
	//point p1(P2.x+0.1,0,-4),p2(p1.x+0.2,0,-4),p3(p1.x+0.2,0,-8),p4(P2.x+0.2,0,-8);
	point p1(6,0,0),p2(10,0,0),p3(10,6,0),p4(6,6,0);
	float hight=5,width=4;
	
	if(keys['N']){
		doorZ=-3; openDoor=true;
	}
	if(keys['M']){
		doorZ=0; openDoor=false;
	}

	if(keys['Y']){
		PlaySound("train_horn_sound.wav",NULL,SND_ASYNC);
	}
	
	HEAD_ROOM.draw_head(p1,p2,p3,p4,hight,width,doorX,doorY,doorZ,controllTable,controllTableSide,trainColor);

	glPopMatrix();
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
*/