#include "bedRoom.h"
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
#include "bed.h"

bedRoom::bedRoom(void)
{
}

bedRoom::bedRoom(point P1,point P2,point P3,point P4,point P5,point P6,point P7,point P8,
		point p1,point p2,point p3,point p4,point p5,point p6,point p7,point p8,point x1,point x2,point x3,point x4,color c,
		int trainColor,int bed_trainGlass,int trainDoor,int bed_trainFloor,int bed_trainInside,int bedWood,int bedSleep,
		int bedHead,int bedMirror,
		float hight,float width,float thick,point i1,point i2,point i3,point i4)
{
	this->P1=P1; this->P2=P2; this->P3=P3; this->P3=P3; this->P4=P4; this->P5=P5; this->P6=P6; this->P7=P7; this->P8=P8;
	this->p1=p1; this->p2=p2; this->p3=p3; this->p3=p3; this->p4=p4; this->p5=p5; this->p6=p6; this->p7=p7; this->p8=p8;
	this->x1=x1; this->x2=x2; this->x3=x3; this->x3=x3; this->x4=x4;
	this->c=c;
	this->trainColor=trainColor; this->bed_trainInside=bed_trainInside; this->trainDoor=trainDoor;
	this->bed_trainFloor=bed_trainFloor; this->bed_trainGlass=bed_trainGlass; this->bedSleep=bedSleep;
	this->bedWood=bedWood; this->bedHead=bedHead; this->bedMirror=bedMirror;
	this->hight=hight; this->width=width; this->thick=thick;
	this->i1=i1; this->i2=i2; this->i3=i3; this->i3=i3; this->i4=i4;

	trailer room(P1,P2,P3,P4,P5,P6,P7,P8,trainColor,bed_trainInside,bed_trainGlass,bed_trainFloor,trainDoor,c);
	this->room=room;
	bed b(x1,x2,x3,x4,hight,width,thick,bedWood,bedSleep,bedHead);
	this->b=b;
	cube mirror(i1,i2,i3,i4,8,bedMirror);
	this->mirror=mirror;
}

void bedRoom::draw(float doorX,float doorY,float doorZ)
{
	glPushMatrix();


	///////////////////////////////////////////////////////////draw beds
	glPushMatrix();

	//first pair of beds
	glPushMatrix();
	glTranslated(0,0,-8);
	b.draw_pair(b);
	glPopMatrix();

	//second pair of beds
	glPushMatrix();
	glTranslated(0,0,-18);
	b.draw_pair(b);
	glPopMatrix();

	//third pair of beds
	glPushMatrix();
	glTranslated(0,0,-28);
	b.draw_pair(b);
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////draw decoration
	glPushMatrix();

	glPushMatrix();
	glTranslated(2,0,-34);
	mirror.draw();
	glPopMatrix();

	glPopMatrix();
	////////////////////////////////////////////////////////////////////


	/////////////////////////////////////////////////////////drawing trailer
	glPushMatrix();
	room.draw3(p1,p2,p3,p4,p5,p6,p7,p8,doorX,doorY,doorZ);
	glPopMatrix();
	/////////////////////////////////////////////////////////////////////////


	glPopMatrix();
}

bool bedRoom::bedRoomCollision(point cam,point tranz,bool openDoor)
{
	bool ok=false;

	// check collision with sitting trailer inside ans door
	if(in_collision(tranz.x+(0),tranz.x+(15),tranz.z+(-40),tranz.z+(0),cam) & ( ( (cam.x>=6&&cam.x<=10 && (cam.z>tranz.z+(0)&&!openDoor)) || (cam.x>=6&&cam.x<=10 && (cam.z<tranz.z+(-40)&&!openDoor)) ) || !openDoor ) )
		ok=true;
	
	// check collision with beds
	//bed 1
	if(out_collision(tranz.x+(0.5),tranz.x+(8.5),tranz.z+(-7),tranz.z+(-3),cam))
		ok=true;
	//bed 2
	if(out_collision(tranz.x+(0.5),tranz.x+(8.5),tranz.z+(-17),tranz.z+(-13),cam))
		ok=true;
	//bed 3
	if(out_collision(tranz.x+(0.5),tranz.x+(8.5),tranz.z+(-27),tranz.z+(-23),cam))
		ok=true;

	//check collision with mirror
	if(out_collision(tranz.x+(1),tranz.x+(6),tranz.z+(-38),tranz.z+(-34),cam))
		ok=true;

	return ok;
}

bool bedRoom::in_collision(float minX,float maxX,float minZ,float maxZ,point cam)
{
	if(cam.x>=minX && cam.x<=maxX && cam.z<=maxZ && cam.z>=minZ)
		return false;
	else
		return true;
}

bool bedRoom::out_collision(float minX,float maxX,float minZ,float maxZ,point cam)
{
	if(cam.x>=minX&&cam.x<=maxX){
		if(cam.z>=maxZ || cam.z<=minZ)
			return false;
		else return true;
	}
	return false;
}

bedRoom::~bedRoom(void)
{
}
