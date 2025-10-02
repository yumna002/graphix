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


skybox::skybox(void)
{
}

skybox::skybox(point p11,point p22,point p33,point p44,point p55,point p66,point p77,point p88,
		int frontt,int backk,int topp,int downn,int leftt,int rightt)
{
	p1=p11; p2=p22; p3=p33; p4=p44; p5=p55; p6=p66; p7=p77; p8=p88;
	left=leftt; right=rightt; down=downn; top=topp; front=frontt; back=backk;
}

void skybox::draw()
{
	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 1);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p4.x,p4.y,p4.z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, front);
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

	glBindTexture(GL_TEXTURE_2D, left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(0, 1);
	glVertex3d(p4.x,p4.y,p4.z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, right);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(0, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p3.x,p3.y,p3.z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
}

void skybox::draw2(point i1,point i2,point i3,point i4,point i5,point i6,point i7,point i8,int ph)
{
	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 1);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p4.x,p4.y,p4.z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, front);
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
	
	point ii5=i5,ii6=i6,ii7=i7,ii8=i8;
	ii5.x=p1.x; ii6.x=p1.x; ii7.x=p1.x; ii8.x=p1.x;
	ii5.z=p1.z; ii6.z=p5.z; ii7.z=p5.z; ii8.z=p1.z;

	glBindTexture(GL_TEXTURE_2D, ph);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 1);
	glVertex3d(ii6.x,ii6.y,ii6.z);
	glTexCoord2d(0, 1);
	glVertex3d(ii5.x,ii5.y,ii5.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(ii8.x,ii8.y,ii8.z);
	glTexCoord2d(1, 0);
	glVertex3d(ii7.x,ii7.y,ii7.z);
	glTexCoord2d(1, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(0, 1);
	glVertex3d(p4.x,p4.y,p4.z);
	glEnd();
	
	point x1=i5,x2=i6,x3=i7,x4=i8;
	x1.x=p1.x; x2.x=p1.x; x3.x=p1.x; x4.x=p1.x;

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(ii5.x,ii5.y,ii5.z);
	glTexCoord2d(1, 0);
	glVertex3d(x1.x,x1.y,x1.z);
	glTexCoord2d(1, 1);
	glVertex3d(x4.x,x4.y,x4.z);
	glTexCoord2d(0, 1);
	glVertex3d(ii8.x,ii8.y,ii8.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(x2.x,x2.y,x2.z);
	glTexCoord2d(1, 0);
	glVertex3d(ii6.x,ii6.y,ii6.z);
	glTexCoord2d(1, 1);
	glVertex3d(ii7.x,ii7.y,ii7.z);
	glTexCoord2d(0, 1);
	glVertex3d(x3.x,x3.y,x3.z);
	glEnd();
	
	
	point x5=i4,x6=i3,x7=i5,x8=i6,x10=i8,x9=i7;
	x5.y=p3.y; x6.y=p3.y; x10.y=p3.y; x9.y=p3.y; x7.y=p2.y; x8.y=p2.y;

	glBindTexture(GL_TEXTURE_2D, right);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(0, 0);
	glVertex3d(i1.x,i1.y,i1.z);
	glTexCoord2d(0, 1);
	glVertex3d(x5.x,x5.y,x5.z);
	glTexCoord2d(1, 1);
	glVertex3d(p3.x,p3.y,p3.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(i2.x,i2.y,i2.z);
	glTexCoord2d(0, 0);
	glVertex3d(x7.x,x7.y,x7.z);
	glTexCoord2d(0, 1);
	glVertex3d(x10.x,x10.y,x10.z);
	glTexCoord2d(1, 1);
	glVertex3d(x6.x,x6.y,x6.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(x8.x,x8.y,x8.z);
	glTexCoord2d(0, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(1, 1);
	glVertex3d(x9.x,x9.y,x9.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, ph);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(i4.x,i4.y,i4.z);
	glTexCoord2d(0, 0);
	glVertex3d(i3.x,i3.y,i3.z);
	glTexCoord2d(0, 1);
	glVertex3d(x6.x,x6.y,x6.z);
	glTexCoord2d(1, 1);
	glVertex3d(x5.x,x5.y,x5.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(i8.x,i8.y,i8.z);
	glTexCoord2d(0, 0);
	glVertex3d(i7.x,i7.y,i7.z);
	glTexCoord2d(0, 1);
	glVertex3d(x9.x,x9.y,x9.z);
	glTexCoord2d(1, 1);
	glVertex3d(x10.x,x10.y,x10.z);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(x7.x,x7.y,x7.z);
	glTexCoord2d(0, 0);
	glVertex3d(x8.x,x8.y,x8.z);
	glTexCoord2d(0, 1);
	glVertex3d(i6.x,i6.y,i6.z);
	glTexCoord2d(1, 1);
	glVertex3d(i5.x,i5.y,i5.z);
	glEnd();
	

	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(1, 0);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, down);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 1);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(0, 1);
	glVertex3d(p5.x,p5.y,p5.z);
	glEnd();
}

skybox::~skybox(void)
{
}
