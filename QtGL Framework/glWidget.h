#ifndef DOUFEI_GLWIDGET_H
#define DOUFEI_GLWIDGET_H
#include <QtOpenGL/QGLWidget>
#include "Vec3D.h"
#include "mesh.h"

enum RenderMode
{
	renderFill, //填充绘制
	renderLine, //不填充绘制
	renderFillWire,//在填充绘制时加上line
	renderFlat, //飞平滑显示，使用面片的法线
	renderNum //支持的绘制类型数目
};

class GLWidget : public QGLWidget 
{
	Q_OBJECT
public:
	GLWidget(QWidget *parent = NULL ) ;
	~GLWidget() ;
	void smoothZooming(bool open = true) ; //对放缩进行平滑

public slots :
	void openFile(QString fileName) ; //打开文件命令
	void fillMode() ; //三种绘制模式的转变
	void lineMode() ;
	void fileWireMode() ;
	void fillFlat() ;

	void fillMode(bool flag) ; //三种绘制模式的转变，使用右侧控制面板
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
	void timerEvent(QTimerEvent *e) ; //模拟idle函数
	void updateDisplayList() ; //更新绘制列表
	void drawMesh() ; //用来创建绘制列表，不直接调用进行绘制
	void drawSurface() ; //绘制列表内容
private:
	void initLighting() ; //初始化灯光
	void initMaterial() ; //初始化材质
	void updateFPS() ; //统计帧速

private:
	float fps ; //帧速
	Vec3Df eyePos ; //视点位置
	float deltaEyeDistance ; //用来做视点远近的平滑
	Mesh *mesh;

	// OpenGL handles
	GLuint dispListID;  // surface display list
	RenderMode mode; // 渲染方式

};




#endif