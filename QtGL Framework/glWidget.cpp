#include "glWidget.h"
#include <gl/GL.h>
#include <gl/glut.h>
#include <QKeyEvent>
#include "clickToSphere.h"
#include <ctime>
#include <iostream>
using namespace std;

///////////////////////////////开启和关闭帧速垂直同步///////////////////////////////////////////begin
typedef void (APIENTRY *PFNWGLEXTSWAPCONTROLPROC) (int);
typedef int (*PFNWGLEXTGETSWAPINTERVALPROC) (void);
PFNWGLEXTSWAPCONTROLPROC wglSwapIntervalEXT = NULL;
PFNWGLEXTGETSWAPINTERVALPROC wglGetSwapIntervalEXT = NULL;
// 初始化函数指针接口
bool InitVSync()
{
	char* extensions = (char*)glGetString(GL_EXTENSIONS);
	if (strstr(extensions,"WGL_EXT_swap_control")) {
		wglSwapIntervalEXT = (PFNWGLEXTSWAPCONTROLPROC)wglGetProcAddress("wglSwapIntervalEXT");
		wglGetSwapIntervalEXT = (PFNWGLEXTGETSWAPINTERVALPROC)wglGetProcAddress("wglGetSwapIntervalEXT");
		return true;
	}
	return false;
}

// 判断当前状态是否为垂直同步
bool IsVSyncEnabled()
{
	return (wglGetSwapIntervalEXT() > 0);
}

// 开启和关闭垂直同步
void SetVSyncState(bool enable)
{
	if (enable)
		wglSwapIntervalEXT(1);
	else 
		wglSwapIntervalEXT(0);
}
///////////////////////////////开启和关闭帧速垂直同步///////////////////////////////////////////end


void GLWidget :: fillMode()
{
	mode = renderFill ;
	updateDisplayList() ;
}
void GLWidget :: lineMode()
{
	mode = renderLine ;
	updateDisplayList() ;
}
void GLWidget :: fileWireMode()
{
	mode = renderFillWire ;
	updateDisplayList() ;
}

void GLWidget :: fillFlat()
{
	mode = renderFlat ;
	updateDisplayList() ;
}

void GLWidget :: fillMode(bool flag)
{
	if (!flag) return ;
	mode = renderFill ;
	updateDisplayList() ;
}
void GLWidget :: lineMode(bool flag)
{
	if (!flag) return ;
	mode = renderLine ;
	updateDisplayList() ;
}
void GLWidget :: fileWireMode(bool flag)
{
	if (!flag) return ;
	mode = renderFillWire ;
	updateDisplayList() ;
}

void GLWidget :: fillFlat(bool flag)
{
	if (!flag) return ;
	mode = renderFlat ;
	updateDisplayList() ;
}


void GLWidget :: openFile(QString fileName)
{
	string fname = fileName.toStdString() ;
	mesh->openOFF(fname) ;
	updateDisplayList() ;
}


GLWidget :: GLWidget(QWidget *parent) : QGLWidget(parent) 
{
	fps = 0.0f ;
	eyePos.init(0, 0, 3.6) ;
	dispListID = 0 ;
	deltaEyeDistance = 0 ;
	mode = renderFill ;
	mesh = new Mesh() ;
	if(!mesh->openOFF("../models/octopus.off") )
		cout << "Failed to load file ... " << endl;
	setMouseTracking(true) ;
	startTimer(0) ;
	setFocusPolicy(Qt::StrongFocus); //鼠标事件响应
	//更新帧速
	connect(this, SIGNAL(updateStatusBar(float , int , int )), parent, SLOT(updateStatusBar(float , int , int ))) ;

}
GLWidget :: ~GLWidget()
{
	if (dispListID)
	{
		glDeleteLists(dispListID, 1) ;
	}
}

void GLWidget :: updateFPS()
{
	static clock_t lastTime = clock() ;
	static int rendTimes = 0 ; //渲染的次数
	rendTimes ++ ;
	if (clock() - lastTime >= 1000)
	{
		fps = (float)rendTimes / ((float)(clock() - lastTime) / 1000.0) ; 
		lastTime = clock() ;
		rendTimes = 0 ;
		emit updateStatusBar(fps, mesh->nVertices(), mesh->nVertices()) ;
	}
}

