#ifndef DOUFEI_GLWIDGET_H
#define DOUFEI_GLWIDGET_H
#include <QtOpenGL/QGLWidget>
#include "Vec3D.h"
#include "mesh.h"

enum RenderMode
{
	renderFill, //������
	renderLine, //��������
	renderFillWire,//��������ʱ����line
	renderFlat, //��ƽ����ʾ��ʹ����Ƭ�ķ���
	renderNum //֧�ֵĻ���������Ŀ
};

class GLWidget : public QGLWidget 
{
	Q_OBJECT
public:
	GLWidget(QWidget *parent = NULL ) ;
	~GLWidget() ;
	void smoothZooming(bool open = true) ; //�Է�������ƽ��

public slots :
	void openFile(QString fileName) ; //���ļ�����
	void fillMode() ; //���ֻ���ģʽ��ת��
	void lineMode() ;
	void fileWireMode() ;
	void fillFlat() ;

	void fillMode(bool flag) ; //���ֻ���ģʽ��ת�䣬ʹ���Ҳ�������
	void lineMode(bool flag) ;
	void fileWireMode(bool flag) ;
	void fillFlat(bool flag) ;

signals:
	void updateStatusBar(float fps, int nVerts, int nFaces) ;

protected:
	void initializeGL( ) ;
	void resizeGL(int w, int h) ;
	void paintGL( ) ;
	void mousePressEvent(QMouseEvent * e) ;
	void mouseMoveEvent(QMouseEvent *e) ;
	void mouseReleaseEvent(QMouseEvent *e) ;
	void wheelEvent(QWheelEvent * e) ;
	void keyPressEvent(QKeyEvent * e) ;
	void timerEvent(QTimerEvent *e) ; //ģ��idle����
	void updateDisplayList() ; //���»����б�
	void drawMesh() ; //�������������б���ֱ�ӵ��ý��л���
	void drawSurface() ; //�����б�����
private:
	void initLighting() ; //��ʼ���ƹ�
	void initMaterial() ; //��ʼ������
	void updateFPS() ; //ͳ��֡��

private:
	float fps ; //֡��
	Vec3Df eyePos ; //�ӵ�λ��
	float deltaEyeDistance ; //�������ӵ�Զ����ƽ��
	Mesh *mesh;

	// OpenGL handles
	GLuint dispListID;  // surface display list
	RenderMode mode; // ��Ⱦ��ʽ

};




#endif