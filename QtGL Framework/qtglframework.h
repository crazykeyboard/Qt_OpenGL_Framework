#ifndef QTGLFRAMEWORK_H
#define QTGLFRAMEWORK_H

#include <QtGui/QMainWindow>
#include "ui_qtglframework.h"
#include "glWidget.h"
#include <QtGui/QLabel>

class QtGLFramework : public QMainWindow
{
	Q_OBJECT

public:
	QtGLFramework(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtGLFramework();
	
protected:
	void keyPressEvent(QKeyEvent *e) ;
	void setVisible(bool flag) ;

private:
	Ui::QtGLFrameworkClass ui;
	GLWidget *glwidget;
	QLabel *fpsLabel ;
	
public slots:
		void openFile() ;
		void updateStatusBar(float fps, int nVerts, int nFaces) ;
		void changeFullScreen() ; //��ȫ���ͷ�ȫ��֮���л�

		//����radio�е�ѡ��
		void setFillMode() ;
		void setLineMode() ;
		void setFillWireMode() ;
		void setFlatMode() ;

signals:
		void openFile(QString fileName) ;


};

#endif // QTGLFRAMEWORK_H
