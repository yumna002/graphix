#include "cinemaRoom.h"
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
#include "chair2.h"

cinemaRoom::cinemaRoom(void)
{
}

cinemaRoom::cinemaRoom(point P1,point P2,point P3,point P4,point P5,point P6,point P7,point P8,
		point p1,point p2,point p3,point p4,point x1,point x2,point x3,point x4,color c,
		int trainColor,int trainGlass,int trainDoor,int trainFloor,int trainInside,int chairFabric,int chairWood,int tv_screen,
		int tv_screen2,
		float hight,float width,float thick,point i1,point i2,point i3,point i4)
{
	this->P1=P1; this->P2=P2; this->P3=P3; this->P3=P3; this->P4=P4; this->P5=P5; this->P6=P6; this->P7=P7; this->P8=P8;
	this->p1=p1; this->p2=p2; this->p3=p3; this->p3=p3; this->p4=p4;
	this->x1=x1; this->x2=x2; this->x3=x3; this->x3=x3; this->x4=x4;
	this->c=c;
	this->trainColor=trainColor; this->trainInside=trainInside; this->trainDoor=trainDoor;
	this->trainFloor=trainFloor; this->trainGlass=trainGlass; this->chairFabric=chairFabric;
	this->chairWood=chairWood; this->tv_screen=tv_screen; this->tv_screen2=tv_screen2;
	this->hight=hight; this->width=width; this->thick=thick;
	this->i1=i1; this->i2=i2; this->i3=i3; this->i3=i3; this->i4=i4;

	trailer room(P1,P2,P3,P4,P5,P6,P7,P8,trainColor,trainInside,trainGlass,trainFloor,trainDoor,c);
	this->room=room;
	chair2 ch(x1,x2,x3,x4,hight,width,thick,chairFabric,chairWood);
	this->ch=ch;
	cube tv(i1,i2,i3,i4,6.7,tv_screen);
	this->tv=tv;
	cube tv2(i1,i2,i3,i4,6.7,tv_screen2);
	this->tv2=tv2;
}

void cinemaRoom::draw(float doorX,float doorY,float doorZ,float TV)
{
	glPushMatrix();

	/////////////////////////////////////////drawing trailer 
	glPushMatrix();
	glColor3f(1,1,1);

	room.draw2(p1,p2,p3,p4,doorX,doorY,doorZ);

	glPopMatrix();
	////////////////////////////////////////////////////////



	/////////////////////////////////////////draw cinema chairs 
	glPushMatrix();
	glColor3f(1,1,1);

	//first pair of cinema chairs
	glPushMatrix();
	ch.draw_pair(ch);
	glPopMatrix();

	//second pair of cinema chairs
	glPushMatrix();
	glTranslated(0,0,-5.7);
	ch.draw_pair(ch);
	glPopMatrix();

	//thrid pair of cinema chairs
	glPushMatrix();
	glTranslated(0,0,-10.7);
	ch.draw_pair(ch);
	glPopMatrix();

	//fourth pair of cinema chairs
	glPushMatrix();
	glTranslated(0,0,-15.7);
	ch.draw_pair(ch);
	glPopMatrix();

	//fifth pair of cinema chairs
	glPushMatrix();
	glTranslated(0,0,-20.7);
	ch.draw_pair(ch);
	glPopMatrix();

	//sixth pair of cinema chairs
	glPushMatrix();
	glTranslated(0,0,-25.7);
	ch.draw_pair(ch);
	glPopMatrix();

	//seventh pair of cinema chairs
	glPushMatrix();
	glTranslated(0,0,-30);
	ch.draw_pair(ch);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////



	///////////////////////////////////////////////////draw tv screen
	glPushMatrix();

	glPushMatrix();
	glTranslated(14.6,2.5,-7.5);
	if(TV==1)
		tv.draw();
	else 
		tv2.draw();
	glPopMatrix();

	glPopMatrix();
	/////////////////////////////////////////////////////////////////

	glPopMatrix();
}

bool cinemaRoom::cinemaRoomCollision(point cam,point tranz,bool openDoor)
{
	bool ok=false;

	// check collision with sitting trailer inside ans door
	if(in_collision(tranz.x+(0),tranz.x+(15),tranz.z+(-40),tranz.z+(0),cam) & ( ( (cam.x>=6&&cam.x<=10 && (cam.z>tranz.z+(0)&&!openDoor)) || (cam.x>=6&&cam.x<=10 && (cam.z<tranz.z+(-40)&&!openDoor)) ) || !openDoor ) )
		ok=true;
	
	// check collision with chairs
	// chair line 1
	if(out_collision(tranz.x+(0.5),tranz.x+(3),tranz.z+(-37),tranz.z+(-2),cam))
		ok=true;
	// chair line 2
	if(out_collision(tranz.x+(4.5),tranz.x+(8.5),tranz.z+(-37),tranz.z+(-2),cam))
		ok=true;
	
	return ok;
}

bool cinemaRoom::in_collision(float minX,float maxX,float minZ,float maxZ,point cam)
{
	if(cam.x>=minX && cam.x<=maxX && cam.z<=maxZ && cam.z>=minZ)
		return false;
	else
		return true;
}

bool cinemaRoom::out_collision(float minX,float maxX,float minZ,float maxZ,point cam)
{
	if(cam.x>=minX&&cam.x<=maxX){
		if(cam.z>=maxZ || cam.z<=minZ)
			return false;
		else return true;
	}
	return false;
}

cinemaRoom::~cinemaRoom(void)
{
}