void GLWidget :: timerEvent(QTimerEvent *e) //模拟idle函数
{
	ClickToSphre :: sharedInstance() ->mouseIdle() ;
	//Add code here
	smoothZooming(true) ; //平滑放缩操作


	updateGL() ;
}

void GLWidget :: initializeGL()
{
	glShadeModel(GL_SMOOTH) ;
	glClearColor(1.0f, 1.0f, 1.f, 0.0f) ;
	glClearDepth(1.0f) ;
	glEnable(GL_DEPTH_TEST) ;
	glDepthFunc(GL_LEQUAL) ;
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST) ;
	initLighting() ; //初始化灯光
	initMaterial() ; //初始化材质
	updateDisplayList() ; //构建绘制列表

	//关闭帧速垂直同步
	bool isOk = InitVSync(); 
	if (isOk) {
		SetVSyncState(false);
	}
}

void GLWidget :: resizeGL(int w, int h) 
{
	if (h == 0)
		h = 1 ;
	glViewport(0, 0, w, h) ;
	glMatrixMode(GL_PROJECTION) ;
	glLoadIdentity() ;
	gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f) ;
	glMatrixMode(GL_MODELVIEW) ;
	glLoadIdentity() ;
}

void GLWidget :: paintGL( ) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// 清除屏幕及深度缓存
	glLoadIdentity();					// 重置模型观察矩阵
	gluLookAt(eyePos[0], eyePos[1], eyePos[2], 0, 0, 0, 0, 1, 0) ;
	ClickToSphre :: sharedInstance()->applyMouseMotion() ;
	drawSurface() ;
	 updateFPS() ; //计算FPS
}

void GLWidget :: initLighting()
{
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };  
	GLfloat local_view[] = { 0.0 };  
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };  
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };  
	GLfloat position[] = { 0.0, 1.0, 1.0, 0.0 };  
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);  
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);  
	glLightfv(GL_LIGHT0, GL_POSITION, position);  
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);  
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);  
}

void GLWidget :: initMaterial() 
{
	GLfloat     zero[4] = { 0., 0., 0., 1. };
	GLfloat  diffuse[4] = { .8, .5, .3, 1. };
	GLfloat specular[4] = { .3, .3, .3, 1. };
	GLfloat  ambient[4] = { .2, .2, .5, 1. };

	glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE,   diffuse  );
	glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR,  specular );
	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT,   ambient  );
	glMaterialf ( GL_FRONT_AND_BACK, GL_SHININESS, 16.      );
	glEnable(GL_COLOR_MATERIAL);
}


void GLWidget :: mousePressEvent(QMouseEvent * e)
{
	if (e->button() == Qt::LeftButton)
	{
		deltaEyeDistance = 0. ; //停止放缩（停止平滑操作）
		ClickToSphre :: sharedInstance()->clickMouse(0, GLUT_DOWN, e->x(), e->y()) ;
	}
}

void GLWidget :: mouseMoveEvent(QMouseEvent *e)
{
	ClickToSphre :: sharedInstance() ->mouseMotion(e->x(), e->y() ) ;

}
void GLWidget :: mouseReleaseEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
		ClickToSphre :: sharedInstance()->clickMouse(0, GLUT_UP, e->x(), e->y()) ;

}
void GLWidget :: wheelEvent(QWheelEvent * e)
{
	deltaEyeDistance += e->delta() / 600.0 ; //在[-120, 120]之间


}

void GLWidget :: keyPressEvent(QKeyEvent * e)
{
	e->ignore() ;
	switch (e->key())
	{
	case Qt :: Key_Escape :
		break;
	default:
		break;
	}
}

