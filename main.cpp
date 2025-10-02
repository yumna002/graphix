#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Sound.h"
#include "camera.h"
#include "texture.h"
#include "point.h"
#include "color.h"
#include "cube.h"
#include "chair.h"
#include "door.h"
#include "skybox.h"
#include "trailer.h"
#include "sittingRoom.h"
#include "chair2.h"
#include "cinemaRoom.h"
#include "bed.h"
#include "bedRoom.h"
#include "foodTable.h"
#include "eatingRoom.h"
#include "person.h"
#include "nature.h"


HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

sittingRoom SITTING_ROOM;
bedRoom BED_ROOM;
eatingRoom EATING_ROOM;
cinemaRoom CINEMA_ROOM;
trailer HEAD_ROOM;
nature N;

//float XC=7.5, YC=4, ZC=0;
float XC=0, YC=0, ZC=5;
Camera cam,Tcam,Pcam;
person p;

point center(0,0,0);
int trailer_num=0;

float doorX=0,doorY=0,doorZ=0; bool openDoor=false;
float foodTableX=0,foodTableY=0,foodTableZ=0;
float TV=1,view=0,add=1;
bool rd3_view=false;

int trainColor,trainGlass,trainDoor,trainFloor,trainInside,chairFabric,chairWood,trainChimney,controllTableSide,controllTable,
	cinema_trainFloor,cinema_trainInside,cinema_chairWood,cinema_chairFabric,tv,tv2,
	bedWood,bedSleep,bedHead,bed_trainFloor,bed_trainInside,bed_trainGlass,bedMirror,
	foodTableWood,foodTableFabric,food_trainInside,food_trainFloor,food_wallDec,
	steve_body,steve_head,steve_hand;
int top,left,right,front,back,down,glass,building1,building2,building3,building4,building5,building6,building7,
treewood1,treewood2,treeleaf,treeleaf2,treeleaf3,treeleaf4,treeleaf5,treeleaf6,treeleaf8,treeleaf9,treeleaf10,treeleaf11,treeleaf12,
house1,house2,house3,roof1,roof2,rollercoaster1,rollercoaster2;

