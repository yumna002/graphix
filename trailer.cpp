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

trailer::trailer(void)
{
}

trailer::trailer(point p1,point p2,point p3,point p4,point p5,point p6,point p7,point p8,int traincolor,int traininside,int trainglass,int trainfloor,int traindoor,color cc)
{
	trainColor=traincolor; trainInside=traininside; trainGlass=trainglass; trainFloor=trainfloor; trainDoor=traindoor; c=cc;
	P1=p1; P2=p2; P3=p3; P4=p4; P5=p5; P6=p6; P7=p7; P8=p8;	
}

void trailer::draw(point p1,point p2,point p3,point p4,point p5,point p6,point p7,point p8,float doorX,float doorY,float doorZ)
{
	point p44=p4,p33=p3;
	p44.y=P4.y; p33.y=P3.y;

	point p55=p5,p66=p6,p77=p7,p88=p8;
	p55.y=P2.y; p66.y=P5.y;
	p77.y=P3.y; p88.y=P3.y;



	// front side
	glPushMatrix();
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glPopMatrix();



	//back side
	glPushMatrix();
	glTranslated(0,0,P5.z);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();
	
	glDisable(GL_CULL_FACE);

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();
	
	glDisable(GL_CULL_FACE);

	glPopMatrix();



	// top side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P4.x,P4.y,P4.z);
	glTexCoord2d(1, 0);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P4.x,P4.y,P4.z);
	glTexCoord2d(1, 0);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glPopMatrix();



	// down side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainFloor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(0, 1);
	glVertex3d(P5.x,P5.y,P5.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);

	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(0, 1);
	glVertex3d(P5.x,P5.y,P5.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glPopMatrix();


	
	//right side
	glPushMatrix();

	//draw right walls
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	float add=P6.z-3*p6.z;
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z+3*p6.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,P2.z+3*p6.z+add);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,P2.z+3*p6.z+add);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P2.z+3*p6.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	add=P6.z-3*p6.z;
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z+3*p6.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,P2.z+3*p6.z+add);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,P2.z+3*p6.z+add);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P2.z+3*p6.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glDisable(GL_CULL_FACE);
	
	glPopMatrix();

	
	//left side

	//draw left walls
	glPushMatrix();
	glTranslated(-(P2.x-P1.x),0,0);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	add=P6.z-3*p6.z;
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z+3*p6.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,P2.z+3*p6.z+add);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,P2.z+3*p6.z+add);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P2.z+3*p6.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glDisable(GL_CULL_FACE);
	
	glPopMatrix();

	glPushMatrix();
	glTranslated(-(P2.x-P1.x),0,0);

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	add=P6.z-3*p6.z;
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z+3*p6.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,P2.z+3*p6.z+add);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,P2.z+3*p6.z+add);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P2.z+3*p6.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glDisable(GL_CULL_FACE);
	
	glPopMatrix();


	//draw trailer doors
	glPushMatrix();

	////////////////drawing trailer doors and interactions
	glPushMatrix();
	glTranslated(doorX,doorY,doorZ);

	//draw trailer door front
	glPushMatrix();
	point i1=p1,i2=p2,i3=p2,i4=p1;
	i1.z+=0.4; i2.z+=0.4; i3.z+=0.1; i4.z+=0.1;
	door d(i1,i2,i3,i4,p3.y,trainDoor);
	d.draw();
	glPopMatrix();

	//draw trailer door back
	glPushMatrix();
	glTranslated(0,0,P5.z-0.5);
	d.draw();
	glPopMatrix();
	
	glColor3f(1,1,1);
	glPopMatrix();
	/////////////////////////////////////////////////////////

	glPopMatrix();
	/////////////////////////////////////////////


	//draw trailer circles
	glPushMatrix();
	glColor3f(1,1,1);

	//draw front left circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-1,0,0);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw front right circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-1,0,-15.1);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw back right circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-39,0,0);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw back left circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-39,0,-15);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	glColor3f(1,1,1);
	glPopMatrix();



	//draw train joining line
	glPushMatrix();
	glColor3f(1,1,1);
	
	point x1=p1,x2=p2;
	x1.z+=3.3; x2.z+=3.3;
	cube l(x1,x2,p2,p1,0.1,0);
	l.draw_with_color(c);
	
	glColor3f(1,1,1);
	glPopMatrix();


	//draw right window
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainGlass);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainGlass);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainGlass);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();
	glPopMatrix();


	//draw left window
	glPushMatrix();
	glTranslated(-(P2.x-P1.x),0,0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainGlass);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainGlass);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainGlass);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();
	glPopMatrix();
	
	glPopMatrix();


	glPopMatrix();
}