void GLWidget :: drawMesh()
{
	const vector<Vertex> & V = mesh->getVertices();
	const vector<Triangle> & T = mesh->getTriangles();

	if (mode == renderFill || mode == renderFillWire)
	{
		glEnable( GL_POLYGON_OFFSET_FILL );
		glPolygonOffset( 1., 1. );
		glBegin (GL_TRIANGLES);
		for (unsigned int i = 0; i < T.size (); i++) {
			const Triangle & t = T[i];
			for (unsigned int j = 0; j < 3; j++) 
			{
				glNormalVec3Df (V[t.getVertex (j)].getNormal ());
				glVertexVec3Df (V[t.getVertex (j)].getPos ());
			}
		}
		glEnd ();
		glDisable( GL_POLYGON_OFFSET_FILL );

		if (mode == renderFillWire)
		{
			glDisable(GL_LIGHTING) ;
			glColor4f(0., 0., 0., .25) ;
			glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
			glEnable( GL_BLEND );
			glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

			glBegin( GL_TRIANGLES );
			for (unsigned int i = 0; i < T.size (); i++) {
				const Triangle & t = T[i];
				for (unsigned int j = 0; j < 3; j++) 
				{
					glNormalVec3Df (V[t.getVertex (j)].getNormal ());
					glVertexVec3Df (V[t.getVertex (j)].getPos ());
				}
			}
			glEnd() ;
		}
	}
	else
		if (mode == renderLine)
		{
			glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
			glBegin( GL_TRIANGLES );
			for (unsigned int i = 0; i < T.size (); i++) {
				const Triangle & t = T[i];
				for (unsigned int j = 0; j < 3; j++) 
				{
					glNormalVec3Df (V[t.getVertex (j)].getNormal ());
					glVertexVec3Df (V[t.getVertex (j)].getPos ());
				}
			}
			glEnd() ;
		}
		else
			if (mode == renderFlat)
			{
				glEnable( GL_POLYGON_OFFSET_FILL );
				glPolygonOffset( 1., 1. );
				glBegin (GL_TRIANGLES);
				for (unsigned int i = 0; i < T.size (); i++) {
					const Triangle & t = T[i];
					Vec3Df normal = Vec3Df::crossProduct (V[t.getVertex (1)].getPos ()
						- V[t.getVertex (0)].getPos (),
						V[t.getVertex (2)].getPos ()
						- V[t.getVertex (0)].getPos ());
					normal.normalize ();
					glNormalVec3Df (normal);
					for (unsigned int j = 0; j < 3; j++) 
						glVertexVec3Df (V[t.getVertex (j)].getPos ());
				}
				glEnd ();
				glDisable( GL_POLYGON_OFFSET_FILL );
			}
}

void GLWidget :: updateDisplayList()
{
	if (dispListID)
	{
		glDeleteLists(dispListID, 1) ;
		dispListID = 0;
	}
	dispListID = glGenLists( 1 ) ;
	glNewList(dispListID, GL_COMPILE) ;
	drawMesh() ;
	glEndList() ;
}

void GLWidget :: drawSurface()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS) ;
	glEnable(GL_DEPTH_TEST) ;
	glEnable(GL_LIGHTING) ;
	glEnable(GL_LIGHT0) ;
	glColor4f(0.8, 0.5, 0.3, 0.6) ;
	glEnable(GL_COLOR_MATERIAL) ;
	glCallList(dispListID) ;
	glDisable(GL_DEPTH_TEST) ;
	glDisable(GL_LIGHTING) ;
	glDisable(GL_LIGHT0) ;
	glPopAttrib() ;
}

void GLWidget :: smoothZooming(bool open)
{
	if (!open)
	{
		eyePos[2] -= deltaEyeDistance ;
		deltaEyeDistance = 0. ;
	}
	int updateCount = 100 ;
	static clock_t t0 = clock() ;
	if ((float)(clock() - t0) / CLOCKS_PER_SEC >= 1. / updateCount)
	{
		eyePos[2] -= deltaEyeDistance / updateCount ;
		deltaEyeDistance -= deltaEyeDistance / updateCount ;
		if (fabs(deltaEyeDistance) < 0.00001 ) deltaEyeDistance = 0. ;
		t0 = clock() ;
	}
	if (eyePos[2] < 0.1) 
	{
		eyePos[2] = 0.1 ;
		deltaEyeDistance = 0. ;
	}
	
}