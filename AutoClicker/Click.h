#pragma once

#include <Windows.h>
#include <windowsx.h>
#include <list>

//Click class which takes a point, and a char.
class Click{
private:
	POINT p;
	char c;
public:
	Click(void){};
	Click(POINT p, char c);
	virtual ~Click(void){};
	POINT getPoint();
	char getChar();
};