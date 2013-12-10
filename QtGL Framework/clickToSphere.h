#ifndef		DOUFEI_CLICKTOSPHERE_HEADER
#define		DOUFEI_CLICKTOSPHERE_HEADER
#include "Quaternion.h"
#include <Eigen/Dense>

/************************************************************************
* 使用说明：
*1. 在glutMouseFunc的注册函数中调用clickMouse函数
*2. 在glutMotionFunc的注册函数中调用mouseMotion函数
*3. 在glutIdleFunc的注册函数中调用mouseIdle函数
*4. 在glutDisplayFunc函数中，绘制操作前调用applyMouseMotion
************************************************************************/

class ClickToSphre
{
private:
	ClickToSphre();					//禁止外部生成新对象
	~ClickToSphre(){};					//禁止外部删除对象
	ClickToSphre(const ClickToSphre& c){ movX = 0; movY = 0;};				//禁止外部拷贝
	void operator = (const ClickToSphre& c){};		//禁止赋值给别的对象
	static ClickToSphre * m_instance;


	Quaternion pClick;   // mouse coordinates of current click
	Quaternion pDrag;    // mouse coordinates of current drag
	Quaternion pLast;    // mouse coordinates of previous drag
	Quaternion rLast;    // previous camera rotation
	Quaternion momentum; // camera momentum//实现平滑变化的效果
	int tLast;           // time of previous drag

	//记录x和y变化的总和
	int movX ;
	int movY ;
	bool rolling ; //表示是否正处于可以旋转的状态

	Quaternion getClickQuaternion(const int x, const int y); //得到要变化的四元组

public:
	static ClickToSphre* sharedInstance();
	static void Destroy();											//负责删除对象

	void clickMouse(int button, int state, int x, int y);				//点击鼠标的时候调用
	void mouseMotion(int x, int y , bool saveXY = true);											//鼠标移动的时候调用
	void mouseIdle();																//模拟惯性
	void applyMouseMotion();												//使用鼠标操作

	int getMovX() {return movX ;} ;
	int getMovY() {return movY ;} ;

	Eigen::MatrixXf getMatrix() ; //得到变换矩阵
	
};

#endif