void trailer::draw2(point p1,point p2,point p3,point p4,float doorX,float doorY,float doorZ)
{
	point p44=p4,p33=p3;
	p44.y=P4.y; p33.y=P3.y;

	// front side
	glPushMatrix();
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glPopMatrix();



	//back side
	glPushMatrix();
	glTranslated(0,0,P5.z);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();
	
	glDisable(GL_CULL_FACE);

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();
	
	glDisable(GL_CULL_FACE);

	glPopMatrix();



	// top side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P4.x,P4.y,P4.z);
	glTexCoord2d(1, 0);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P4.x,P4.y,P4.z);
	glTexCoord2d(1, 0);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glPopMatrix();



	// down side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainFloor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(0, 1);
	glVertex3d(P5.x,P5.y,P5.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);

	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(0, 1);
	glVertex3d(P5.x,P5.y,P5.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glPopMatrix();


	//left side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(P5.x,P5.y,P5.z);
	glTexCoord2d(1, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(P5.x,P5.y,P5.z);
	glTexCoord2d(1, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glPopMatrix();


	//right side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glPopMatrix();


	//draw trailer doors
	glPushMatrix();

	////////////////drawing trailer doors and interactions
	glPushMatrix();
	glTranslated(doorX,doorY,doorZ);

	//draw trailer door front
	glPushMatrix();
	point i1=p1,i2=p2,i3=p2,i4=p1;
	i1.z+=0.4; i2.z+=0.4; i3.z+=0.1; i4.z+=0.1;
	door d(i1,i2,i3,i4,p3.y,trainDoor);
	d.draw();
	glPopMatrix();

	//draw trailer door back
	glPushMatrix();
	glTranslated(0,0,P5.z-0.5);
	d.draw();
	glPopMatrix();
	
	glColor3f(1,1,1);
	glPopMatrix();
	/////////////////////////////////////////////////////////

	glPopMatrix();
	/////////////////////////////////////////////


	//draw trailer circles
	glPushMatrix();
	glColor3f(1,1,1);

	//draw front left circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-1,0,0);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw front right circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-1,0,-15.1);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw back right circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-39,0,0);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw back left circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-39,0,-15);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	glColor3f(1,1,1);
	glPopMatrix();



	//draw train joining line
	glPushMatrix();
	glColor3f(1,1,1);
	
	point x1=p1,x2=p2;
	x1.z+=3.3; x2.z+=3.3;
	cube l(x1,x2,p2,p1,0.1,0);
	l.draw_with_color(c);
	
	glColor3f(1,1,1);
	glPopMatrix();


	glPopMatrix();
}

void trailer::draw3(point p1,point p2,point p3,point p4,point p5,point p6,point p7,point p8,float doorX,float doorY,float doorZ)
{
	point p44=p4,p33=p3;
	p44.y=P4.y; p33.y=P3.y;

	point p55=p5,p66=p6,p77=p7,p88=p8;
	p55.y=P2.y; p66.y=P5.y;
	p77.y=P3.y; p88.y=P3.y;


	// front side
	glPushMatrix();
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glPopMatrix();



	//back side
	glPushMatrix();
	glTranslated(0,0,P5.z);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();
	
	glDisable(GL_CULL_FACE);

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();
	
	glDisable(GL_CULL_FACE);

	glPopMatrix();



	// top side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P4.x,P4.y,P4.z);
	glTexCoord2d(1, 0);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P4.x,P4.y,P4.z);
	glTexCoord2d(1, 0);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glPopMatrix();



	// down side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainFloor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(0, 1);
	glVertex3d(P5.x,P5.y,P5.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);

	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(0, 1);
	glVertex3d(P5.x,P5.y,P5.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glPopMatrix();


	
	//left side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(P5.x,P5.y,P5.z);
	glTexCoord2d(1, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(P5.x,P5.y,P5.z);
	glTexCoord2d(1, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glPopMatrix();


	//right side
	glPushMatrix();

	//draw right walls
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	float add=P6.z-3*p6.z;
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z+3*p6.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,P2.z+3*p6.z+add);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,P2.z+3*p6.z+add);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P2.z+3*p6.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	add=P6.z-3*p6.z;
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z+3*p6.z);
	glTexCoord2d(1, 0);
	glVertex3d(p55.x,p55.y,P2.z+3*p6.z+add);
	glTexCoord2d(1, 1);
	glVertex3d(p88.x,p88.y,P2.z+3*p6.z+add);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P2.z+3*p6.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p55.x,p55.y,p55.z);
	glTexCoord2d(1, 0);
	glVertex3d(p66.x,p66.y,p66.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(1, 0);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p77.x,p77.y,p77.z);
	glTexCoord2d(0, 1);
	glVertex3d(p88.x,p88.y,p88.z);
	glEnd();
	glPopMatrix();

	glDisable(GL_CULL_FACE);
	
	glPopMatrix();



	//draw trailer doors
	glPushMatrix();

	////////////////drawing trailer doors and interactions
	glPushMatrix();
	glTranslated(doorX,doorY,doorZ);

	//draw trailer door front
	glPushMatrix();
	point i1=p1,i2=p2,i3=p2,i4=p1;
	i1.z+=0.4; i2.z+=0.4; i3.z+=0.1; i4.z+=0.1;
	door d(i1,i2,i3,i4,p3.y,trainDoor);
	d.draw();
	glPopMatrix();

	//draw trailer door back
	glPushMatrix();
	glTranslated(0,0,P5.z-0.5);
	d.draw();
	glPopMatrix();
	
	glColor3f(1,1,1);
	glPopMatrix();
	/////////////////////////////////////////////////////////

	glPopMatrix();
	/////////////////////////////////////////////


	//draw trailer circles
	glPushMatrix();
	glColor3f(1,1,1);

	//draw front left circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-1,0,0);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw front right circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-1,0,-15.1);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw back right circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-39,0,0);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw back left circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-39,0,-15);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	glColor3f(1,1,1);
	glPopMatrix();



	//draw train joining line
	glPushMatrix();
	glColor3f(1,1,1);
	
	point x1=p1,x2=p2;
	x1.z+=3.3; x2.z+=3.3;
	cube l(x1,x2,p2,p1,0.1,0);
	l.draw_with_color(c);
	
	glColor3f(1,1,1);
	glPopMatrix();


	//draw right window
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, trainGlass);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,p6.z);
	glBindTexture(GL_TEXTURE_2D, trainGlass);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2*p6.z);
	glBindTexture(GL_TEXTURE_2D, trainGlass);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();
	glPopMatrix();


	glPopMatrix();
}

