#ifndef __SOLARSYSTEM_HPP__
#define __SOLARSYSTEM_HPP__

#include <GL/glut.h>
#include "star.hpp"


#define STARS_NUM 10
#define REST 700
#define REST_Y (-REST)
#define REST_Z (REST)

class SolarSystem{

public:

	SolarSystem();
	~SolarSystem();
	
	void onDisplay();
	void onUpdate();
	void onKeyboard(unsigned char key,int x,int y);

private:
	Star *stars[STARS_NUM];

	//定义观察视角的参数
	GLdouble viewX,viewY,viewZ;
	GLdouble centerX,centerY,centerZ;
	GLdouble upX,upY,upZ;

};

#endif /* solarsystem_hpp */
