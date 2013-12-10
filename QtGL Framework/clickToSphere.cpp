#include "clickToSphere.h"
#include <time.h>
#include <gl/glut.h>
#include <gl/gl.h>
//#include <Eigen/Dense>
#define  NULL 0
ClickToSphre* ClickToSphre::m_instance = NULL;

ClickToSphre :: ClickToSphre()
{
	pClick = 1;
	pDrag = 1;
	pLast = 1;
	rLast = 1;
	momentum = 1;
	rolling = false ;
}

ClickToSphre* ClickToSphre::sharedInstance()
{
	if (NULL == m_instance)
	{
		m_instance = new ClickToSphre;
		atexit(ClickToSphre :: Destroy);				//程序退出时删除对象
	}

	return m_instance;
}
void ClickToSphre :: Destroy()
{
	if (NULL != m_instance)
	{
		delete m_instance;
		m_instance = NULL;
	}
}

Quaternion ClickToSphre::getClickQuaternion(const int x, const int y)
{
	int viewport[4];
	glGetIntegerv( GL_VIEWPORT, viewport );
	int w = viewport[2];
	int h = viewport[3];

	Quaternion p( 0.,
		2. * (double) x / (double) w - 1.,
		2. * (double) y / (double) h - 1.,
		0. );

	if( p.norm2() > 1. )
	{
		p.normalize();
		p.im()[2] = 0.;
	}
	else
	{
		p.im()[2] = sqrt( 1. - p.norm2() );
	}

	return p;
}

void ClickToSphre :: clickMouse(int button, int state, int x, int y)
{
	if (GLUT_DOWN == state)
	{
		rolling = true ;
		pClick = pDrag = pLast = getClickQuaternion(x, y);
		momentum = 1. ;
	}
	if (GLUT_UP == state)
	{
		rolling = false ;
		float  timeSinceDrag = (clock() - tLast) / (float)CLOCKS_PER_SEC;

		if (timeSinceDrag < 1. )
		{
			momentum = pDrag * (~pLast);
			momentum = (.03 * momentum + .97).unit();
		}
		else
		{
			momentum = 1 ;
		}

		rLast = pDrag * (~pClick) * rLast ;
		pClick = pDrag = -1. ;
	}
}

void ClickToSphre :: mouseMotion(int x ,int y , bool saveXY)
{
	if (!rolling) return ;
	if (saveXY)
	{
		movX += x ;
		movY += y ;
	}

	tLast = clock();
	pLast = pDrag ;
	pDrag = getClickQuaternion(x, y);
}

void ClickToSphre :: mouseIdle()
{
	static int t0 = clock();
	int t1 = clock();
	double dt = .5 * (t1-t0) / (double) CLOCKS_PER_SEC;
	rLast = momentum * rLast;
	momentum = ( (1.-dt) * momentum + dt ).unit();
	t0 = t1;


}

void ClickToSphre :: applyMouseMotion()
{
	glMatrixMode( GL_MODELVIEW );
	Quaternion r = ( pDrag * ( ~pClick )) * rLast;
	double w = r[0];
	double x = - r[1];
	double y = r[2];
	double z = - r[3];
	GLdouble M[16] = {
		1.-2.*y*y-2.*z*z, 2.*x*y+2.*w*z, 2.*x*z-2.*w*y, 0.,
		2.*x*y-2.*w*z, 1.-2.*x*x-2.*z*z, 2.*y*z+2.*w*x, 0.,
		2.*x*z+2.*w*y, 2.*y*z-2.*w*x, 1.-2.*x*x-2.*y*y, 0.,
		0., 0., 0., 1.
	};
	glMultMatrixd( M );

}


//得到变换矩阵
Eigen::MatrixXf ClickToSphre::getMatrix()
{
	Quaternion r = ( pDrag * ( ~pClick )) * rLast;
	double w = r[0];
	double x = - r[1];
	double y = r[2];
	double z = - r[3];
	GLdouble M[16] = {
		1.-2.*y*y-2.*z*z, 2.*x*y+2.*w*z, 2.*x*z-2.*w*y, 0.,
		2.*x*y-2.*w*z, 1.-2.*x*x-2.*z*z, 2.*y*z+2.*w*x, 0.,
		2.*x*z+2.*w*y, 2.*y*z-2.*w*x, 1.-2.*x*x-2.*y*y, 0.,
		0., 0., 0., 1.
	};

	Eigen::MatrixXf ret(4,4) ;
	for (int i = 0; i < 4; ++ i)
		for (int j = 0; j < 4; ++ j)
			ret(i, j) = M[ i * 4 + j ] ;

	return ret ;
}