void trailer::draw_head(point p1,point p2,point p3,point p4,float hight,float width,float doorX,float doorY,float doorZ,int controllTable,int controllTableSide,int trainChimney)
{
	//drawing controll table
	point t1=P5,t2=P6,t3=P6,t4=P5;
	t1.x+=width/2; t4.x+=width/2; t2.x-=width/2; t3.x-=width/2;
	t4.z+=0.5; t3.z+=0.5;
	t1.z+=3; t2.z+=3;
	cube Ctable(t1,t2,t3,t4,hight-0.6,controllTable);
	glPushMatrix();
	Ctable.draw2(controllTable,controllTableSide);
	glPopMatrix();

	//drawing chimney
	point i1=P4,i2=i1,i4=i1;
	i2.x+=3.5;
	point i3=i2; i3.z-=3.5; i4.z-=3.5;
	cube chimney(i1,i2,i3,i4,5,trainChimney);
	glPushMatrix();
	chimney.draw();

	glPopMatrix();

	//for begin of the train head
	point x1=P5,x2=P6,x3=P6,x4=P5;
	x3.z-=width; x4.z-=width;
	cube beginHead(x1,x2,x3,x4,hight,trainColor);
	glPushMatrix();
	beginHead.draw();
	glPopMatrix();
	
	//draw door
	point pp3=p2,pp4=p1;
	pp3.z+=0.1; pp4.z+=0.1;
	p1.z+=0.3; p2.z+=0.3;
	cube door(p1,p2,pp3,pp4,6,trainDoor);
	glPushMatrix();
	glTranslated(doorX,doorY,doorZ);
	door.draw();
	glPopMatrix();
	
	// front side
	glPushMatrix();
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P5.x,P5.y,P5.z);
	glTexCoord2d(1, 0);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(1, 1);
	glVertex3d(P6.x,P6.y+hight,P6.z);
	glTexCoord2d(0, 1);
	glVertex3d(P5.x,P5.y+hight,P5.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P5.x,P5.y,P5.z);
	glTexCoord2d(1, 0);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(1, 1);
	glVertex3d(P6.x,P6.y+hight,P6.z);
	glTexCoord2d(0, 1);
	glVertex3d(P5.x,P5.y+hight,P5.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glPopMatrix();
	

	
	point p44=p4,p33=p3;
	p44.y=P4.y; p33.y=P3.y;

	//back side
	glPushMatrix();
	glTranslated(0,0,0);

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();
	
	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p33.x,p33.y,p33.z);
	glTexCoord2d(0, 1);
	glVertex3d(p44.x,p44.y,p44.z);
	glEnd();
	
	glDisable(GL_CULL_FACE);

	glPopMatrix();
	
	
	// top side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainColor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P4.x,P4.y,P4.z);
	glTexCoord2d(1, 0);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_2D, trainInside);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P4.x,P4.y,P4.z);
	glTexCoord2d(1, 0);
	glVertex3d(P3.x,P3.y,P3.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glEnd();

	glDisable(GL_CULL_FACE);

	glPopMatrix();



	// down side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainFloor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(0, 1);
	glVertex3d(P5.x,P5.y,P5.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);

	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 1);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(0, 1);
	glVertex3d(P5.x,P5.y,P5.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glPopMatrix();


	//left side
	glPushMatrix();

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(P5.x,P5.y,P5.z);
	glTexCoord2d(1, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P1.x,P1.y,P1.z);
	glTexCoord2d(1, 0);
	glVertex3d(P5.x,P5.y,P5.z);
	glTexCoord2d(1, 1);
	glVertex3d(P8.x,P8.y,P8.z);
	glTexCoord2d(0, 1);
	glVertex3d(P4.x,P4.y,P4.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glPopMatrix();
	

	//right side
	glPushMatrix();

	glCullFace(GL_FRONT);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainInside);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, trainColor);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(P2.x,P2.y,P2.z);
	glTexCoord2d(1, 0);
	glVertex3d(P6.x,P6.y,P6.z);
	glTexCoord2d(1, 1);
	glVertex3d(P7.x,P7.y,P7.z);
	glTexCoord2d(0, 1);
	glVertex3d(P3.x,P3.y,P3.z);
	glEnd();
	glDisable(GL_CULL_FACE);

	glPopMatrix();



	//draw trailer circles
	glPushMatrix();
	glColor3f(1,1,1);

	//draw front left circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-1,0,0);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw front right circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-1,0,-15.1);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw back right circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-39,0,0);
	glTranslated(21,0,0);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	//draw back left circle
	glPushMatrix();
	glRotated(270,0,1,0);
	glTranslated(-39,0,-15);
	glTranslated(21,0,0);
	glBegin(GL_POLYGON);
	glColor3f(c.r,c.g,c.b);
		for(float angle = 0.0f; angle <= (2.0f*3.14f); angle += 0.000001f)
		{
			float x = 2.0f * cos(angle);
			float y = 2.0f * sin(angle);
			glVertex3f(P1.x, P1.y, P1.z);
			glVertex3f(x, y, P1.z);
			angle += 0.1f;
			x = 2.0f * cos(angle);
			y = 2.0f * sin(angle);
			glVertex3f(x, y, P1.z);
		}
	glEnd();
	glPopMatrix();

	glColor3f(1,1,1);
	glPopMatrix();



	//draw train joining line
	glPushMatrix();
	glColor3f(1,1,1);
	
	point z1=P1,z2=P2;
	z1.x+=6; z2.x-=5;
	point z3=z2,z4=z1;
	z1.z+=3.3; z2.z+=3.3;
	cube l(z1,z2,z3,z4,0.1,0);
	l.draw_with_color(c);
	
	glColor3f(1,1,1);
	glPopMatrix();

	//points for window
	point p5=x1,p6=x2,p7=x2,p8=x1;
	p5.y+=hight; p6.y+=hight;
	cube window(p5,p6,p6,p5,P7.y-p5.y,trainGlass);
	glPushMatrix();
	window.draw();
	glPopMatrix();
}


bool trailer::headRoomCollision(point cam,point tranz,bool openDoor)
{
	bool ok=false;

	// check collision with sitting trailer inside ans door
	if(in_collision(tranz.x+(0),tranz.x+(15),tranz.z+(-14),tranz.z+(0),cam) & ( ( (cam.x>=6&&cam.x<=10 && (cam.z>tranz.z+(0)&&!openDoor)) || (cam.x>=6&&cam.x<=10 && (cam.z<tranz.z+(-40)&&!openDoor)) ) || !openDoor ) )
		ok=true;

	if(out_collision(tranz.x+(2),tranz.x+(13),tranz.z+(-14),tranz.z+(-11),cam))
		ok=true;
	
	return ok;
}

bool trailer::in_collision(float minX,float maxX,float minZ,float maxZ,point cam)
{
	if(cam.x>=minX && cam.x<=maxX && cam.z<=maxZ && cam.z>=minZ)
		return false;
	else
		return true;
}

bool trailer::out_collision(float minX,float maxX,float minZ,float maxZ,point cam)
{
	if(cam.x>=minX&&cam.x<=maxX){
		if(cam.z>=maxZ || cam.z<=minZ)
			return false;
		else return true;
	}
	return false;
}

trailer::~trailer(void)
{
}
