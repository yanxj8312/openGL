
#include "SolarSystem.hpp"

#define TIMEPAST 1

//自转速度
#define SELFROTATE 3
//公转半径
#define SUN_RADIUS 48.74
#define MER_RADIUS 7.32
#define VEN_RADIUS 18.15
#define EAR_RADIUS 19.13
#define MOO_RADIUS 6.15
#define MAR_RADIUS 10.19
#define JUP_RADIUS 42.90
#define SAT_RADIUS 36.16
#define URA_RADIUS 25.56
#define NEP_RADIUS 24.74

//距离太阳的距离
#define MER_DIS 62.06
#define VEN_DIS 115.56
#define EAR_DIS 168.00
#define MOO_DIS 26.01
#define MAR_DIS 228.00
#define JUP_DIS 333.40
#define SAT_DIS 428.10
#define URA_DIS 848.00
#define NEP_DIS 989.10

//运动速度
#define MER_SPEED 87.0
#define VEN_SPEED 225.0
#define EAR_SPEED 365.0
#define MOO_SPEED 30.0
#define MAR_SPEED 687.0
#define JUP_SPEED 1298.4
#define SAT_SPEED 3225.6
#define URA_SPEED 3066.4
#define NEP_SPEED 6014.8

//为了方便操作数组，定义一个设置多为数组的宏
#define SET_VALUE_3(name,value0,value1,value2) \
			((name)[0])=(value0),((name)[1])=(value1),((name)[2]=(value2))



enum STARS{
	Sun,
	Mercury,
	Venus,
	Earth,
	Moon,
	Mars,
	Jupiter,
	Saturn,
	Uranus,
	Neptune
	};

void SolarSystem::onDisplay(){
	//TODO:
	//清除viewport缓冲区
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//清空并设置颜色缓存
	glClearColor(.7f,.7f,.7f,.1f);
	//指定当前矩阵是投影矩阵
	glMatrixMode(GL_PROJECTION);
	//将指定的矩阵指定为单位矩阵
	glLoadIdentity();
	//制定当前的观察视景体
	gluPerspective(75.0f,1.0f,1.0f,40000000);
	//指定当前矩阵为视景矩阵堆栈应用后的矩阵操作
	glMatrixMode(GL_MODELVIEW);
	//指定当前的矩阵为单位矩阵，并与当前矩阵相乘
	gluLookAt(viewX,viewY,viewZ,centerX,centerY,centerZ,upX,upY,upZ);

	//设置第一个光源（0号光源）
	glEnable(GL_LIGHT0);
	//启用光源
	glEnable(GL_LIGHTING);
	//启用生读测试，根据坐标的远近自动隐藏被遮住的图形
	glEnalbe(GL_DEPTH_TEST);

	//绘制星球
	for(int i = 0; i<STARS_NUM;i++)
	{
		stars[i]->draw();
	}
	//我们需要在main函数中初始化显示模式时使用GLUT_DOUBLE
	//需要使用glutSwapBuffer 在绘制结束后实现双缓冲的缓冲区交换
	glutSwapBuffers();
}

void SolarSystem::onUpdate(){
	//TODO:
	for(int i=0;i<STARS_NUM;++i)
		stars[i]->update(TIMEPAST);	//更新星球的位置
	this->onDisplay();	//刷新显示 
}

void SolarSystem::onKeyboard(unsigned char key,int x,int y){
	//TODO:
}

SolarSystem::SolarSystem(){
	//TODO:
	viewX = 0;
	viewY = REST_Y;
	viewZ = REST_Z;
	centerX = centerY = centerZ = 0;
	upX = upY = 0;
	upZ = 1;
	
	//太阳
	GLfloat rgbColor[3] = {1,0,0};
	stars[Sun] = new LightPlanet(SUN_RADIUS,0,0,SELFROTATE,0,rgbColor);
	//水星
	
}


SolarSystem::~SolarSystem(){
	//TODO:
}
