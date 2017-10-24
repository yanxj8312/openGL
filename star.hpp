#ifndef __STAR_HPP__
#define __STAR_HPP__
#include <GL/glut.h>

class Star{
public:
	//星球的运转半径
	GLfloat radius;
	//星球的公转、自传速度
	GLfloat speed,selfSpeed;
	//星球的中心与父节点星球中心的距离
	GLfloat distance;
	//星球的颜色
	GLfloat rgbaColor[4];
	
	//父节点星球
	Star* parentStar;
	
	//构造函数，构造一颗星球时必须提供
	//旋转半径，旋转速度，自转速度、绕行星球
	Star(GLfloat radius,GLfloat distance,
	     GLfloat speed, GLfloat selfSpeed,
		Star* parent);

	//对一般星球的移动、旋转等活动进行绘制
	void drawStar();
	//提供默认实现，负责调用drawstar
	virtual void draw(){drawStar();}
	//参数为每次刷新画面时的时间跨度
	virtual void update(long timeSpan);
protected:
	float alphaSelf,alpha;
};

//行星
class Planet : public Star{
public:
	//构造函数
	Planet(GLfloat radius,GLfloat distance,GLfloat speed,GLfloat selfSpeed,Star* parent,GLfloat rgbColor[3]);
	//增加对具备自身材质的行星绘制材质
	void drawPlanet();
	//继续向其子类开放重写功能
	virtual void draw(){ drawPlanet();drawStar();}

};

//恒星
class LightPlanet : public Planet{

public:
	LightPlanet(GLfloat Radius,GLfloat Distance,
			GLfloat Speed,GLfloat SelfSpeed,
			Star* Parent,GLfloat rgbClolr[3]);
	//增加对提供光源的恒星绘制光照
	void drawLight();
	virtual void draw(){ drawLight(),drawPlanet();drawStar();}
};

#endif /* star_hpp */
