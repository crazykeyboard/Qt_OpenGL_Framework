#ifndef		DOUFEI_CLICKTOSPHERE_HEADER
#define		DOUFEI_CLICKTOSPHERE_HEADER
#include "Quaternion.h"
#include <Eigen/Dense>

/************************************************************************
* ʹ��˵����
*1. ��glutMouseFunc��ע�ắ���е���clickMouse����
*2. ��glutMotionFunc��ע�ắ���е���mouseMotion����
*3. ��glutIdleFunc��ע�ắ���е���mouseIdle����
*4. ��glutDisplayFunc�����У����Ʋ���ǰ����applyMouseMotion
************************************************************************/

class ClickToSphre
{
private:
	ClickToSphre();					//��ֹ�ⲿ�����¶���
	~ClickToSphre(){};					//��ֹ�ⲿɾ������
	ClickToSphre(const ClickToSphre& c){ movX = 0; movY = 0;};				//��ֹ�ⲿ����
	void operator = (const ClickToSphre& c){};		//��ֹ��ֵ����Ķ���
	static ClickToSphre * m_instance;


	Quaternion pClick;   // mouse coordinates of current click
	Quaternion pDrag;    // mouse coordinates of current drag
	Quaternion pLast;    // mouse coordinates of previous drag
	Quaternion rLast;    // previous camera rotation
	Quaternion momentum; // camera momentum//ʵ��ƽ���仯��Ч��
	int tLast;           // time of previous drag

	//��¼x��y�仯���ܺ�
	int movX ;
	int movY ;
	bool rolling ; //��ʾ�Ƿ������ڿ�����ת��״̬

	Quaternion getClickQuaternion(const int x, const int y); //�õ�Ҫ�仯����Ԫ��

public:
	static ClickToSphre* sharedInstance();
	static void Destroy();											//����ɾ������

	void clickMouse(int button, int state, int x, int y);				//�������ʱ�����
	void mouseMotion(int x, int y , bool saveXY = true);											//����ƶ���ʱ�����
	void mouseIdle();																//ģ�����
	void applyMouseMotion();												//ʹ��������

	int getMovX() {return movX ;} ;
	int getMovY() {return movY ;} ;

	Eigen::MatrixXf getMatrix() ; //�õ��任����
	
};

#endif