Sound train_main_sound,train_horn_sound;
INIT initialize=INIT();
bool sound_on=false;

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	initialize.InitOpenAL();
	train_main_sound=Sound("train_main_sound.wav");
	train_horn_sound=Sound("train_horn_sound.wav");

	glEnable(GL_TEXTURE_2D);
	//name = LoadTexture("name.bmp");
	trainColor = LoadTexture("trainColor.bmp");
	trainDoor = LoadTexture("trainDoor.bmp");
	trainGlass = LoadTexture("trainGlass.bmp",70);
	trainFloor = LoadTexture("trainFloor.bmp");
	trainInside = LoadTexture("trainInside.bmp");
	chairFabric = LoadTexture("chairFabric.bmp");
	chairWood = LoadTexture("chairWood.bmp");
	cinema_chairWood = LoadTexture("cinema_chairWood.bmp");
	cinema_chairFabric = LoadTexture("cinema_chairFabric.bmp");
	cinema_trainInside = LoadTexture("cinema_trainInside.bmp");
	cinema_trainFloor = LoadTexture("cinema_trainFloor.bmp");
	tv = LoadTexture("tv.bmp");
	tv2 = LoadTexture("tv2.bmp");
	bedWood = LoadTexture("bedWood.bmp");
	bedSleep = LoadTexture("bedSleep.bmp");
	bedHead = LoadTexture("bedHead.bmp");
	bed_trainGlass = LoadTexture("bed_trainGlass.bmp",120);
	bed_trainFloor = LoadTexture("bed_trainFloor.bmp");
	bed_trainInside = LoadTexture("bed_trainInside.bmp");
	bedMirror = LoadTexture("bedMirror.bmp");
	foodTableWood = LoadTexture("foodTableWood.bmp");
	foodTableFabric = LoadTexture("foodTableFabric.bmp");
	food_trainInside = LoadTexture("food_trainInside.bmp");
	food_trainFloor = LoadTexture("food_trainFloor.bmp");
	food_wallDec = LoadTexture("food_wallDec.bmp");
	trainChimney = LoadTexture("trainChimney.bmp");
	steve_body = LoadTexture("steve_body.bmp");
	steve_head = LoadTexture("steve_head.bmp");
	steve_hand = LoadTexture("steve_hand.bmp");
	controllTable = LoadTexture("controllTable.bmp");
	controllTableSide = LoadTexture("controllTableSide.bmp");

	top = LoadTexture("top.bmp");
	left = LoadTexture("left.bmp");
	right = LoadTexture("right.bmp");
	back = LoadTexture("back.bmp");
	front = LoadTexture("front.bmp");
	down = LoadTexture("down.bmp");
	building1=LoadTexture("buildingg.bmp");
	building2=LoadTexture("building5.bmp");
	building4=LoadTexture("kk.bmp");
	building3=LoadTexture("buildingg.bmp");
	building5=LoadTexture("images1.bmp");
	building6=LoadTexture("jj.bmp");
	building7=LoadTexture("images2.bmp");
	house1=LoadTexture("house1.bmp");
	roof1=LoadTexture("roof2.bmp");
	house2=LoadTexture("house2.bmp");
	house3=LoadTexture("house3.bmp");
	roof2=LoadTexture("roof3.bmp");
	treewood1=LoadTexture("treewood1.bmp");
	treewood2=LoadTexture("treewood2.bmp");
	treeleaf=LoadTexture("treeleaf1.bmp");
	treeleaf2=LoadTexture("treeleaf2.bmp");
	treeleaf3=LoadTexture("treeleaf3.bmp");
	treeleaf4=LoadTexture("treeleaf7.bmp");
	treeleaf6=LoadTexture("treeleaf6.bmp");
	treeleaf8=LoadTexture("treeleaf8.bmp");
	treeleaf9=LoadTexture("treeleaf9.bmp");
	treeleaf10=LoadTexture("treeleaf10.bmp");
	treeleaf11=LoadTexture("treeleaf11.bmp");
	treeleaf12=LoadTexture("treeleaf12.bmp");
	rollercoaster1=LoadTexture("rollercoaster1.bmp");
	rollercoaster2=LoadTexture("rollercoaster2.bmp");

	cam = Camera(XC,YC,ZC);
	Tcam = Camera(XC,YC,ZC);
	Pcam=cam; Pcam.Position.z+=1; Pcam.Position.y+=2;

	return TRUE;										// Initialization Went OK
}

void TrailerNubmer()
{
	float place=cam.Position.z;
	
	if(place<=-391.5 && place >=-406.5){ 
		trailer_num=1;
		center=point(0,0,-391.5);
	}
	
	else if(place<=-348 && place >=-388){
		trailer_num=2;		
		center=point(0,0,-348);
	}

	else if(place<=-304.5 && place >=-344.5){
		trailer_num=3;		
		center=point(0,0,-304.5);
	}

	else if(place<=-261 && place >=-301){
		trailer_num=4;		
		center=point(0,0,-261);
	}

	else if(place<=-217.5 && place >=-257.5){
		trailer_num=5;		
		center=point(0,0,-217.5);
	}

	else if(place<=-174 && place >=-214){
		trailer_num=6;	
		center=point(0,0,-174);
	}

	else if(place<=-130.5 && place >=-170.5){
		trailer_num=7;
		center=point(0,0,-130.5);
	}

	else if(place<=-87 && place >=-127){
		trailer_num=8;		
		center=point(0,0,-87);
	}

	else if(place<=-43.5 && place >=-83.5){
		trailer_num=9;		
		center=point(0,0,-43.5);
	}

	else if(place<=0 && place >=-40){
		trailer_num=10;	
		center=point(0,0,0);
	}

	else
		trailer_num=0;
}

