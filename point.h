#pragma once
class point
{
public:
	float x,y,z;

	point(void);

	point(float xx,float yy,float zz);
	void init(float xx,float yy,float zz);

	~point(void);
};

