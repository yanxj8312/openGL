
#include "SolarSystem.hpp"

#define TIMEPAST 1
#define SELFROTATE 3

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
}


SolarSystem::~SolarSystem(){
	//TODO:
}
