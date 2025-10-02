#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "point.h"
#include "color.h"
#include "cube.h"

cube::cube(void)
{
}

cube::cube(point p11,point p22,point p33,point p44,float hightt,int photoo)
{
	p1=p11; p2=p22; p3=p33; p4=p44; hight=hightt; photo=photoo;
}

void cube::draw()
{	
	glBindTexture(GL_TEXTURE_2D, photo);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p1.x,p1.y,p1.z);
		glTexCoord2d(1,0);
		glVertex3f(p2.x,p2.y,p2.z);
		glTexCoord2d(1,1);
		glVertex3f(p3.x,p3.y,p3.z);
		glTexCoord2d(0,1);
		glVertex3f(p4.x,p4.y,p4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, photo);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p1.x,p1.y+hight,p1.z);
		glTexCoord2d(1,0);
		glVertex3f(p2.x,p2.y+hight,p2.z);
		glTexCoord2d(1,1);
		glVertex3f(p3.x,p3.y+hight,p3.z);
		glTexCoord2d(0,1);
		glVertex3f(p4.x,p4.y+hight,p4.z);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, photo);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p4.x,p4.y,p4.z);
		glTexCoord2d(1,0);
		glVertex3f(p1.x,p1.y,p1.z);
		glTexCoord2d(1,1);
		glVertex3f(p1.x,p1.y+hight,p1.z);
		glTexCoord2d(0,1);
		glVertex3f(p4.x,p4.y+hight,p4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, photo);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p2.x,p2.y,p2.z);
		glTexCoord2d(1,0);
		glVertex3f(p3.x,p3.y,p3.z);
		glTexCoord2d(1,1);
		glVertex3f(p3.x,p3.y+hight,p3.z);
		glTexCoord2d(0,1);
		glVertex3f(p2.x,p2.y+hight,p2.z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, photo);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p1.x,p1.y,p1.z);
		glTexCoord2d(1,0);
		glVertex3f(p2.x,p2.y,p2.z);
		glTexCoord2d(1,1);
		glVertex3f(p2.x,p2.y+hight,p2.z);
		glTexCoord2d(0,1);
		glVertex3f(p1.x,p1.y+hight,p1.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, photo);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p4.x,p4.y,p4.z);
		glTexCoord2d(1,0);
		glVertex3f(p3.x,p3.y,p3.z);
		glTexCoord2d(1,1);
		glVertex3f(p3.x,p3.y+hight,p3.z);
		glTexCoord2d(0,1);
		glVertex3f(p4.x,p4.y+hight,p4.z);
	glEnd();
}

void cube::draw2(int top,int sides)	
{	
	glBindTexture(GL_TEXTURE_2D, sides);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p1.x,p1.y,p1.z);
		glTexCoord2d(1,0);
		glVertex3f(p2.x,p2.y,p2.z);
		glTexCoord2d(1,1);
		glVertex3f(p3.x,p3.y,p3.z);
		glTexCoord2d(0,1);
		glVertex3f(p4.x,p4.y,p4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, top);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p1.x,p1.y+hight,p1.z);
		glTexCoord2d(1,0);
		glVertex3f(p2.x,p2.y+hight,p2.z);
		glTexCoord2d(1,1);
		glVertex3f(p3.x,p3.y+hight,p3.z);
		glTexCoord2d(0,1);
		glVertex3f(p4.x,p4.y+hight,p4.z);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, sides);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p4.x,p4.y,p4.z);
		glTexCoord2d(1,0);
		glVertex3f(p1.x,p1.y,p1.z);
		glTexCoord2d(1,1);
		glVertex3f(p1.x,p1.y+hight,p1.z);
		glTexCoord2d(0,1);
		glVertex3f(p4.x,p4.y+hight,p4.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, sides);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p2.x,p2.y,p2.z);
		glTexCoord2d(1,0);
		glVertex3f(p3.x,p3.y,p3.z);
		glTexCoord2d(1,1);
		glVertex3f(p3.x,p3.y+hight,p3.z);
		glTexCoord2d(0,1);
		glVertex3f(p2.x,p2.y+hight,p2.z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, sides);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p1.x,p1.y,p1.z);
		glTexCoord2d(1,0);
		glVertex3f(p2.x,p2.y,p2.z);
		glTexCoord2d(1,1);
		glVertex3f(p2.x,p2.y+hight,p2.z);
		glTexCoord2d(0,1);
		glVertex3f(p1.x,p1.y+hight,p1.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, sides);

	glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(p4.x,p4.y,p4.z);
		glTexCoord2d(1,0);
		glVertex3f(p3.x,p3.y,p3.z);
		glTexCoord2d(1,1);
		glVertex3f(p3.x,p3.y+hight,p3.z);
		glTexCoord2d(0,1);
		glVertex3f(p4.x,p4.y+hight,p4.z);
	glEnd();
}

void cube::draw_with_color(color c)
{
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
		glColor3f(c.r,c.g,c.b);
		glVertex3f(p1.x,p1.y,p1.z);
		glVertex3f(p2.x,p2.y,p2.z);
		glVertex3f(p3.x,p3.y,p3.z);
		glVertex3f(p4.x,p4.y,p4.z);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(c.r,c.g,c.b);
		glVertex3f(p1.x,p1.y+hight,p1.z);
		glVertex3f(p2.x,p2.y+hight,p2.z);
		glVertex3f(p3.x,p3.y+hight,p3.z);
		glVertex3f(p4.x,p4.y+hight,p4.z);
	glEnd();
	
	glBegin(GL_QUADS);
		glColor3f(c.r,c.g,c.b);
		glVertex3f(p1.x,p1.y,p1.z);
		glVertex3f(p4.x,p4.y,p4.z);
		glVertex3f(p4.x,p4.y+hight,p4.z);
		glVertex3f(p1.x,p1.y+hight,p1.z);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(c.r,c.g,c.b);
		glVertex3f(p2.x,p2.y,p2.z);
		glVertex3f(p3.x,p3.y,p3.z);
		glVertex3f(p3.x,p3.y+hight,p3.z);
		glVertex3f(p2.x,p2.y+hight,p2.z);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(c.r,c.g,c.b);
		glVertex3f(p1.x,p1.y,p1.z);
		glVertex3f(p2.x,p1.y,p2.z);
		glVertex3f(p2.x,p2.y+hight,p2.z);
		glVertex3f(p1.x,p1.y+hight,p1.z);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(c.r,c.g,c.b);
		glVertex3f(p4.x,p4.y,p4.z);
		glVertex3f(p3.x,p3.y,p3.z);
		glVertex3f(p3.x,p3.y+hight,p3.z);
		glVertex3f(p4.x,p4.y+hight,p4.z);
	glEnd();

}

cube::~cube(void)
{
}
