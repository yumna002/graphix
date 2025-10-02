#pragma once
#include "point.h"
#include "color.h"
#include "cube.h"

class nature
{
public:


	nature(void);
	
	nature(int nu);
	void draw(int top,int left,int right,int front,int back,int down,int glass,int building1,int building2,int building3,
		int building4,int building5,int building6,int building7,int treewood1,int treewood2,int treeleaf,
		int treeleaf2,int treeleaf3,int treeleaf4,int treeleaf5,int treeleaf6,int treeleaf8,int treeleaf9,
		int treeleaf10,int treeleaf11,int treeleaf12,int house1,int house2,
		int house3,int roof1,int roof2,int rollercoaster1,int rollercoaster2);
	
	~nature(void);
};

