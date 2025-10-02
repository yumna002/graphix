#include "sittingRoom.h"
#include "trailer.h"
#include "skybox.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "point.h"
#include "color.h"
#include "cube.h"
#include "door.h"
#include "chair.h"


sittingRoom::sittingRoom(void)
{
}

sittingRoom::sittingRoom(point P1,point P2,point P3,point P4,point P5,point P6,point P7,point P8,
		point p1,point p2,point p3,point p4,point p5,point p6,point p7,point p8,point x1,point x2,point x3,point x4,color c,
		int trainColor,int trainGlass,int trainDoor,int trainFloor,int trainInside,int chairFabric,int chairWood)
{
	this->P1=P1; this->P2=P2; this->P3=P3; this->P3=P3; this->P4=P4; this->P5=P5; this->P6=P6; this->P7=P7; this->P8=P8;
	this->p1=p1; this->p2=p2; this->p3=p3; this->p3=p3; this->p4=p4; this->p5=p5; this->p6=p6; this->p7=p7; this->p8=p8;
	this->x1=x1; this->x2=x2; this->x3=x3; this->x3=x3; this->x4=x4;
	this->c=c;
	this->trainColor=trainColor; this->trainInside=trainInside; this->trainDoor=trainDoor;
	this->trainFloor=trainFloor; this->trainGlass=trainGlass; this->chairFabric=chairFabric;
	this->chairWood=chairWood;
	trailer room(P1,P2,P3,P4,P5,P6,P7,P8,trainColor,trainInside,trainGlass,trainFloor,trainDoor,c);
	this->room=room;
	chair ch1(x1,x2,x3,x4,2.5,chairFabric,chairWood);
	this->ch1=ch1;
}

void sittingRoom::draw(float doorX,float doorY,float doorZ)
{
	/////////////////////////////////////////drawing sitting room 
	glPushMatrix();
	glColor3f(1,1,1);
	
	//////////////////////////////////draw sitting room chairs
	glPushMatrix();
	
	//draw left chairs
	glPushMatrix();
	glTranslated(1,0,-35.5);
	ch1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1,0,-24.5);
	ch1.draw_pair(ch1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(1,0,-12.5);
	ch1.draw_pair(ch1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,-0.9);
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(-5.5,0,7);
	ch1.draw();
	glPopMatrix();
	glPopMatrix();


	//draw right chairs
	glPushMatrix();
	glTranslated(9,0,0);

	glPushMatrix();
	glTranslated(1,0,-35.5);
	ch1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1,0,-24.5);
	ch1.draw_pair(ch1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(1,0,-12.5);
	ch1.draw_pair(ch1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,-0.9);
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(-5.5,0,7);
	ch1.draw();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	/////////////////////////////////////////drawing trailer
	room.draw(p1,p2,p3,p4,p5,p6,p7,p8,doorX,doorY,doorZ);

	glPopMatrix();
	///////////////////////////////////////////////////////////
	

}

bool sittingRoom::sittingRoomCollision(point cam,point tranz,bool openDoor)
{
	bool ok=false;

	// check collision with sitting trailer inside ans door
	if(in_collision(tranz.x+(0),tranz.x+(15),tranz.z+(-40),tranz.z+(0),cam) & ( ( (cam.x>=6&&cam.x<=10 && (cam.z>tranz.z+(0)&&!openDoor)) || (cam.x>=6&&cam.x<=10 && (cam.z<tranz.z+(-40)&&!openDoor)) ) || !openDoor ) )
		ok=true;
	
	// check collision with sitting chairs from back to front
	//chair 1 left
	if(out_collision(tranz.x+(1),tranz.x+(6),tranz.z+(-6.5),tranz.z+(-1.5),cam))
		ok=true;
	//chair 2 left
	if(out_collision(tranz.x+(1),tranz.x+(6),tranz.z+(-19.5),tranz.z+(-10),cam))
		ok=true;
	//chair 3 left
	if(out_collision(tranz.x+(1),tranz.x+(6),tranz.z+(-30),tranz.z+(-24),cam))
		ok=true;
	//chair 4 left
	if(out_collision(tranz.x+(1),tranz.x+(6),tranz.z+(-38),tranz.z+(-34),cam))
		ok=true;
	//chair 1 right
	if(out_collision(tranz.x+(9.5),tranz.x+(14.4),tranz.z+(-6.5),tranz.z+(-1.5),cam))
		ok=true;
	//chair 2 right
	if(out_collision(tranz.x+(9.5),tranz.x+(14.4),tranz.z+(-19.5),tranz.z+(-10),cam))
		ok=true;
	//chair 3 right
	if(out_collision(tranz.x+(9.5),tranz.x+(14.4),tranz.z+(-30),tranz.z+(-24),cam))
		ok=true;
	//chair 4 right
	if(out_collision(tranz.x+(9.5),tranz.x+(14.4),tranz.z+(-38),tranz.z+(-34),cam))
		ok=true;

	return ok;
}

bool sittingRoom::in_collision(float minX,float maxX,float minZ,float maxZ,point cam)
{
	if(cam.x>=minX && cam.x<=maxX && cam.z<=maxZ && cam.z>=minZ)
		return false;
	else
		return true;
}

bool sittingRoom::out_collision(float minX,float maxX,float minZ,float maxZ,point cam)
{
	if(cam.x>=minX&&cam.x<=maxX){
		if(cam.z>=maxZ || cam.z<=minZ)
			return false;
		else return true;
	}
	return false;
}

sittingRoom::~sittingRoom(void)
{
}