boolean collision(point cam,point tranz)
{
	TrailerNubmer();

	if(trailer_num==1)
		return HEAD_ROOM.headRoomCollision(cam,tranz,openDoor);
	
	else if(trailer_num==2)
		return CINEMA_ROOM.cinemaRoomCollision(cam,tranz,openDoor);

	else if(trailer_num==3)
		return EATING_ROOM.eatingRoomCollision(cam,tranz,openDoor);

	else if(trailer_num==4)
		return EATING_ROOM.eatingRoomCollision(cam,tranz,openDoor);

	else if(trailer_num==5)
		return SITTING_ROOM.sittingRoomCollision(cam,tranz,openDoor);

	else if(trailer_num==6)
		return SITTING_ROOM.sittingRoomCollision(cam,tranz,openDoor);

	else if(trailer_num==7)
		return SITTING_ROOM.sittingRoomCollision(cam,tranz,openDoor);

	else if(trailer_num==8)
		return BED_ROOM.bedRoomCollision(cam,tranz,openDoor);

	else if(trailer_num==9)
		return BED_ROOM.bedRoomCollision(cam,tranz,openDoor);

	else if(trailer_num==10)
		return BED_ROOM.bedRoomCollision(cam,tranz,openDoor);
	
	else 
		return false;
}

void camera()
{
	TrailerNubmer();
	float sp=0.3;
	point fp(Tcam.Position.x,Tcam.Position.y,Tcam.Position.z);

	if(keys['W']){
		Tcam.MoveForward(sp);
		fp= point(Tcam.Position.x,Tcam.Position.y,Tcam.Position.z);

		if(!collision(fp,center)){
			cam=Tcam;
		}
		else Tcam=cam;
	}

	if(keys['S']){
		Tcam.MoveForward(-sp);
		fp= point(Tcam.Position.x,Tcam.Position.y,Tcam.Position.z);

		if(!collision(fp,center)){
			cam=Tcam;
		}
		else Tcam=cam;
	}
	
	if(keys['D']){
		Tcam.MoveRight(sp);
		fp= point(Tcam.Position.x,Tcam.Position.y,Tcam.Position.z);

		if(!collision(fp,center)){
			cam=Tcam;
		}
		else Tcam=cam;
	}
	
	if(keys['A']){
		Tcam.MoveRight(-sp);
		fp= point(Tcam.Position.x,Tcam.Position.y,Tcam.Position.z);

		if(!collision(fp,center)){
			cam=Tcam;
		}
		else Tcam=cam;
	}

	if(keys['E']){
		cam.MoveUpward(sp);
		Tcam=cam;
	}
	
	if(keys['Q']){
		cam.MoveUpward(-sp);
		Tcam=cam;
	}

	if(keys[VK_RIGHT]){
		cam.RotateY(sp);
		Tcam=cam;
	}
	
	if(keys[VK_LEFT]){
		cam.RotateY(-sp);
		Tcam=cam;
	}

	if(keys[VK_UP]){
		cam.RotateX(sp);
		Tcam=cam;
	}
	
	if(keys[VK_DOWN]){
		cam.RotateX(-sp);
		Tcam=cam;
	}

	if(rd3_view){
		Pcam=cam; Pcam.Position.z+=13; Pcam.Position.y+=6;
		Pcam.Render();
	}
	else{
		cam.Render();
		Pcam=cam; Pcam.Position.z+=13; Pcam.Position.y+=6;
	}
}

