#include "nature.h"
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

nature::nature(void)
{
}

nature::nature(int nu)
{
}

void nature::draw(int top,int left,int right,int front,int back,int down,int glass,int building1,int building2,int building3,
		int building4,int building5,int building6,int building7,int treewood1,int treewood2,int treeleaf,
		int treeleaf2,int treeleaf3,int treeleaf4,int treeleaf5,int treeleaf6,int treeleaf8,int treeleaf9,
		int treeleaf10,int treeleaf11,int treeleaf12,int house1,int house2,
		int house3,int roof1,int roof2,int rollercoaster1,int rollercoaster2)
{
	glPushMatrix();
	////////////////////////////////////////////draw sky box
  glPushMatrix();
  point S1(-60,-2,0),S2(60,-2,0),S3(60,50,0),S4(-60,50,0),
    S5(-60,-2,-800),S6(60,-2,-800),S7(60,50,-800),S8(-60,50,-800);
  skybox skx(S1,S2,S3,S4,S5,S6,S7,S8,front,back,top,down,left,right);
  skx.draw();
  glPopMatrix();
  /////////////////////////////////////////////////////////




  //building in the other side
	glPushMatrix();
	glTranslated(50,-2,-20);
	point bs1(0,0,0),bs2(5,0,0),bs3(5,0,-5),bs4(0,0,-5);
	cube cs1(bs1,bs2,bs3,bs4,20,building1);
	cs1.draw();
	glPopMatrix();

	//building in the other side
	glPushMatrix();
	glTranslated(45,-2,-20);
	glTranslated(0,0,-20);
	point bs5(0,0,0),bs6(5,0,0),bs7(5,0,-5),bs8(0,0,-5);
	cube cs2(bs5,bs6,bs7,bs8,20,building2);
	cs2.draw();

	//building in the other side
	glTranslated(0,0,-20);
	point bs9(0,0,0),bs10(5,0,0),bs11(5,0,-5),bs12(0,0,-5);
	cube cs3(bs9,bs10,bs11,bs12,20,building3);
	cs3.draw();

	//building in the other side
	point bs13(0,0,0),bs14(5,0,0),bs15(5,0,-5),bs16(0,0,-3);
	cube cs4(bs13,bs14,bs15,bs16,20,building4);
	cs4.draw();
	//building in the other side
	glTranslatef(0,0,-20);
	point bs17(0,0,0),bs18(5,0,0),bs19(5,0,-5),bs20(0,0,-5);
	cube cs5(bs17,bs18,bs19,bs20,20,building5);
	cs5.draw();

	//building in the other side
	glTranslatef(0,0,-20);
	point bs21(0,0,0),bs22(5,0,0),bs23(5,0,-5),bs24(0,0,-5);
	cube cs6(bs21,bs22,bs23,bs24,20,building6);
	cs6.draw();
	//seventh building
	glTranslatef(0,0,-20);
	point bs25(0,0,0),bs26(5,0,0),bs27(5,0,-5),bs28(0,0,-5);
	cube cs7(bs25,bs26,bs27,bs28,20,building7);
	cs7.draw();

	//eighdth building
	glTranslatef(0,0,-20);
	point bs29(0,0,0),bs30(5,0,0),bs31(5,0,-5),bs32(0,0,-5);
	cube cs8(bs29,bs30,bs31,bs32,20,building1);
	cs8.draw();

	//nineth building
	glTranslated(0,0,-20);
	point bs33(0,0,0),bs34(5,0,0),bs35(5,0,-5),bs36(0,0,-5);
	cube cs9(bs33,bs34,bs35,bs36,20,building2);
	cs9.draw();
	//tenth building
	glTranslatef(0,0,-20);
	point bs37(0,0,0),bs38(5,0,0),bs39(5,0,-5),bs40(0,0,-5);
	cube cs10(bs37,bs38,bs39,bs40,20,building3);
	cs10.draw();

	//11th building
	glTranslatef(0,0,-20);
	point bs41(0,0,0),bs42(5,0,0),bs43(5,0,-5),bs44(0,0,-3);
	cube cs11(bs41,bs42,bs43,bs44,20,building4);
	cs11.draw();

	//12th building
	glTranslatef(0,0,-20);
	point bs45(0,0,0),bs46(5,0,0),bs47(5,0,-5),bs48(0,0,-5);
	cube cs12(bs45,bs46,bs47,bs48,20,building5);
	cs12.draw();

	//13th building
	glTranslatef(0,0,-20);
	point bs49(0,0,0),bs50(5,0,0),bs51(5,0,-5),bs52(0,0,-5);
	cube cs13(bs49,bs50,bs51,bs52,20,building6);
	cs13.draw();
	//14th building
	glTranslatef(0,0,-20);
	point bs53(0,0,0),bs54(5,0,0),bs55(5,0,-5),bs56(0,0,-5);
	cube cs14(bs53,bs54,bs55,bs56,20,building1);
	cs14.draw();

	//15th building
	glTranslated(0,0,-20);
	point bs57(0,0,0),bs58(5,0,0),bs59(5,0,-5),bs60(0,0,-5);
	cube cs15(bs57,bs58,bs59,bs60,20,building2);
	cs15.draw();
	//16th building
	glTranslatef(0,0,-20);
	point bs61(0,0,0),bs62(5,0,0),bs63(5,0,-5),bs64(0,0,-5);
	cube cs16(bs61,bs62,bs63,bs64,20,building3);
	cs16.draw();

	//17th building
	glTranslatef(0,0,-20);
	point bs65(0,0,0),bs66(5,0,0),bs67(5,0,-5),bs68(0,0,-3);
	cube cs17(bs65,bs66,bs67,bs68,20,building4);
	cs17.draw();

	//18th building
	glTranslatef(0,0,-20);
	point bs69(0,0,0),bs70(5,0,0),bs71(5,0,-5),bs72(0,0,-5);
	cube cs18(bs69,bs70,bs71,bs72,20,building5);
	cs18.draw();

	//19th building
	glTranslatef(0,0,-20);
	point bs73(0,0,0),bs74(5,0,0),bs75(5,0,-5),bs76(0,0,-5);
	cube cs19(bs73,bs74,bs75,bs76,20,building6);
	cs19.draw();

	//first house
	//glPushMatrix();
	glTranslatef(1,0,-20);

	//glTranslatef(50,0,-20);
	point ish1(0,0,0),ish2(8,0,0),ish3(8,0,-8),ish4(0,0,-8);
	cube csh(ish1,ish2,ish3,ish4,7,house1);
	csh.draw();

	point hs1(-5.0f, -5.0f, -4.0f),hs2(5.0f, -5.0f, -4.0f),hs3(0.0f, 5.0f, 0.0f),hs4(-5.0f, -5.0f, 4.0f),hs5(5.0f, -5.0f, 4.0f),hs6(0.0f, 5.0f, 0.0f),
		hs7(-5.0f, -5.0f, 4.0f),hs8(-5.0f, -5.0f, -4.0f),hs9(0.0f, 5.0f, 0.0f),hs10(5.0f, -5.0f, -4.0f),hs11(5.0f, -5.0f, 4.0f),hs12(0.0f, 5.0f, 0.0f),
		hs13(5.0f, -5.0f, -4.0f),hs14(5.0f, -5.0f, 4.0f),hs15(-5.0f, -5.0f, -4.0f),hs16(5.0f, -5.0f, 4.0f),hs17(-5.0f, -5.0f, -4.0f),hs18(-5.0f, -5.0f, 4.0f);
	glTranslatef(2,11,-1);
	glBindTexture(GL_TEXTURE_2D, roof2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(hs1.x,hs1.y,hs1.z);
	glTexCoord2d(1, 0);
	glVertex3d(hs2.x,hs2.y,hs2.z);
	glTexCoord2d(1, 1);
	glVertex3d(hs3.x,hs3.y,hs3.z);
	glTexCoord2d(0, 1);
	glVertex3d(hs4.x,hs4.y,hs4.z);
	glTexCoord2d(0, 0);
    glVertex3d(hs5.x,hs5.y,hs5.z);
	glTexCoord2d(1, 0);
	glVertex3d(hs6.x,hs6.y,hs6.z);
	glTexCoord2d(1, 1);
	glVertex3d(hs7.x,hs7.y,hs7.z);
	glTexCoord2d(0, 1);
	glVertex3d(hs8.x,hs8.y,hs8.z);
	glTexCoord2d(0, 0);
	glVertex3d(hs9.x,hs9.y,hs9.z);
	glTexCoord2d(1, 0);
	glVertex3d(hs10.x,hs10.y,hs10.z);
	glTexCoord2d(1, 1);
	glVertex3d(hs11.x,hs11.y,hs11.z);
	glTexCoord2d(0, 1);
	glVertex3d(hs12.x,hs12.y,hs12.z);
	glTexCoord2d(0, 0);
	glVertex3d(hs13.x,hs13.y,hs13.z);
	glTexCoord2d(1, 0);
	glVertex3d(hs14.x,hs14.y,hs14.z);
	glTexCoord2d(1, 1);
	glVertex3d(hs15.x,hs15.y,hs15.z);
	glTexCoord2d(0, 1);
	glVertex3d(hs16.x,hs16.y,hs16.z);
	glTexCoord2d(0, 0);
	glVertex3d(hs17.x,hs17.y,hs17.z);
	glTexCoord2d(1, 0);
	glVertex3d(hs18.x,hs18.y,hs18.z);
	glTexCoord2d(1, 1);
	glEnd();
	//glPopMatrix();

	
	//firsrt tree
	//glPushMatrix();
	glTranslatef(-3.5,-11,-20);
	point is1(0,0,0),is2(2,0,0),is3(2,0,-2),is4(0,0,-2);
	cube cs(is1,is2,is3,is4,7,treewood2);
	cs.draw();

	point ps1(-5.0f, -5.0f, -4.0f),ps2(5.0f, -5.0f, -4.0f),ps3(0.0f, 5.0f, 0.0f),ps4(-5.0f, -5.0f, 4.0f),ps5(5.0f, -5.0f, 4.0f),ps6(0.0f, 5.0f, 0.0f),
		ps7(-5.0f, -5.0f, 4.0f),ps8(-5.0f, -5.0f, -4.0f),ps9(0.0f, 5.0f, 0.0f),ps10(5.0f, -5.0f, -4.0f),ps11(5.0f, -5.0f, 4.0f),ps12(0.0f, 5.0f, 0.0f),
		ps13(5.0f, -5.0f, -4.0f),ps14(5.0f, -5.0f, 4.0f),ps15(-5.0f, -5.0f, -4.0f),ps16(5.0f, -5.0f, 4.0f),ps17(-5.0f, -5.0f, -4.0f),ps18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-1);
	glBindTexture(GL_TEXTURE_2D, treeleaf2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(ps1.x,ps1.y,ps1.z);
	glTexCoord2d(1, 0);
	glVertex3d(ps2.x,ps2.y,ps2.z);
	glTexCoord2d(1, 1);
	glVertex3d(ps3.x,ps3.y,ps3.z);
	glTexCoord2d(0, 1);
	glVertex3d(ps4.x,ps4.y,ps4.z);
	glTexCoord2d(0, 0);
    glVertex3d(ps5.x,ps5.y,ps5.z);
	glTexCoord2d(1, 0);
	glVertex3d(ps6.x,ps6.y,ps6.z);
	glTexCoord2d(1, 1);
	glVertex3d(ps7.x,ps7.y,ps7.z);
	glTexCoord2d(0, 1);
	glVertex3d(ps8.x,ps8.y,ps8.z);
	glTexCoord2d(0, 0);
	glVertex3d(ps9.x,ps9.y,ps9.z);
	glTexCoord2d(1, 0);
	glVertex3d(ps10.x,ps10.y,ps10.z);
	glTexCoord2d(1, 1);
	glVertex3d(ps11.x,ps11.y,ps11.z);
	glTexCoord2d(0, 1);
	glVertex3d(ps12.x,ps12.y,ps12.z);
	glTexCoord2d(0, 0);
	glVertex3d(ps13.x,ps13.y,ps13.z);
	glTexCoord2d(1, 0);
	glVertex3d(ps14.x,ps14.y,ps14.z);
	glTexCoord2d(1, 1);
	glVertex3d(ps15.x,ps15.y,ps15.z);
	glTexCoord2d(0, 1);
	glVertex3d(ps16.x,ps16.y,ps16.z);
	glTexCoord2d(0, 0);
	glVertex3d(ps17.x,ps17.y,ps17.z);
	glTexCoord2d(1, 0);
	glVertex3d(ps18.x,ps18.y,ps18.z);
	glTexCoord2d(1, 1);
	glEnd();
	//glPopMatrix();

	//second tree
	//glPushMatrix();
	glTranslatef(-2,-11,-20);
	glTranslatef(0,-2,-20);
	point js1(0,0,0),js2(2,0,0),js3(2,0,-2),js4(0,0,-2);
	cube csj(js1,js2,js3,js4,10,treewood2);
	csj.draw();

	point pjs1(-5.0f, -5.0f, -4.0f),pjs2(5.0f, -5.0f, -4.0f),pjs3(0.0f, 5.0f, 0.0f),pjs4(-5.0f, -5.0f, 4.0f),pjs5(5.0f, -5.0f, 4.0f),pjs6(0.0f, 5.0f, 0.0f),
		psj7(-5.0f, -5.0f, 4.0f),pjs8(-5.0f, -5.0f, -4.0f),pjs9(0.0f, 5.0f, 0.0f),pjs10(5.0f, -5.0f, -4.0f),pjs11(5.0f, -5.0f, 4.0f),pjs12(0.0f, 5.0f, 0.0f),
		pjs13(5.0f, -5.0f, -4.0f),pjs14(5.0f, -5.0f, 4.0f),pjs15(-5.0f, -5.0f, -4.0f),pjs16(5.0f, -5.0f, 4.0f),pjs17(-5.0f, -5.0f, -4.0f),pjs18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pjs1.x,pjs1.y,pjs1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pjs2.x,pjs2.y,pjs2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pjs3.x,pjs3.y,pjs3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pjs4.x,pjs4.y,pjs4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pjs5.x,pjs5.y,pjs5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pjs6.x,pjs6.y,pjs6.z);
	glTexCoord2d(1, 1);
	glVertex3d(psj7.x,psj7.y,psj7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pjs8.x,pjs8.y,pjs8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pjs9.x,pjs9.y,pjs9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pjs10.x,pjs10.y,pjs10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pjs11.x,pjs11.y,pjs11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pjs12.x,pjs12.y,pjs12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pjs13.x,pjs13.y,pjs13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pjs14.x,pjs14.y,pjs14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pjs15.x,pjs15.y,pjs15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pjs16.x,pjs16.y,pjs16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pjs17.x,pjs17.y,pjs17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pjs18.x,pjs18.y,pjs18.z);
	glTexCoord2d(1, 1);
	glEnd();
	//glPopMatrix();
	
	//third tree
	//glPushMatrix();
	glTranslatef(0,-11,-20);
	glTranslatef(0,0,-20);
	point ks1(0,0,0),ks2(2,0,0),ks3(2,0,-2),ks4(0,0,-2);
	cube csk(ks1,ks2,ks3,ks4,10,treewood1);
	csk.draw();

	point psk1(-5.0f, -5.0f, -4.0f),psk2(5.0f, -5.0f, -4.0f),psk3(0.0f, 5.0f, 0.0f),psk4(-5.0f, -5.0f, 4.0f),psk5(5.0f, -5.0f, 4.0f),psk6(0.0f, 5.0f, 0.0f),
		psk7(-5.0f, -5.0f, 4.0f),psk8(-5.0f, -5.0f, -4.0f),psk9(0.0f, 5.0f, 0.0f),psk10(5.0f, -5.0f, -4.0f),psk11(5.0f, -5.0f, 4.0f),psk12(0.0f, 5.0f, 0.0f),
		psk13(5.0f, -5.0f, -4.0f),psk14(5.0f, -5.0f, 4.0f),psk15(-5.0f, -5.0f, -4.0f),psk16(5.0f, -5.0f, 4.0f),psk17(-5.0f, -5.0f, -4.0f),psk18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf3);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(psk1.x,psk1.y,psk1.z);
	glTexCoord2d(1, 0);
	glVertex3d(psk2.x,psk2.y,psk2.z);
	glTexCoord2d(1, 1);
	glVertex3d(psk3.x,psk3.y,psk3.z);
	glTexCoord2d(0, 1);
	glVertex3d(psk4.x,psk4.y,psk4.z);
	glTexCoord2d(0, 0);
    glVertex3d(psk5.x,psk5.y,psk5.z);
	glTexCoord2d(1, 0);
	glVertex3d(psk6.x,psk6.y,psk6.z);
	glTexCoord2d(1, 1);
	glVertex3d(psk7.x,psk7.y,psk7.z);
	glTexCoord2d(0, 1);
	glVertex3d(psk8.x,psk8.y,psk8.z);
	glTexCoord2d(0, 0);
	glVertex3d(psk9.x,psk9.y,psk9.z);
	glTexCoord2d(1, 0);
	glVertex3d(psk10.x,psk10.y,psk10.z);
	glTexCoord2d(1, 1);
	glVertex3d(psk11.x,psk11.y,psk11.z);
	glTexCoord2d(0, 1);
	glVertex3d(psk12.x,psk12.y,psk12.z);
	glTexCoord2d(0, 0);
	glVertex3d(psk13.x,psk13.y,psk13.z);
	glTexCoord2d(1, 0);
	glVertex3d(psk14.x,psk14.y,psk14.z);
	glTexCoord2d(1, 1);
	glVertex3d(psk15.x,psk15.y,psk15.z);
	glTexCoord2d(0, 1);
	glVertex3d(psk16.x,psk16.y,psk16.z);
	glTexCoord2d(0, 0);
	glVertex3d(psk17.x,psk17.y,psk17.z);
	glTexCoord2d(1, 0);
	glVertex3d(psk18.x,psk18.y,psk18.z);
	glTexCoord2d(1, 1);
	glEnd();


	//glPopMatrix();



	//second house
	//glPushMatrix();
	glTranslatef(-5,-9,-20);
	point ishh1(0,0,0),ishh2(9,0,0),ishh3(9,0,-9),ishh4(0,0,-9);
	cube cshh(ishh1,ishh2,ishh3,ishh4,7,house2);
	cshh.draw();

	point pshh1(-5.0f, -5.0f, -5.0f),pshh2(5.0f, -5.0f, -5.0f),pshh3(0.0f, 5.0f, 0.0f),pshh4(-5.0f, -5.0f, 5.0f),pshh5(5.0f, -5.0f, 5.0f),pshh6(0.0f, 5.0f, 0.0f),
		pshh7(-5.0f, -5.0f, 5.0f),pshh8(-5.0f, -5.0f, -5.0f),pshh9(0.0f, 5.0f, 0.0f),pshh10(5.0f, -5.0f, -5.0f),pshh11(5.0f, -5.0f, 5.0f),pshh12(0.0f, 5.0f, 0.0f),
		pshh13(5.0f, -5.0f, -5.0f),pshh14(5.0f, -5.0f, 5.0f),pshh15(-5.0f, -5.0f, -5.0f),pshh16(5.0f, -5.0f, 5.0f),pshh17(-5.0f, -5.0f, -5.0f),pshh18(-5.0f, -5.0f, 5.0f);
	
	glTranslatef(3.5,11,-1);
	glBindTexture(GL_TEXTURE_2D, roof2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pshh1.x,pshh1.y,pshh1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pshh2.x,pshh2.y,pshh2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pshh3.x,pshh3.y,pshh3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pshh4.x,pshh4.y,pshh4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pshh5.x,pshh5.y,pshh5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pshh6.x,pshh6.y,pshh6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pshh7.x,pshh7.y,pshh7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pshh8.x,pshh8.y,pshh8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pshh9.x,pshh9.y,pshh9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pshh10.x,pshh10.y,pshh10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pshh11.x,pshh11.y,pshh11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pshh12.x,pshh12.y,pshh12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pshh13.x,pshh13.y,pshh13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pshh14.x,pshh14.y,pshh14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pshh15.x,pshh15.y,pshh15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pshh16.x,pshh16.y,pshh16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pshh17.x,pshh17.y,pshh17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pshh18.x,pshh18.y,pshh18.z);
	glTexCoord2d(1, 1);
	glEnd();


	//firsrt tree
	//glPushMatrix();
	glTranslatef(1,-11,-20);
	point ist1(0,0,0),ist2(2,0,0),ist3(2,0,-2),ist4(0,0,-2);
	cube csit(ist1,ist2,ist3,ist4,7,treewood2);
	csit.draw();

	point pst1(-5.0f, -5.0f, -4.0f),pst2(5.0f, -5.0f, -4.0f),pst3(0.0f, 5.0f, 0.0f),pst4(-5.0f, -5.0f, 4.0f),pst5(5.0f, -5.0f, 4.0f),pst6(0.0f, 5.0f, 0.0f),
		pst7(-5.0f, -5.0f, 4.0f),pst8(-5.0f, -5.0f, -4.0f),pst9(0.0f, 5.0f, 0.0f),pst10(5.0f, -5.0f, -4.0f),pst11(5.0f, -5.0f, 4.0f),pst12(0.0f, 5.0f, 0.0f),
		pst13(5.0f, -5.0f, -4.0f),pst14(5.0f, -5.0f, 4.0f),pst15(-5.0f, -5.0f, -4.0f),pst16(5.0f, -5.0f, 4.0f),pst17(-5.0f, -5.0f, -4.0f),pst18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-1);
	glBindTexture(GL_TEXTURE_2D, treeleaf2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pst1.x,pst1.y,pst1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pst2.x,pst2.y,pst2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pst3.x,pst3.y,pst3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pst4.x,pst4.y,pst4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pst5.x,pst5.y,pst5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pst6.x,pst6.y,pst6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pst7.x,pst7.y,pst7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pst8.x,pst8.y,pst8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pst9.x,pst9.y,pst9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pst10.x,pst10.y,pst10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pst11.x,pst11.y,pst11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pst12.x,pst12.y,pst12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pst13.x,pst13.y,pst13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pst14.x,pst14.y,pst14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pst15.x,pst15.y,pst15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pst16.x,pst16.y,pst16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pst17.x,pst17.y,pst17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pst18.x,pst18.y,pst18.z);
	glTexCoord2d(1, 1);
	glEnd();


	//second tree
	//glPushMatrix();
	glTranslatef(0,-10,-20);
	glTranslatef(0,0,-20);
	point jst1(0,0,0),jst2(2,0,0),jst3(2,0,-2),jst4(0,0,-2);
	cube cstj(jst1,jst2,jst3,jst4,10,treewood2);
	cstj.draw();

	point psjt1(-5.0f, -5.0f, -4.0f),pstj2(5.0f, -5.0f, -4.0f),pstj3(0.0f, 5.0f, 0.0f),pstj4(-5.0f, -5.0f, 4.0f),pstj5(5.0f, -5.0f, 4.0f),pstj6(0.0f, 5.0f, 0.0f),
		pstj7(-5.0f, -5.0f, 4.0f),pstj8(-5.0f, -5.0f, -4.0f),pstj9(0.0f, 5.0f, 0.0f),pstj10(5.0f, -5.0f, -4.0f),pstj11(5.0f, -5.0f, 4.0f),pstj12(0.0f, 5.0f, 0.0f),
		pstj13(5.0f, -5.0f, -4.0f),pstj14(5.0f, -5.0f, 4.0f),pstj15(-5.0f, -5.0f, -4.0f),pstj16(5.0f, -5.0f, 4.0f),pstj17(-5.0f, -5.0f, -4.0f),pstj18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(0,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(psjt1.x,psjt1.y,psjt1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstj2.x,pstj2.y,pstj2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstj3.x,pstj3.y,pstj3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstj4.x,pstj4.y,pstj4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pstj5.x,pstj5.y,pstj5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstj6.x,pstj6.y,pstj6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstj7.x,pstj7.y,pstj7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstj8.x,pstj8.y,pstj8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pstj9.x,pstj9.y,pstj9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstj10.x,pstj10.y,pstj10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstj11.x,pstj11.y,pstj11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstj12.x,pstj12.y,pstj12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pstj13.x,pstj13.y,pstj13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstj14.x,pstj14.y,pstj14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstj15.x,pstj15.y,pstj15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstj16.x,pstj16.y,pstj16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pstj17.x,pstj17.y,pstj17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstj18.x,pstj18.y,pstj18.z);
	glTexCoord2d(1, 1);
	glEnd();



	//third tree
	//glPushMatrix();
	glTranslatef(0,-10,-20);
	glTranslatef(0,0,-20);
	point kst1(0,0,0),kst2(2,0,0),kst3(2,0,-2),kst4(0,0,-2);
	cube cskt(kst1,kst2,kst3,kst4,10,treewood1);
	cskt.draw();

	point pstk1(-5.0f, -5.0f, -4.0f),pstk2(5.0f, -5.0f, -4.0f),pstk3(0.0f, 5.0f, 0.0f),pstk4(-5.0f, -5.0f, 4.0f),pstk5(5.0f, -5.0f, 4.0f),pstk6(0.0f, 5.0f, 0.0f),
		pstk7(-5.0f, -5.0f, 4.0f),pstk8(-5.0f, -5.0f, -4.0f),pstk9(0.0f, 5.0f, 0.0f),pstk10(5.0f, -5.0f, -4.0f),pstk11(5.0f, -5.0f, 4.0f),pstk12(0.0f, 5.0f, 0.0f),
		pstk13(5.0f, -5.0f, -4.0f),pstk14(5.0f, -5.0f, 4.0f),pstk15(-5.0f, -5.0f, -4.0f),pstk16(5.0f, -5.0f, 4.0f),pstk17(-5.0f, -5.0f, -4.0f),pstk18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf3);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pstk1.x,pstk1.y,pstk1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstk2.x,pstk2.y,pstk2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstk3.x,pstk3.y,pstk3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstk4.x,pstk4.y,pstk4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pstk5.x,pstk5.y,pstk5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstk6.x,pstk6.y,pstk6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstk7.x,pstk7.y,pstk7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstk8.x,pstk8.y,pstk8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pstk9.x,pstk9.y,pstk9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstk10.x,pstk10.y,pstk10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstk11.x,pstk11.y,pstk11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstk12.x,pstk12.y,pstk12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pstk13.x,pstk13.y,pstk13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstk14.x,pstk14.y,pstk14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstk15.x,pstk15.y,pstk15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstk16.x,pstk16.y,pstk16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pstk17.x,pstk17.y,pstk17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstk18.x,pstk18.y,pstk18.z);
	glTexCoord2d(1, 1);
	glEnd();

	//third house
	glTranslatef(-2,-11,-20);
	glTranslatef(0,0,-20);
	point ishhh1(0,0,0),ishhh2(9,0,0),ishhh3(9,0,-8),ishhh4(0,0,-9);
	cube cshhh(ishhh1,ishhh2,ishhh3,ishhh4,7,house3);
	cshhh.draw();

	point pshhh1(-5.0f, -5.0f, -5.0f),pshhh2(5.0f, -5.0f, -5.0f),pshhh3(0.0f, 5.0f, 0.0f),pshhh4(-5.0f, -5.0f, 5.0f),pshhh5(5.0f, -5.0f, 5.0f),pshhh6(0.0f, 5.0f, 0.0f),
		pshhh7(-5.0f, -5.0f, 5.0f),pshhh8(-5.0f, -5.0f, -5.0f),pshhh9(0.0f, 5.0f, 0.0f),pshhh10(5.0f, -5.0f, -5.0f),pshhh11(5.0f, -5.0f, 5.0f),pshhh12(0.0f, 5.0f, 0.0f),
		pshhh13(5.0f, -5.0f, -5.0f),pshhh14(5.0f, -5.0f, 5.0f),pshhh15(-5.0f, -5.0f, -5.0f),pshhh16(5.0f, -5.0f, 5.0f),pshhh17(-5.0f, -5.0f, -5.0f),pshhh18(-5.0f, -5.0f, 5.0f);
	
	glTranslatef(4,11,-5);
	glBindTexture(GL_TEXTURE_2D, roof2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pshhh1.x,pshhh1.y,pshhh1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pshhh2.x,pshhh2.y,pshhh2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pshhh3.x,pshhh3.y,pshhh3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pshhh4.x,pshhh4.y,pshhh4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pshhh5.x,pshhh5.y,pshhh5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pshhh6.x,pshhh6.y,pshhh6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pshhh7.x,pshhh7.y,pshhh7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pshhh8.x,pshhh8.y,pshhh8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pshhh9.x,pshhh9.y,pshhh9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pshhh10.x,pshhh10.y,pshhh10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pshhh11.x,pshhh11.y,pshhh11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pshhh12.x,pshhh12.y,pshhh12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pshhh13.x,pshhh13.y,pshhh13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pshhh14.x,pshhh14.y,pshhh14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pshhh15.x,pshhh15.y,pshhh15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pshhh16.x,pshhh16.y,pshhh16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pshhh17.x,pshhh17.y,pshhh17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pshhh18.x,pshhh18.y,pshhh18.z);
	glTexCoord2d(1, 1);
	glEnd();

	//tree
	//glPushMatrix();
	glTranslatef(0,-11,-20);
	point istt1(0,0,0),istt2(2,0,0),istt3(2,0,-2),istt4(0,0,-2);
	cube csitt(istt1,istt2,istt3,istt4,7,treewood2);
	csitt.draw();

	point pstt1(-5.0f, -5.0f, -4.0f),pstt2(5.0f, -5.0f, -4.0f),pstt3(0.0f, 5.0f, 0.0f),pstt4(-5.0f, -5.0f, 4.0f),pstt5(5.0f, -5.0f, 4.0f),pstt6(0.0f, 5.0f, 0.0f),
		pstt7(-5.0f, -5.0f, 4.0f),pstt8(-5.0f, -5.0f, -4.0f),pstt9(0.0f, 5.0f, 0.0f),pstt10(5.0f, -5.0f, -4.0f),pstt11(5.0f, -5.0f, 4.0f),pstt12(0.0f, 5.0f, 0.0f),
		pstt13(5.0f, -5.0f, -4.0f),pstt14(5.0f, -5.0f, 4.0f),pstt15(-5.0f, -5.0f, -4.0f),pstt16(5.0f, -5.0f, 4.0f),pstt17(-5.0f, -5.0f, -4.0f),pstt18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-1);
	glBindTexture(GL_TEXTURE_2D, treeleaf2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pstt1.x,pstt1.y,pstt1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstt2.x,pstt2.y,pstt2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstt3.x,pstt3.y,pstt3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstt4.x,pstt4.y,pstt4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pstt5.x,pstt5.y,pstt5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstt6.x,pstt6.y,pstt6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstt7.x,pstt7.y,pstt7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstt8.x,pstt8.y,pstt8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pstt9.x,pstt9.y,pstt9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstt10.x,pstt10.y,pstt10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstt11.x,pstt11.y,pstt11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstt12.x,pstt12.y,pstt12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pstt13.x,pstt13.y,pstt13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstt14.x,pstt14.y,pstt14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pstt15.x,pstt15.y,pstt15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pstt16.x,pstt16.y,pstt16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pstt17.x,pstt17.y,pstt17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pstt18.x,pstt18.y,pstt18.z);
	glTexCoord2d(1, 1);
	glEnd();

	//second tree
	//glPushMatrix();
	glTranslatef(0,-11,-20);
	glTranslatef(0,0,-20);
	point jstt1(0,0,0),jstt2(2,0,0),jstt3(2,0,-2),jstt4(0,0,-2);
	cube csttj(jstt1,jstt2,jstt3,jstt4,10,treewood2);
	csttj.draw();

	point psjtt1(-5.0f, -5.0f, -4.0f),psttj2(5.0f, -5.0f, -4.0f),psttj3(0.0f, 5.0f, 0.0f),psttj4(-5.0f, -5.0f, 4.0f),psttj5(5.0f, -5.0f, 4.0f),psttj6(0.0f, 5.0f, 0.0f),
		psttj7(-5.0f, -5.0f, 4.0f),psttj8(-5.0f, -5.0f, -4.0f),psttj9(0.0f, 5.0f, 0.0f),psttj10(5.0f, -5.0f, -4.0f),psttj11(5.0f, -5.0f, 4.0f),psttj12(0.0f, 5.0f, 0.0f),
		psttj13(5.0f, -5.0f, -4.0f),psttj14(5.0f, -5.0f, 4.0f),psttj15(-5.0f, -5.0f, -4.0f),psttj16(5.0f, -5.0f, 4.0f),psttj17(-5.0f, -5.0f, -4.0f),psttj18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(0,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(psjtt1.x,psjtt1.y,psjtt1.z);
	glTexCoord2d(1, 0);
	glVertex3d(psttj2.x,psttj2.y,psttj2.z);
	glTexCoord2d(1, 1);
	glVertex3d(psttj3.x,psttj3.y,psttj3.z);
	glTexCoord2d(0, 1);
	glVertex3d(psttj4.x,psttj4.y,psttj4.z);
	glTexCoord2d(0, 0);
    glVertex3d(psttj5.x,psttj5.y,psttj5.z);
	glTexCoord2d(1, 0);
	glVertex3d(psttj6.x,psttj6.y,psttj6.z);
	glTexCoord2d(1, 1);
	glVertex3d(psttj7.x,psttj7.y,psttj7.z);
	glTexCoord2d(0, 1);
	glVertex3d(psttj8.x,psttj8.y,psttj8.z);
	glTexCoord2d(0, 0);
	glVertex3d(psttj9.x,psttj9.y,psttj9.z);
	glTexCoord2d(1, 0);
	glVertex3d(psttj10.x,psttj10.y,psttj10.z);
	glTexCoord2d(1, 1);
	glVertex3d(psttj11.x,psttj11.y,psttj11.z);
	glTexCoord2d(0, 1);
	glVertex3d(psttj12.x,psttj12.y,psttj12.z);
	glTexCoord2d(0, 0);
	glVertex3d(psttj13.x,psttj13.y,psttj13.z);
	glTexCoord2d(1, 0);
	glVertex3d(psttj14.x,psttj14.y,psttj14.z);
	glTexCoord2d(1, 1);
	glVertex3d(psttj15.x,psttj15.y,psttj15.z);
	glTexCoord2d(0, 1);
	glVertex3d(psttj16.x,psttj16.y,psttj16.z);
	glTexCoord2d(0, 0);
	glVertex3d(psttj17.x,psttj17.y,psttj17.z);
	glTexCoord2d(1, 0);
	glVertex3d(psttj18.x,psttj18.y,psttj18.z);
	glTexCoord2d(1, 1);
	glEnd();
	//glPopMatrix();
	
	//third tree
	//glPushMatrix();
	glTranslatef(-1,-11,-20);
	glTranslatef(0,0,-20);
	point kstt1(0,0,0),kstt2(2,0,0),kstt3(2,0,-2),kstt4(0,0,-2);
	cube csktt(kstt1,kstt2,kstt3,kstt4,10,treewood1);
	csktt.draw();

	point psttk1(-5.0f, -5.0f, -4.0f),psttk2(5.0f, -5.0f, -4.0f),psttk3(0.0f, 5.0f, 0.0f),psttk4(-5.0f, -5.0f, 4.0f),psttk5(5.0f, -5.0f, 4.0f),psttk6(0.0f, 5.0f, 0.0f),
		psttk7(-5.0f, -5.0f, 4.0f),psttk8(-5.0f, -5.0f, -4.0f),psttk9(0.0f, 5.0f, 0.0f),psttk10(5.0f, -5.0f, -4.0f),psttk11(5.0f, -5.0f, 4.0f),psttk12(0.0f, 5.0f, 0.0f),
		psttk13(5.0f, -5.0f, -4.0f),psttk14(5.0f, -5.0f, 4.0f),psttk15(-5.0f, -5.0f, -4.0f),psttk16(5.0f, -5.0f, 4.0f),psttk17(-5.0f, -5.0f, -4.0f),psttk18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(0,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf3);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(psttk1.x,psttk1.y,psttk1.z);
	glTexCoord2d(1, 0);
	glVertex3d(psttk2.x,psttk2.y,psttk2.z);
	glTexCoord2d(1, 1);
	glVertex3d(psttk3.x,psttk3.y,psttk3.z);
	glTexCoord2d(0, 1);
	glVertex3d(psttk4.x,psttk4.y,psttk4.z);
	glTexCoord2d(0, 0);
    glVertex3d(psttk5.x,psttk5.y,psttk5.z);
	glTexCoord2d(1, 0);
	glVertex3d(psttk6.x,psttk6.y,psttk6.z);
	glTexCoord2d(1, 1);
	glVertex3d(psttk7.x,psttk7.y,psttk7.z);
	glTexCoord2d(0, 1);
	glVertex3d(psttk8.x,psttk8.y,psttk8.z);
	glTexCoord2d(0, 0);
	glVertex3d(psttk9.x,psttk9.y,psttk9.z);
	glTexCoord2d(1, 0);
	glVertex3d(psttk10.x,psttk10.y,psttk10.z);
	glTexCoord2d(1, 1);
	glVertex3d(psttk11.x,psttk11.y,psttk11.z);
	glTexCoord2d(0, 1);
	glVertex3d(psttk12.x,psttk12.y,psttk12.z);
	glTexCoord2d(0, 0);
	glVertex3d(psttk13.x,psttk13.y,psttk13.z);
	glTexCoord2d(1, 0);
	glVertex3d(psttk14.x,psttk14.y,psttk14.z);
	glTexCoord2d(1, 1);
	glVertex3d(psttk15.x,psttk15.y,psttk15.z);
	glTexCoord2d(0, 1);
	glVertex3d(psttk16.x,psttk16.y,psttk16.z);
	glTexCoord2d(0, 0);
	glVertex3d(psttk17.x,psttk17.y,psttk17.z);
	glTexCoord2d(1, 0);
	glVertex3d(psttk18.x,psttk18.y,psttk18.z);
	glTexCoord2d(1, 1);
	glEnd();





	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0);
	glTranslatef(0,0,-20);
	glBindTexture(GL_TEXTURE_2D,rollercoaster1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
	glTexCoord2d(1, 0);
	glVertex3d(20,0,0);
	glTexCoord2d(1, 1);
	glVertex3d(20,0,-800);
	glTexCoord2d(0, 1);
	glVertex3d(0,0,-800);
	glEnd();
	glPopMatrix();

    //first building
	glTranslatef(-55,-2,-20);
	point b1(0,0,0),b2(5,0,0),b3(5,0,-5),b4(0,0,-5);
	cube c1(b1,b2,b3,b4,20,building1);
	c1.draw();

	
	//second building
	glPushMatrix();
	glTranslated(0,0,-20);
	point b5(0,0,0),b6(5,0,0),b7(5,0,-5),b8(0,0,-5);
	cube c2(b5,b6,b7,b8,20,building2);
	c2.draw();
    glPopMatrix();


	

	//third building
	glTranslatef(0,0,-20);
	point b9(0,0,0),b10(5,0,0),b11(5,0,-5),b12(0,0,-5);
	cube c3(b9,b10,b11,b12,20,building3);
	c3.draw();

	//forth building
	glTranslatef(0,0,-20);
	point b13(0,0,0),b14(5,0,0),b15(5,0,-5),b16(0,0,-3);
	cube c4(b13,b14,b15,b16,20,building4);
	c4.draw();

	//fifth building
	glTranslatef(0,0,-20);
	point b17(0,0,0),b18(5,0,0),b19(5,0,-5),b20(0,0,-5);
	cube c5(b17,b18,b19,b20,20,building5);
	c5.draw();

	//sixth building
	glTranslatef(0,0,-20);
	point b21(0,0,0),b22(5,0,0),b23(5,0,-5),b24(0,0,-5);
	cube c6(b21,b22,b23,b24,20,building6);
	c6.draw();
	//seventh building
	glTranslatef(0,0,-20);
	point b25(0,0,0),b26(5,0,0),b27(5,0,-5),b28(0,0,-5);
	cube c7(b25,b26,b27,b28,20,building7);
	c7.draw();
	//eighdth building
	glTranslatef(0,0,-20);
	point b29(0,0,0),b30(5,0,0),b31(5,0,-5),b32(0,0,-5);
	cube c8(b29,b30,b31,b32,20,building1);
	c8.draw();

	//nineth building
	glTranslated(0,0,-20);
	point b33(0,0,0),b34(5,0,0),b35(5,0,-5),b36(0,0,-5);
	cube c9(b33,b34,b35,b36,20,building2);
	c9.draw();
	//tenth building
	glTranslatef(0,0,-20);
	point b37(0,0,0),b38(5,0,0),b39(5,0,-5),b40(0,0,-5);
	cube c10(b37,b38,b39,b40,20,building3);
	c10.draw();

	//11th building
	glTranslatef(0,0,-20);
	point b41(0,0,0),b42(5,0,0),b43(5,0,-5),b44(0,0,-3);
	cube c11(b41,b42,b43,b44,20,building4);
	c11.draw();

	//12th building
	glTranslatef(0,0,-20);
	point b45(0,0,0),b46(5,0,0),b47(5,0,-5),b48(0,0,-5);
	cube c12(b45,b46,b47,b48,20,building5);
	c12.draw();

	//13th building
	glTranslatef(0,0,-20);
	point b49(0,0,0),b50(5,0,0),b51(5,0,-5),b52(0,0,-5);
	cube c13(b49,b50,b51,b52,20,building6);
	c13.draw();
	//14th building
	glTranslatef(0,0,-20);
	point b53(0,0,0),b54(5,0,0),b55(5,0,-5),b56(0,0,-5);
	cube c14(b53,b54,b55,b56,20,building1);
	c14.draw();

	//15th building
	glTranslated(0,0,-20);
	point b57(0,0,0),b58(5,0,0),b59(5,0,-5),b60(0,0,-5);
	cube c15(b57,b58,b59,b60,20,building2);
	c15.draw();
	//16th building
	glTranslatef(0,0,-20);
	point b61(0,0,0),b62(5,0,0),b63(5,0,-5),b64(0,0,-5);
	cube c16(b61,b62,b63,b64,20,building3);
	c16.draw();

	//17th building
	glTranslatef(0,0,-20);
	point b65(0,0,0),b66(5,0,0),b67(5,0,-5),b68(0,0,-3);
	cube c17(b65,b66,b67,b68,20,building4);
	c17.draw();

	//18th building
	glTranslatef(0,0,-20);
	point b69(0,0,0),b70(5,0,0),b71(5,0,-5),b72(0,0,-5);
	cube c18(b69,b70,b71,b72,20,building5);
	c18.draw();

	//19th building
	glTranslatef(0,0,-20);
	point b73(0,0,0),b74(5,0,0),b75(5,0,-5),b76(0,0,-5);
	cube c19(b73,b74,b75,b76,20,building6);
	c19.draw();

	//first house
	//glPushMatrix();
	glTranslatef(0,0,-20);
	//glTranslatef(50,0,-20);
	point ih1(0,0,0),ih2(8,0,0),ih3(8,0,-8),ih4(0,0,-8);
	cube ch(ih1,ih2,ih3,ih4,7,house1);
	ch.draw();

	point h1(-5.0f, -5.0f, -4.0f),h2(5.0f, -5.0f, -4.0f),h3(0.0f, 5.0f, 0.0f),h4(-5.0f, -5.0f, 4.0f),h5(5.0f, -5.0f, 4.0f),h6(0.0f, 5.0f, 0.0f),
		h7(-5.0f, -5.0f, 4.0f),h8(-5.0f, -5.0f, -4.0f),h9(0.0f, 5.0f, 0.0f),h10(5.0f, -5.0f, -4.0f),h11(5.0f, -5.0f, 4.0f),h12(0.0f, 5.0f, 0.0f),
		h13(5.0f, -5.0f, -4.0f),h14(5.0f, -5.0f, 4.0f),h15(-5.0f, -5.0f, -4.0f),h16(5.0f, -5.0f, 4.0f),h17(-5.0f, -5.0f, -4.0f),h18(-5.0f, -5.0f, 4.0f);
	glTranslatef(5,11,-1);
	glBindTexture(GL_TEXTURE_2D, roof2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(h1.x,h1.y,h1.z);
	glTexCoord2d(1, 0);
	glVertex3d(h2.x,h2.y,h2.z);
	glTexCoord2d(1, 1);
	glVertex3d(h3.x,h3.y,h3.z);
	glTexCoord2d(0, 1);
	glVertex3d(h4.x,h4.y,h4.z);
	glTexCoord2d(0, 0);
    glVertex3d(h5.x,h5.y,h5.z);
	glTexCoord2d(1, 0);
	glVertex3d(h6.x,h6.y,h6.z);
	glTexCoord2d(1, 1);
	glVertex3d(h7.x,h7.y,h7.z);
	glTexCoord2d(0, 1);
	glVertex3d(h8.x,h8.y,h8.z);
	glTexCoord2d(0, 0);
	glVertex3d(h9.x,h9.y,h9.z);
	glTexCoord2d(1, 0);
	glVertex3d(h10.x,h10.y,h10.z);
	glTexCoord2d(1, 1);
	glVertex3d(h11.x,h11.y,h11.z);
	glTexCoord2d(0, 1);
	glVertex3d(h12.x,h12.y,h12.z);
	glTexCoord2d(0, 0);
	glVertex3d(h13.x,h13.y,h13.z);
	glTexCoord2d(1, 0);
	glVertex3d(h14.x,h14.y,h14.z);
	glTexCoord2d(1, 1);
	glVertex3d(h15.x,h15.y,h15.z);
	glTexCoord2d(0, 1);
	glVertex3d(h16.x,h16.y,h16.z);
	glTexCoord2d(0, 0);
	glVertex3d(h17.x,h17.y,h17.z);
	glTexCoord2d(1, 0);
	glVertex3d(h18.x,h18.y,h18.z);
	glTexCoord2d(1, 1);
	glEnd();
	//glPopMatrix();

	
	//firsrt tree
	//glPushMatrix();
	glTranslatef(1,-11,-20);
	point i1(0,0,0),i2(2,0,0),i3(2,0,-2),i4(0,0,-2);
	cube c(i1,i2,i3,i4,7,treewood2);
	c.draw();

	point p1(-5.0f, -5.0f, -4.0f),p2(5.0f, -5.0f, -4.0f),p3(0.0f, 5.0f, 0.0f),p4(-5.0f, -5.0f, 4.0f),p5(5.0f, -5.0f, 4.0f),p6(0.0f, 5.0f, 0.0f),
		p7(-5.0f, -5.0f, 4.0f),p8(-5.0f, -5.0f, -4.0f),p9(0.0f, 5.0f, 0.0f),p10(5.0f, -5.0f, -4.0f),p11(5.0f, -5.0f, 4.0f),p12(0.0f, 5.0f, 0.0f),
		p13(5.0f, -5.0f, -4.0f),p14(5.0f, -5.0f, 4.0f),p15(-5.0f, -5.0f, -4.0f),p16(5.0f, -5.0f, 4.0f),p17(-5.0f, -5.0f, -4.0f),p18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-1);
	glBindTexture(GL_TEXTURE_2D, treeleaf2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(p1.x,p1.y,p1.z);
	glTexCoord2d(1, 0);
	glVertex3d(p2.x,p2.y,p2.z);
	glTexCoord2d(1, 1);
	glVertex3d(p3.x,p3.y,p3.z);
	glTexCoord2d(0, 1);
	glVertex3d(p4.x,p4.y,p4.z);
	glTexCoord2d(0, 0);
    glVertex3d(p5.x,p5.y,p5.z);
	glTexCoord2d(1, 0);
	glVertex3d(p6.x,p6.y,p6.z);
	glTexCoord2d(1, 1);
	glVertex3d(p7.x,p7.y,p7.z);
	glTexCoord2d(0, 1);
	glVertex3d(p8.x,p8.y,p8.z);
	glTexCoord2d(0, 0);
	glVertex3d(p9.x,p9.y,p9.z);
	glTexCoord2d(1, 0);
	glVertex3d(p10.x,p10.y,p10.z);
	glTexCoord2d(1, 1);
	glVertex3d(p11.x,p11.y,p11.z);
	glTexCoord2d(0, 1);
	glVertex3d(p12.x,p12.y,p12.z);
	glTexCoord2d(0, 0);
	glVertex3d(p13.x,p13.y,p13.z);
	glTexCoord2d(1, 0);
	glVertex3d(p14.x,p14.y,p14.z);
	glTexCoord2d(1, 1);
	glVertex3d(p15.x,p15.y,p15.z);
	glTexCoord2d(0, 1);
	glVertex3d(p16.x,p16.y,p16.z);
	glTexCoord2d(0, 0);
	glVertex3d(p17.x,p17.y,p17.z);
	glTexCoord2d(1, 0);
	glVertex3d(p18.x,p18.y,p18.z);
	glTexCoord2d(1, 1);
	glEnd();
	//glPopMatrix();

	//second tree
	//glPushMatrix();
	glTranslatef(0,-11,-20);
	glTranslatef(0,-2,-20);
	point j1(0,0,0),j2(2,0,0),j3(2,0,-2),j4(0,0,-2);
	cube cj(j1,j2,j3,j4,10,treewood2);
	cj.draw();

	point pj1(-5.0f, -5.0f, -4.0f),pj2(5.0f, -5.0f, -4.0f),pj3(0.0f, 5.0f, 0.0f),pj4(-5.0f, -5.0f, 4.0f),pj5(5.0f, -5.0f, 4.0f),pj6(0.0f, 5.0f, 0.0f),
		pj7(-5.0f, -5.0f, 4.0f),pj8(-5.0f, -5.0f, -4.0f),pj9(0.0f, 5.0f, 0.0f),pj10(5.0f, -5.0f, -4.0f),pj11(5.0f, -5.0f, 4.0f),pj12(0.0f, 5.0f, 0.0f),
		pj13(5.0f, -5.0f, -4.0f),pj14(5.0f, -5.0f, 4.0f),pj15(-5.0f, -5.0f, -4.0f),pj16(5.0f, -5.0f, 4.0f),pj17(-5.0f, -5.0f, -4.0f),pj18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pj1.x,pj1.y,pj1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pj2.x,pj2.y,pj2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pj3.x,pj3.y,pj3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pj4.x,pj4.y,pj4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pj5.x,pj5.y,pj5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pj6.x,pj6.y,pj6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pj7.x,pj7.y,pj7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pj8.x,pj8.y,pj8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pj9.x,pj9.y,pj9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pj10.x,pj10.y,pj10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pj11.x,pj11.y,pj11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pj12.x,pj12.y,pj12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pj13.x,pj13.y,pj13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pj14.x,pj14.y,pj14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pj15.x,pj15.y,pj15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pj16.x,pj16.y,pj16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pj17.x,pj17.y,pj17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pj18.x,pj18.y,pj18.z);
	glTexCoord2d(1, 1);
	glEnd();
	//glPopMatrix();
	
	//third tree
	glPushMatrix();
	glTranslatef(0,-11,-20);
	glTranslatef(0,0,-20);
	point k1(0,0,0),k2(2,0,0),k3(2,0,-2),k4(0,0,-2);
	cube ck(k1,k2,k3,k4,10,treewood1);
	ck.draw();

	point pk1(-5.0f, -5.0f, -4.0f),pk2(5.0f, -5.0f, -4.0f),pk3(0.0f, 5.0f, 0.0f),pk4(-5.0f, -5.0f, 4.0f),pk5(5.0f, -5.0f, 4.0f),pk6(0.0f, 5.0f, 0.0f),
		pk7(-5.0f, -5.0f, 4.0f),pk8(-5.0f, -5.0f, -4.0f),pk9(0.0f, 5.0f, 0.0f),pk10(5.0f, -5.0f, -4.0f),pk11(5.0f, -5.0f, 4.0f),pk12(0.0f, 5.0f, 0.0f),
		pk13(5.0f, -5.0f, -4.0f),pk14(5.0f, -5.0f, 4.0f),pk15(-5.0f, -5.0f, -4.0f),pk16(5.0f, -5.0f, 4.0f),pk17(-5.0f, -5.0f, -4.0f),pk18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf3);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pk1.x,pk1.y,pk1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pk2.x,pk2.y,pk2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pk3.x,pk3.y,pk3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pk4.x,pk4.y,pk4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pk5.x,pk5.y,pk5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pk6.x,pk6.y,pk6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pk7.x,pk7.y,pk7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pk8.x,pk8.y,pk8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pk9.x,pk9.y,pk9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pk10.x,pk10.y,pk10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pk11.x,pk11.y,pk11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pk12.x,pk12.y,pk12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pk13.x,pk13.y,pk13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pk14.x,pk14.y,pk14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pk15.x,pk15.y,pk15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pk16.x,pk16.y,pk16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pk17.x,pk17.y,pk17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pk18.x,pk18.y,pk18.z);
	glTexCoord2d(1, 1);
	glEnd();
	glPopMatrix();



	//second house
	glPushMatrix();
	glTranslatef(-2,-11,-20);
	point ihh1(0,0,0),ihh2(9,0,0),ihh3(9,0,-9),ihh4(0,0,-9);
	cube chh(ihh1,ihh2,ihh3,ihh4,7,house2);
	chh.draw();

	point phh1(-5.0f, -5.0f, -5.0f),phh2(5.0f, -5.0f, -5.0f),phh3(0.0f, 5.0f, 0.0f),phh4(-5.0f, -5.0f, 5.0f),phh5(5.0f, -5.0f, 5.0f),phh6(0.0f, 5.0f, 0.0f),
		phh7(-5.0f, -5.0f, 5.0f),phh8(-5.0f, -5.0f, -5.0f),phh9(0.0f, 5.0f, 0.0f),phh10(5.0f, -5.0f, -5.0f),phh11(5.0f, -5.0f, 5.0f),phh12(0.0f, 5.0f, 0.0f),
		phh13(5.0f, -5.0f, -5.0f),phh14(5.0f, -5.0f, 5.0f),phh15(-5.0f, -5.0f, -5.0f),phh16(5.0f, -5.0f, 5.0f),phh17(-5.0f, -5.0f, -5.0f),phh18(-5.0f, -5.0f, 5.0f);
	
	glTranslatef(5.7,11,-1);
	glBindTexture(GL_TEXTURE_2D, roof2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(phh1.x,phh1.y,phh1.z);
	glTexCoord2d(1, 0);
	glVertex3d(phh2.x,phh2.y,phh2.z);
	glTexCoord2d(1, 1);
	glVertex3d(phh3.x,phh3.y,phh3.z);
	glTexCoord2d(0, 1);
	glVertex3d(phh4.x,phh4.y,phh4.z);
	glTexCoord2d(0, 0);
    glVertex3d(phh5.x,phh5.y,phh5.z);
	glTexCoord2d(1, 0);
	glVertex3d(phh6.x,phh6.y,phh6.z);
	glTexCoord2d(1, 1);
	glVertex3d(phh7.x,phh7.y,phh7.z);
	glTexCoord2d(0, 1);
	glVertex3d(phh8.x,phh8.y,phh8.z);
	glTexCoord2d(0, 0);
	glVertex3d(phh9.x,phh9.y,phh9.z);
	glTexCoord2d(1, 0);
	glVertex3d(phh10.x,phh10.y,phh10.z);
	glTexCoord2d(1, 1);
	glVertex3d(phh11.x,phh11.y,phh11.z);
	glTexCoord2d(0, 1);
	glVertex3d(phh12.x,phh12.y,phh12.z);
	glTexCoord2d(0, 0);
	glVertex3d(phh13.x,phh13.y,phh13.z);
	glTexCoord2d(1, 0);
	glVertex3d(phh14.x,phh14.y,phh14.z);
	glTexCoord2d(1, 1);
	glVertex3d(phh15.x,phh15.y,phh15.z);
	glTexCoord2d(0, 1);
	glVertex3d(phh16.x,phh16.y,phh16.z);
	glTexCoord2d(0, 0);
	glVertex3d(phh17.x,phh17.y,phh17.z);
	glTexCoord2d(1, 0);
	glVertex3d(phh18.x,phh18.y,phh18.z);
	glTexCoord2d(1, 1);
	glEnd();
	glPopMatrix();

	//firsrt tree
	glPushMatrix();
	glTranslatef(0,-11,-20);
	point it1(0,0,0),it2(2,0,0),it3(2,0,-2),it4(0,0,-2);
	cube cit(it1,it2,it3,it4,7,treewood2);
	cit.draw();

	point pt1(-5.0f, -5.0f, -4.0f),pt2(5.0f, -5.0f, -4.0f),pt3(0.0f, 5.0f, 0.0f),pt4(-5.0f, -5.0f, 4.0f),pt5(5.0f, -5.0f, 4.0f),pt6(0.0f, 5.0f, 0.0f),
		pt7(-5.0f, -5.0f, 4.0f),pt8(-5.0f, -5.0f, -4.0f),pt9(0.0f, 5.0f, 0.0f),pt10(5.0f, -5.0f, -4.0f),pt11(5.0f, -5.0f, 4.0f),pt12(0.0f, 5.0f, 0.0f),
		pt13(5.0f, -5.0f, -4.0f),pt14(5.0f, -5.0f, 4.0f),pt15(-5.0f, -5.0f, -4.0f),pt16(5.0f, -5.0f, 4.0f),pt17(-5.0f, -5.0f, -4.0f),pt18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-1);
	glBindTexture(GL_TEXTURE_2D, treeleaf2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pt1.x,pt1.y,pt1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pt2.x,pt2.y,pt2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pt3.x,pt3.y,pt3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pt4.x,pt4.y,pt4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pt5.x,pt5.y,pt5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pt6.x,pt6.y,pt6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pt7.x,pt7.y,pt7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pt8.x,pt8.y,pt8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pt9.x,pt9.y,pt9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pt10.x,pt10.y,pt10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pt11.x,pt11.y,pt11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pt12.x,pt12.y,pt12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pt13.x,pt13.y,pt13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pt14.x,pt14.y,pt14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pt15.x,pt15.y,pt15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pt16.x,pt16.y,pt16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pt17.x,pt17.y,pt17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pt18.x,pt18.y,pt18.z);
	glTexCoord2d(1, 1);
	glEnd();
	glPopMatrix();

	//second tree
	glPushMatrix();
	glTranslatef(0,-11,-20);
	glTranslatef(0,0,-20);
	point jt1(0,0,0),jt2(2,0,0),jt3(2,0,-2),jt4(0,0,-2);
	cube ctj(jt1,jt2,jt3,jt4,10,treewood2);
	ctj.draw();

	point pjt1(-5.0f, -5.0f, -4.0f),ptj2(5.0f, -5.0f, -4.0f),ptj3(0.0f, 5.0f, 0.0f),ptj4(-5.0f, -5.0f, 4.0f),ptj5(5.0f, -5.0f, 4.0f),ptj6(0.0f, 5.0f, 0.0f),
		ptj7(-5.0f, -5.0f, 4.0f),ptj8(-5.0f, -5.0f, -4.0f),ptj9(0.0f, 5.0f, 0.0f),ptj10(5.0f, -5.0f, -4.0f),ptj11(5.0f, -5.0f, 4.0f),ptj12(0.0f, 5.0f, 0.0f),
		ptj13(5.0f, -5.0f, -4.0f),ptj14(5.0f, -5.0f, 4.0f),ptj15(-5.0f, -5.0f, -4.0f),ptj16(5.0f, -5.0f, 4.0f),ptj17(-5.0f, -5.0f, -4.0f),ptj18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(0,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pjt1.x,pjt1.y,pjt1.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptj2.x,ptj2.y,ptj2.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptj3.x,ptj3.y,ptj3.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptj4.x,ptj4.y,ptj4.z);
	glTexCoord2d(0, 0);
    glVertex3d(ptj5.x,ptj5.y,ptj5.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptj6.x,ptj6.y,ptj6.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptj7.x,ptj7.y,ptj7.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptj8.x,ptj8.y,ptj8.z);
	glTexCoord2d(0, 0);
	glVertex3d(ptj9.x,ptj9.y,ptj9.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptj10.x,ptj10.y,ptj10.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptj11.x,ptj11.y,ptj11.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptj12.x,ptj12.y,ptj12.z);
	glTexCoord2d(0, 0);
	glVertex3d(ptj13.x,ptj13.y,ptj13.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptj14.x,ptj14.y,ptj14.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptj15.x,ptj15.y,ptj15.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptj16.x,ptj16.y,ptj16.z);
	glTexCoord2d(0, 0);
	glVertex3d(ptj17.x,ptj17.y,ptj17.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptj18.x,ptj18.y,ptj18.z);
	glTexCoord2d(1, 1);
	glEnd();
	glPopMatrix();
	
	//third tree
	glPushMatrix();
	glTranslatef(0,-11,-20);
	glTranslatef(0,0,-20);
	point kt1(0,0,0),kt2(2,0,0),kt3(2,0,-2),kt4(0,0,-2);
	cube ckt(kt1,kt2,kt3,kt4,10,treewood1);
	ckt.draw();

	point ptk1(-5.0f, -5.0f, -4.0f),ptk2(5.0f, -5.0f, -4.0f),ptk3(0.0f, 5.0f, 0.0f),ptk4(-5.0f, -5.0f, 4.0f),ptk5(5.0f, -5.0f, 4.0f),ptk6(0.0f, 5.0f, 0.0f),
		ptk7(-5.0f, -5.0f, 4.0f),ptk8(-5.0f, -5.0f, -4.0f),ptk9(0.0f, 5.0f, 0.0f),ptk10(5.0f, -5.0f, -4.0f),ptk11(5.0f, -5.0f, 4.0f),ptk12(0.0f, 5.0f, 0.0f),
		ptk13(5.0f, -5.0f, -4.0f),ptk14(5.0f, -5.0f, 4.0f),ptk15(-5.0f, -5.0f, -4.0f),ptk16(5.0f, -5.0f, 4.0f),ptk17(-5.0f, -5.0f, -4.0f),ptk18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf3);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(ptk1.x,ptk1.y,ptk1.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptk2.x,ptk2.y,ptk2.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptk3.x,ptk3.y,ptk3.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptk4.x,ptk4.y,ptk4.z);
	glTexCoord2d(0, 0);
    glVertex3d(ptk5.x,ptk5.y,ptk5.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptk6.x,ptk6.y,ptk6.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptk7.x,ptk7.y,ptk7.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptk8.x,ptk8.y,ptk8.z);
	glTexCoord2d(0, 0);
	glVertex3d(ptk9.x,ptk9.y,ptk9.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptk10.x,ptk10.y,ptk10.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptk11.x,ptk11.y,ptk11.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptk12.x,ptk12.y,ptk12.z);
	glTexCoord2d(0, 0);
	glVertex3d(ptk13.x,ptk13.y,ptk13.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptk14.x,ptk14.y,ptk14.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptk15.x,ptk15.y,ptk15.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptk16.x,ptk16.y,ptk16.z);
	glTexCoord2d(0, 0);
	glVertex3d(ptk17.x,ptk17.y,ptk17.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptk18.x,ptk18.y,ptk18.z);
	glTexCoord2d(1, 1);
	glEnd();
	glPopMatrix();

	//third house
	glTranslatef(-2,-11,-20);
	glTranslatef(0,0,-20);
	point ihhh1(0,0,0),ihhh2(9,0,0),ihhh3(9,0,-8),ihhh4(0,0,-9);
	cube chhh(ihhh1,ihhh2,ihhh3,ihhh4,7,house3);
	chhh.draw();

	point phhh1(-5.0f, -5.0f, -5.0f),phhh2(5.0f, -5.0f, -5.0f),phhh3(0.0f, 5.0f, 0.0f),phhh4(-5.0f, -5.0f, 5.0f),phhh5(5.0f, -5.0f, 5.0f),phhh6(0.0f, 5.0f, 0.0f),
		phhh7(-5.0f, -5.0f, 5.0f),phhh8(-5.0f, -5.0f, -5.0f),phhh9(0.0f, 5.0f, 0.0f),phhh10(5.0f, -5.0f, -5.0f),phhh11(5.0f, -5.0f, 5.0f),phhh12(0.0f, 5.0f, 0.0f),
		phhh13(5.0f, -5.0f, -5.0f),phhh14(5.0f, -5.0f, 5.0f),phhh15(-5.0f, -5.0f, -5.0f),phhh16(5.0f, -5.0f, 5.0f),phhh17(-5.0f, -5.0f, -5.0f),phhh18(-5.0f, -5.0f, 5.0f);
	
	glTranslatef(4,11,-5);
	glBindTexture(GL_TEXTURE_2D, roof2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(phhh1.x,phhh1.y,phhh1.z);
	glTexCoord2d(1, 0);
	glVertex3d(phhh2.x,phhh2.y,phhh2.z);
	glTexCoord2d(1, 1);
	glVertex3d(phhh3.x,phhh3.y,phhh3.z);
	glTexCoord2d(0, 1);
	glVertex3d(phhh4.x,phhh4.y,phhh4.z);
	glTexCoord2d(0, 0);
    glVertex3d(phhh5.x,phhh5.y,phhh5.z);
	glTexCoord2d(1, 0);
	glVertex3d(phhh6.x,phhh6.y,phhh6.z);
	glTexCoord2d(1, 1);
	glVertex3d(phhh7.x,phhh7.y,phhh7.z);
	glTexCoord2d(0, 1);
	glVertex3d(phhh8.x,phhh8.y,phhh8.z);
	glTexCoord2d(0, 0);
	glVertex3d(phhh9.x,phhh9.y,phhh9.z);
	glTexCoord2d(1, 0);
	glVertex3d(phhh10.x,phhh10.y,phhh10.z);
	glTexCoord2d(1, 1);
	glVertex3d(phhh11.x,phhh11.y,phhh11.z);
	glTexCoord2d(0, 1);
	glVertex3d(phhh12.x,phhh12.y,phhh12.z);
	glTexCoord2d(0, 0);
	glVertex3d(phhh13.x,phhh13.y,phhh13.z);
	glTexCoord2d(1, 0);
	glVertex3d(phhh14.x,phhh14.y,phhh14.z);
	glTexCoord2d(1, 1);
	glVertex3d(phhh15.x,phhh15.y,phhh15.z);
	glTexCoord2d(0, 1);
	glVertex3d(phhh16.x,phhh16.y,phhh16.z);
	glTexCoord2d(0, 0);
	glVertex3d(phhh17.x,phhh17.y,phhh17.z);
	glTexCoord2d(1, 0);
	glVertex3d(phhh18.x,phhh18.y,phhh18.z);
	glTexCoord2d(1, 1);
	glEnd();

	//tree
	glPushMatrix();
	glTranslatef(0,-11,-20);
	point itt1(0,0,0),itt2(2,0,0),itt3(2,0,-2),itt4(0,0,-2);
	cube citt(itt1,itt2,itt3,itt4,7,treewood2);
	citt.draw();

	point ptt1(-5.0f, -5.0f, -4.0f),ptt2(5.0f, -5.0f, -4.0f),ptt3(0.0f, 5.0f, 0.0f),ptt4(-5.0f, -5.0f, 4.0f),ptt5(5.0f, -5.0f, 4.0f),ptt6(0.0f, 5.0f, 0.0f),
		ptt7(-5.0f, -5.0f, 4.0f),ptt8(-5.0f, -5.0f, -4.0f),ptt9(0.0f, 5.0f, 0.0f),ptt10(5.0f, -5.0f, -4.0f),ptt11(5.0f, -5.0f, 4.0f),ptt12(0.0f, 5.0f, 0.0f),
		ptt13(5.0f, -5.0f, -4.0f),ptt14(5.0f, -5.0f, 4.0f),ptt15(-5.0f, -5.0f, -4.0f),ptt16(5.0f, -5.0f, 4.0f),ptt17(-5.0f, -5.0f, -4.0f),ptt18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-1);
	glBindTexture(GL_TEXTURE_2D, treeleaf2);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(ptt1.x,ptt1.y,ptt1.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptt2.x,ptt2.y,ptt2.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptt3.x,ptt3.y,ptt3.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptt4.x,ptt4.y,ptt4.z);
	glTexCoord2d(0, 0);
    glVertex3d(ptt5.x,ptt5.y,ptt5.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptt6.x,ptt6.y,ptt6.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptt7.x,ptt7.y,ptt7.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptt8.x,ptt8.y,ptt8.z);
	glTexCoord2d(0, 0);
	glVertex3d(ptt9.x,ptt9.y,ptt9.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptt10.x,ptt10.y,ptt10.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptt11.x,ptt11.y,ptt11.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptt12.x,ptt12.y,ptt12.z);
	glTexCoord2d(0, 0);
	glVertex3d(ptt13.x,ptt13.y,ptt13.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptt14.x,ptt14.y,ptt14.z);
	glTexCoord2d(1, 1);
	glVertex3d(ptt15.x,ptt15.y,ptt15.z);
	glTexCoord2d(0, 1);
	glVertex3d(ptt16.x,ptt16.y,ptt16.z);
	glTexCoord2d(0, 0);
	glVertex3d(ptt17.x,ptt17.y,ptt17.z);
	glTexCoord2d(1, 0);
	glVertex3d(ptt18.x,ptt18.y,ptt18.z);
	glTexCoord2d(1, 1);
	glEnd();

	//second tree
	glPushMatrix();
	glTranslatef(0,-11,-20);
	glTranslatef(0,0,-20);
	point jtt1(0,0,0),jtt2(2,0,0),jtt3(2,0,-2),jtt4(0,0,-2);
	cube cttj(jtt1,jtt2,jtt3,jtt4,10,treewood2);
	cttj.draw();

	point pjtt1(-5.0f, -5.0f, -4.0f),pttj2(5.0f, -5.0f, -4.0f),pttj3(0.0f, 5.0f, 0.0f),pttj4(-5.0f, -5.0f, 4.0f),pttj5(5.0f, -5.0f, 4.0f),pttj6(0.0f, 5.0f, 0.0f),
		pttj7(-5.0f, -5.0f, 4.0f),pttj8(-5.0f, -5.0f, -4.0f),pttj9(0.0f, 5.0f, 0.0f),pttj10(5.0f, -5.0f, -4.0f),pttj11(5.0f, -5.0f, 4.0f),pttj12(0.0f, 5.0f, 0.0f),
		pttj13(5.0f, -5.0f, -4.0f),pttj14(5.0f, -5.0f, 4.0f),pttj15(-5.0f, -5.0f, -4.0f),pttj16(5.0f, -5.0f, 4.0f),pttj17(-5.0f, -5.0f, -4.0f),pttj18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(0,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pjtt1.x,pjtt1.y,pjtt1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pttj2.x,pttj2.y,pttj2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pttj3.x,pttj3.y,pttj3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pttj4.x,pttj4.y,pttj4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pttj5.x,pttj5.y,pttj5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pttj6.x,pttj6.y,pttj6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pttj7.x,pttj7.y,pttj7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pttj8.x,pttj8.y,pttj8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pttj9.x,pttj9.y,pttj9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pttj10.x,pttj10.y,pttj10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pttj11.x,pttj11.y,pttj11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pttj12.x,pttj12.y,pttj12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pttj13.x,pttj13.y,pttj13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pttj14.x,pttj14.y,pttj14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pttj15.x,pttj15.y,pttj15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pttj16.x,pttj16.y,pttj16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pttj17.x,pttj17.y,pttj17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pttj18.x,pttj18.y,pttj18.z);
	glTexCoord2d(1, 1);
	glEnd();
	glPopMatrix();
	
	//third tree
	glPushMatrix();
	glTranslatef(0,-11,-20);
	glTranslatef(0,0,-20);
	point ktt1(0,0,0),ktt2(2,0,0),ktt3(2,0,-2),ktt4(0,0,-2);
	cube cktt(ktt1,ktt2,ktt3,ktt4,10,treewood1);
	cktt.draw();

	point pttk1(-5.0f, -5.0f, -4.0f),pttk2(5.0f, -5.0f, -4.0f),pttk3(0.0f, 5.0f, 0.0f),pttk4(-5.0f, -5.0f, 4.0f),pttk5(5.0f, -5.0f, 4.0f),pttk6(0.0f, 5.0f, 0.0f),
		pttk7(-5.0f, -5.0f, 4.0f),pttk8(-5.0f, -5.0f, -4.0f),pttk9(0.0f, 5.0f, 0.0f),pttk10(5.0f, -5.0f, -4.0f),pttk11(5.0f, -5.0f, 4.0f),pttk12(0.0f, 5.0f, 0.0f),
		pttk13(5.0f, -5.0f, -4.0f),pttk14(5.0f, -5.0f, 4.0f),pttk15(-5.0f, -5.0f, -4.0f),pttk16(5.0f, -5.0f, 4.0f),pttk17(-5.0f, -5.0f, -4.0f),pttk18(-5.0f, -5.0f, 4.0f);
	
	glTranslatef(2,11,-0.6);
	glBindTexture(GL_TEXTURE_2D, treeleaf3);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0, 0);
	glVertex3d(pttk1.x,pttk1.y,pttk1.z);
	glTexCoord2d(1, 0);
	glVertex3d(pttk2.x,pttk2.y,pttk2.z);
	glTexCoord2d(1, 1);
	glVertex3d(pttk3.x,pttk3.y,pttk3.z);
	glTexCoord2d(0, 1);
	glVertex3d(pttk4.x,pttk4.y,pttk4.z);
	glTexCoord2d(0, 0);
    glVertex3d(pttk5.x,pttk5.y,pttk5.z);
	glTexCoord2d(1, 0);
	glVertex3d(pttk6.x,pttk6.y,pttk6.z);
	glTexCoord2d(1, 1);
	glVertex3d(pttk7.x,pttk7.y,pttk7.z);
	glTexCoord2d(0, 1);
	glVertex3d(pttk8.x,pttk8.y,pttk8.z);
	glTexCoord2d(0, 0);
	glVertex3d(pttk9.x,pttk9.y,pttk9.z);
	glTexCoord2d(1, 0);
	glVertex3d(pttk10.x,pttk10.y,pttk10.z);
	glTexCoord2d(1, 1);
	glVertex3d(pttk11.x,pttk11.y,pttk11.z);
	glTexCoord2d(0, 1);
	glVertex3d(pttk12.x,pttk12.y,pttk12.z);
	glTexCoord2d(0, 0);
	glVertex3d(pttk13.x,pttk13.y,pttk13.z);
	glTexCoord2d(1, 0);
	glVertex3d(pttk14.x,pttk14.y,pttk14.z);
	glTexCoord2d(1, 1);
	glVertex3d(pttk15.x,pttk15.y,pttk15.z);
	glTexCoord2d(0, 1);
	glVertex3d(pttk16.x,pttk16.y,pttk16.z);
	glTexCoord2d(0, 0);
	glVertex3d(pttk17.x,pttk17.y,pttk17.z);
	glTexCoord2d(1, 0);
	glVertex3d(pttk18.x,pttk18.y,pttk18.z);
	glTexCoord2d(1, 1);
	glEnd();
	glPopMatrix();
	
	glPopMatrix();
}

nature::~nature(void)
{
}
