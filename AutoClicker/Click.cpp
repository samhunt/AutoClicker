#include "stdafx.h"

Click::Click(POINT point, char ch)
{
		p = point;
		c = ch;
}

POINT Click::getPoint(){
	return p;
}

char Click::getChar(){
	return c;
}