void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();	
	




	
	///////////////////////////////////////////////////////////////////////////////CALLING FUNCTIONS AT THE BIGINING
	
	camera();
	if(!sound_on){ train_main_sound.Play(); sound_on=true; }
	center=point(0,0,0);
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	



	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////POINTS
	
	color c(0,0,1);
	point P1(0,0,0),P2(15,0,0),P3(15,10,0),P4(0,10,0),P5(0,0,-15),P6(15,0,-15),P7(15,10,-15),P8(0,10,-15);
	point p1(P2.x+0.1,0,-4),p2(p1.x+0.2,0,-4),p3(p1.x+0.2,0,-8),p4(P2.x+0.2,0,-8),
		p5(15,4,-8),p6(15,4,-12),p7(15,8,-12),p8(15,8,-8);
	float hight=5,width=4,thick=0;
	point x1(0,0,0),x2(thick,0,0),x3(thick,0,-thick),x4(0,0,-thick);
	point i1(0,0,0),i2(0.3,0,0),i3(0.3,0,-25),i4(0,0,-25);
	float hi=4,thi=0.2,wi=5;
	point z1(0,0,0),z2(thi,0,0),z3(thi,0,-wi),z4(0,0,-wi);
	point a1(0,0,0),a2(width,0,0),a3(width,0,-0.5),a4(0,0,-0.5);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////






	////////////////////////////////////////////////////////////////////////////////////////////////////////INTERACTIONS

	//press N to open door and M to close door
	if(keys['N']){
		doorX=-3; openDoor=true;
	}
	if(keys['M']){
		doorX=0; openDoor=false;
	}

	//press Y to start train horn
	if(keys['Y']){
		PlaySound("train_horn_sound.wav",NULL,SND_ASYNC);
	}

	//press J to turn tv on and K to turn it off
	if(keys['J']){
		TV=2;
	}
	if(keys['K']){
		TV=1;
	}

	//press V to pull the food chair ans B to return it back
	if(keys['V']){
		foodTableZ=-2;
	}
	if(keys['B']){
		foodTableZ=0;
	}

	//press U to view 3rd person camera ans I to turn back to main camera
	if(keys['U']){
		rd3_view=true;
	}
	if(keys['I']){
		rd3_view=false;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	




	////////////////////////////////////////////////////////////////////////////////////////////////PERSON FOR 3RD CAMERA
	
	glPushMatrix();

	hight=4.5,width=2;
	a1=point(0,0,0),a2=point(width,0,0),a3=point(width,0,-0.5),a4=point(0,0,-0.5);

	glRotated(cam.RotatedY,0,1,0);
	glTranslated(cam.Position.x-width/2,cam.Position.y-hight/4,cam.Position.z+hight/2);	

	p=person(a1,a2,a3,a4,hight,width,steve_body,steve_head,steve_hand);
	p.draw();
	
	glPopMatrix();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////THE NATURE
	
	glPushMatrix();
	glTranslated(0,-2,50);
	glPushMatrix();
	glTranslated(0,0,view);
	view+=add;
	N=nature(0);
	N.draw(top,left,right,front,back,down,glass,building1,building2,building3,building4,building5,building6,building7,
		treewood1,treewood2,treeleaf,treeleaf2,treeleaf3,treeleaf4,treeleaf5,treeleaf6,treeleaf8,treeleaf9,
		treeleaf10,treeleaf11,treeleaf12,
		house1,house2,house3,roof1,roof2,rollercoaster1,rollercoaster2);
	if(view==300)add=-1;
	else if(view==0)add=1;
	glPopMatrix();
	glPopMatrix();
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	





	///////////////////////////////////////////////////////////////////////////////////////////////////////////////THE TRAIN

	glTranslated(0,0,-391.5);
	//////////////////////////////////////////////////////////////////////////////////////drawing train head
	glPushMatrix();

	c=color(0,0,1);
	P1=point(0,0,0),P2=point(15,0,0),P3=point(15,10,0),P4=point(0,10,0),
		P5=point(0,0,-15),P6=point(15,0,-15),P7=point(15,10,-15),P8=point(0,10,-15);
	trailer HEAD_ROOM(P1,P2,P3,P4,P5,P6,P7,P8,trainColor,trainInside,trainGlass,trainFloor,trainDoor,c);
	p1=point(6,0,0),p2=point(10,0,0),p3=point(10,6,0),p4=point(6,6,0);
	hight=5,width=4;
	
	HEAD_ROOM.draw_head(p1,p2,p3,p4,hight,width,doorX,doorY,doorZ,controllTable,controllTableSide,trainColor);

	glPopMatrix();
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	glTranslated(0,0,391.5);



	glTranslated(0,0,-348);
	//////////////////////////////////////////////////////////////draw cinema room1
	glPushMatrix();

	P1=point(0,0,0),P2=point(15,0,0),P3=point(15,10,0),P4=point(0,10,0),
		P5=point(0,0,-40),P6=point(15,0,-40),P7=point(15,10,-40),P8=point(0,10,-40);
	c=color(0,0,1);
	p1=point(9,0,0),p2=point(12.5,0,0),p3=point(12.5,6,0),p4=point(9,6,0);

	width=3.2,hight=2.1,thick=0.3;
	x1=point(0,0,0),x2=point(thick,0,0),x3=point(thick,0,-thick),x4=point(0,0,-thick);

	i1=point(0,0,0),i2=point(0.3,0,0),i3=point(0.3,0,-25),i4=point(0,0,-25);

	cinemaRoom CINEMA_ROOM(P1,P2,P3,P4,P5,P6,P7,P8,p1,p2,p3,p4,x1,x2,x3,x4,c,
		trainColor,trainGlass,trainDoor,cinema_trainFloor,cinema_trainInside,cinema_chairFabric,cinema_chairWood,tv,tv2,
		hight,width,thick,i1,i2,i3,i4);
	
	CINEMA_ROOM.draw(doorX,doorY,doorZ,TV);

	glPopMatrix();
	///////////////////////////////////////////////////////////////////////////////
	glTranslated(0,0,348);

	

	glTranslated(0,0,-304.5);
	///////////////////////////////////////////////////////////////draw eating room1
	glPushMatrix();

	P1=point(0,0,0),P2=point(15,0,0),P3=point(15,10,0),P4=point(0,10,0),
		P5=point(0,0,-40),P6=point(15,0,-40),P7=point(15,10,-40),P8=point(0,10,-40);
	c=color(0,0,1);
	p1=point(6,0,0),p2=point(10,0,0),p3=point(10,6,0),p4=point(6,6,0);
	width=1.4,hight=3.4,thick=0.3;
	i1=point(0,0,0),i2=point(thick,0,0),i3=point(thick,0,-thick),i4=point(0,0,-thick);
	x1=point(0,0,0),x2=point(thick,0,0),x3=point(thick,0,-thick),x4=point(0,0,-thick);
	hi=4,thi=0.2,wi=5;
	z1=point(0,0,0),z2=point(thi,0,0),z3=point(thi,0,-wi),z4=point(0,0,-wi);

	eatingRoom EATING_ROOM(P1,P2,P3,P4,P5,P6,P7,P8,
		p1,p2,p3,p4,c,
		x1,x2,x3,x4,i1,i2,i3,i4,z1,z2,z3,z4,
		trainColor,trainGlass,trainDoor,food_trainFloor,food_trainInside,foodTableWood,foodTableFabric,food_wallDec,
		hight,width,thick,hi,wi,thi);

	EATING_ROOM.draw(doorX,doorY,doorZ,foodTableX,foodTableY,foodTableZ);

	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////////
	glTranslated(0,0,304.5);

	

	glTranslated(0,0,-261);
	///////////////////////////////////////////////////////////////draw eating room2
	glPushMatrix();

	hight=2.6;
	EATING_ROOM=eatingRoom(P1,P2,P3,P4,P5,P6,P7,P8,
		p1,p2,p3,p4,c,
		x1,x2,x3,x4,i1,i2,i3,i4,z1,z2,z3,z4,
		trainColor,trainGlass,trainDoor,food_trainFloor,food_trainInside,foodTableWood,foodTableFabric,food_wallDec,
		hight,width,thick,hi,wi,thi);

	EATING_ROOM.draw(doorX,doorY,doorZ,foodTableX,foodTableY,foodTableZ);

	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////////
	glTranslated(0,0,261);



	glTranslated(0,0,-217.5);
	/////////////////////////////////////////////////////////////drawing sitting room1
	glPushMatrix();
	
	P1=point(0,0,0),P2=point(15,0,0),P3=point(15,10,0),P4=point(0,10,0),
		P5=point(0,0,-40),P6=point(15,0,-40),P7=point(15,10,-40),P8=point(0,10,-40);
	c=color(0,0,1);
	p1=point(6,0,0),p2=point(10,0,0),p3=point(10,6,0),p4=point(6,6,0),
		p5=point(15,4,-8),p6=point(15,4,-12),p7=point(15,8,-12),p8=point(15,8,-8);
	x1=point(0,0,0),x2=point(4,0,0),x3=point(4,0,-2.7),x4=point(0,0,-2.7);

	sittingRoom SITTING_ROOM(P1,P2,P3,P4,P5,P6,P7,P8,p1,p2,p3,p4,p5,p6,p7,p8,x1,x2,x3,x4,c,
		trainColor,trainGlass,trainDoor,trainFloor,trainInside,chairFabric,chairWood);
	
	SITTING_ROOM.draw(doorX,doorY,doorZ);

	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////////////
	glTranslated(0,0,217.5);



	glTranslated(0,0,-174);
	/////////////////////////////////////////////////////////////drawing sitting room2
	glPushMatrix();

	SITTING_ROOM.draw(doorX,doorY,doorZ);

	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////////////
	glTranslated(0,0,174);



	glTranslated(0,0,-130.5);
	/////////////////////////////////////////////////////////////drawing sitting room3
	glPushMatrix();
	
	SITTING_ROOM.draw(doorX,doorY,doorZ);

	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////////////
	glTranslated(0,0,130.5);
	


	glTranslated(0,0,-87);
	/////////////////////////////////////////////////////////////////////////draw bedRoom1
	glPushMatrix();

	P1=point(0,0,0),P2=point(15,0,0),P3=point(15,10,0),P4=point(0,10,0),
		P5=point(0,0,-40),P6=point(15,0,-40),P7=point(15,10,-40),P8=point(0,10,-40);
	c=color(0,0,1);
	p1=point(9,0,0),p2=point(12.5,0,0),p3=point(12.5,6,0),p4=point(9,6,0),
		p5=point(15,4,-8),p6=point(15,4,-12),p7=point(15,8,-12),p8=point(15,8,-8);
	hight=2.2,width=7.5,thick=0.2;
	x1=point(0,0,0),x2=point(width,0,0),x3=point(width,0,-3.8),x4=point(0,0,-3.8);
	i1=point(0,0,0),i2=point(4,0,-4),i3=point(3.9,0,-4.1),i4=point(0.1,0,-0.1);

	BED_ROOM=bedRoom(P1,P2,P3,P4,P5,P6,P7,P8, p1,p2,p3,p4,p5,p6,p7,p8,x1,x2,x3,x4,c,
		trainColor,bed_trainGlass,trainDoor,bed_trainFloor,bed_trainInside,bedWood,bedSleep,bedHead,bedMirror,
		hight,width,thick,i1,i2,i3,i4);
	
	BED_ROOM.draw(doorX,doorY,doorZ);

	glPopMatrix();
	///////////////////////////////////////////////////////////////////////////////////////
	glTranslated(0,0,87);



	glTranslated(0,0,-43.5);
	/////////////////////////////////////////////////////////////////////////draw bedRoom2
	glPushMatrix();

	BED_ROOM.draw(doorX,doorY,doorZ);

	glPopMatrix();
	///////////////////////////////////////////////////////////////////////////////////////
	glTranslated(0,0,43.5);



	glTranslated(0,0,0);
	/////////////////////////////////////////////////////////////////////////draw bedRoom3
	glPushMatrix();

	BED_ROOM.draw(doorX,doorY,doorZ);

	glPopMatrix();
	///////////////////////////////////////////////////////////////////////////////////////
	glTranslated(0,0,0);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	




	
	glFlush(); 									
    //DO NOT REMOVE THIS
	SwapBuffers(hDC);

}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/
 
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
		case WM_PAINT: 
			DrawGLScene();
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			return 0;
	
		case WM_TIMER:
			DrawGLScene();
			return 0;

		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
					HINSTANCE	hPrevInstance,		// Previous Instance
					LPSTR		lpCmdLine,			// Command Line Parameters
					int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen=FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Madhat NeHe Template",640,480,16,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer=SetTimer(hWnd,0,0,(TIMERPROC) NULL);

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
			TranslateMessage(&msg);	
			DispatchMessage(&msg);
	}

	return 0;

}
