#include "qtglframework.h"
#include <QKeyEvent>
#include <QtGui/QFileDialog>
#include <QtGui/QMessageBox>
#include <QtGui/QLabel>

void QtGLFramework :: changeFullScreen( )  //��ȫ���ͷ�ȫ��֮���л�
{
	if (this->isFullScreen())
		this->showNormal() ;
	else
		this->showFullScreen() ;
}


void QtGLFramework :: setVisible(bool flag)
{
	QMainWindow :: setVisible(flag) ;
}

void QtGLFramework :: updateStatusBar(float fps, int nVerts, int nFaces) 
{
	char fpsText[100] ;
	sprintf_s(fpsText, "   FPS: %.1f	Vertices: %d	Faces: %d ", fps, nVerts, nFaces) ;
	fpsLabel->setText(QString(fpsText)) ;

}

//�ı�radio��ֵ���źŲ�
void QtGLFramework :: setFillMode()
{
	ui.ctrPnlRFill->setChecked(true) ;
}
void QtGLFramework :: setLineMode()
{
	ui.ctrPnlRLine->setChecked(true) ;
}
void QtGLFramework :: setFillWireMode()
{
	ui.ctrPnlRFilewire->setChecked(true) ;
}
void QtGLFramework :: setFlatMode()
{
	ui.ctrPnlFlat->setChecked(true) ;
}

QtGLFramework::QtGLFramework(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	glwidget = new GLWidget(this) ;
	ui.glcontainter->addWidget(glwidget) ;
	ui.controlPanel->setVisible(false) ;

	fpsLabel = new QLabel() ;
	ui.statusBar->addWidget(fpsLabel) ;
	connect(ui.mFOpenFile, SIGNAL(triggered()), this, SLOT(openFile())) ; //���ļ����Ӳ�
	connect(this, SIGNAL(openFile(QString)), glwidget, SLOT(openFile(QString))) ;

	//ת�����Ʒ�ʽ
	connect(ui.mRFill, SIGNAL(triggered()), glwidget, SLOT(fillMode())) ;
	connect(ui.mRLine, SIGNAL(triggered()), glwidget, SLOT(lineMode())) ;
	connect(ui.mRFillWire, SIGNAL(triggered()), glwidget, SLOT(fileWireMode())) ;
	connect(ui.mRFlat,SIGNAL(triggered()), glwidget, SLOT(fillFlat())) ;

	connect(ui.mRFill, SIGNAL(triggered()), this, SLOT(setFillMode())) ;
	connect(ui.mRLine, SIGNAL(triggered()), this, SLOT(setLineMode())) ;
	connect(ui.mRFillWire, SIGNAL(triggered()), this, SLOT(setFillWireMode())) ;
	connect(ui.mRFlat,SIGNAL(triggered()), this, SLOT(setFlatMode())) ;

	//�ı䱻ѡ�е�radio

	//ת�����Ʒ�ʽ���Ҳ�������
	connect(ui.ctrPnlRFill, SIGNAL(clicked(bool)), glwidget, SLOT(fillMode(bool))) ;
	connect(ui.ctrPnlRLine, SIGNAL(clicked(bool)), glwidget, SLOT(lineMode(bool))) ;
	connect(ui.ctrPnlRFilewire, SIGNAL(clicked(bool)), glwidget, SLOT(fileWireMode(bool))) ;
	connect(ui.ctrPnlFlat,SIGNAL(clicked(bool)), glwidget, SLOT(fillFlat(bool))) ;

	//�Ƿ�ȫ��
	connect(ui.actionFull_Screen, SIGNAL(triggered()), this, SLOT(changeFullScreen())) ;


}

QtGLFramework::~QtGLFramework()
{

}

void QtGLFramework :: keyPressEvent(QKeyEvent *e)
{
	switch(e->key())
	{
	case Qt :: Key_Escape :
		if (isFullScreen())
			showNormal() ;
		else
			close() ;
		break;

	case Qt :: Key_QuoteLeft :
		ui.controlPanel->setVisible(!ui.controlPanel->isVisible()) ;
		break;
	default:
		e->ignore() ;
		break;
	}
}

void QtGLFramework :: openFile() //���ļ�
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open file"), ".", tr("Model Files(*.off)")); 
	if(path.length() == 0) { 
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files.")); 
	} else { 
		emit openFile(path) ;
	} 
}