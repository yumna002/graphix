#include "eatingRoom.h"
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
#include "chair2.h"

eatingRoom::eatingRoom(void)
{
}


eatingRoom::eatingRoom(point P1,point P2,point P3,point P4,point P5,point P6,point P7,point P8,
		point p1,point p2,point p3,point p4,color c,
		point x1,point x2,point x3,point x4,point i1,point i2,point i3,point i4,point z1,point z2,point z3,point z4,
		int trainColor,int trainGlass,int trainDoor,int food_trainFloor,int food_trainInside,int foodTableWood,int foodTableFabric,
		int food_wallDec,
		float hight,float width,float thick,float hi,float wi,float thi)
{
	this->P1=P1; this->P2=P2; this->P3=P3; this->P3=P3; this->P4=P4; this->P5=P5; this->P6=P6; this->P7=P7; this->P8=P8;
	this->p1=p1; this->p2=p2; this->p3=p3; this->p3=p3; this->p4=p4; this->x1=x1; this->x2=x2; this->x3=x3; this->x4=x4;
	this->i1=i1; this->i2=i2; this->i3=i3; this->i3=i3; this->i4=i4; 
	this->z1=z1; this->z2=z2; this->z3=z3; this->z3=z3; this->z4=z4;
	this->c=c;
	this->trainColor=trainColor; this->food_trainInside=food_trainInside; this->trainDoor=trainDoor;
	this->food_trainFloor=food_trainFloor; this->trainGlass=trainGlass; this->foodTableWood=foodTableWood;
	this->foodTableFabric=foodTableFabric; this->food_wallDec=food_wallDec;
	this->hight=hight; this->width=width; this->thick=thick;
	this->hi=hi; this->wi=wi; this->thi=thi;

	trailer room(P1,P2,P3,P4,P5,P6,P7,P8,trainColor,food_trainInside,trainGlass,food_trainFloor,trainDoor,c);
	this->room=room;
	foodTable fd(i1,i2,i3,i4,x1,x2,x3,x4,width,hight,thick,foodTableWood,foodTableFabric);
	this->fd=fd;
	cube portraite(z1,z2,z3,z4,hi,food_wallDec);
	this->portraite=portraite;
}

void eatingRoom::draw(float doorX,float doorY,float doorZ,float foodTableX,float foodTableY,float foodTableZ)
{


	//////////////////////////////////////////draw the trailer
	glPushMatrix();
	room.draw2(p1,p2,p3,p4,doorX,doorY,doorZ);
	glPopMatrix();
	/////////////////////////////////////////////////////////



	/////////////////////////////////////////////////drawing foodTables
	glPushMatrix();

	//drawing first table
	glPushMatrix();
	fd.draw(foodTableX,foodTableY,foodTableZ);
	glPopMatrix();

	//drawing second table
	glPushMatrix();
	glTranslated(0,0,-25);
	glScaled(1,0.8,1);
	fd.draw(foodTableX,foodTableY,foodTableZ);
	glPopMatrix();

	//drawing third table
	glPushMatrix();
	glTranslated(8.5,0,-15);
	glScaled(1,0.6,1);
	fd.draw(foodTableX,foodTableY,foodTableZ);
	glPopMatrix();

	glPopMatrix();
	//////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////drawing decoration
	glPushMatrix();

	//draw first pic
	glPushMatrix();
	glTranslated(0.2,5,-17);
	portraite.draw();
	glPopMatrix();

	//draw second pic
	glPushMatrix();
	glTranslated(14.6,5,-30);
	portraite.draw();
	glPopMatrix();

	glPopMatrix();
	/////////////////////////////////////////////////////////////////////

}

bool eatingRoom::eatingRoomCollision(point cam,point tranz,bool openDoor)
{
	bool ok=false;

	// check collision with sitting trailer inside ans door
	if(in_collision(tranz.x+(0),tranz.x+(15),tranz.z+(-40),tranz.z+(0),cam) & ( ( (cam.x>=6&&cam.x<=10 && (cam.z>tranz.z+(0)&&!openDoor)) || (cam.x>=6&&cam.x<=10 && (cam.z<tranz.z+(-40)&&!openDoor)) ) || !openDoor ) )
		ok=true;
	
	// check collision with tables 
	// table 1
	if(out_collision(tranz.x+(0.5),tranz.x+(6),tranz.z+(-13),tranz.z+(-1),cam))
		ok=true;
	// table 2
	if(out_collision(tranz.x+(8),tranz.x+(14.5),tranz.z+(-27),tranz.z+(-17),cam))
		ok=true;
	// table 3
	if(out_collision(tranz.x+(0.5),tranz.x+(6.3),tranz.z+(-37.5),tranz.z+(-27),cam))
		ok=true;
	
	return ok;
}

bool eatingRoom::in_collision(float minX,float maxX,float minZ,float maxZ,point cam)
{
	if(cam.x>=minX && cam.x<=maxX && cam.z<=maxZ && cam.z>=minZ)
		return false;
	else
		return true;
}

bool eatingRoom::out_collision(float minX,float maxX,float minZ,float maxZ,point cam)
{
	if(cam.x>=minX&&cam.x<=maxX){
		if(cam.z>=maxZ || cam.z<=minZ)
			return false;
		else return true;
	}
	return false;
}

eatingRoom::~eatingRoom(void)
{
}
