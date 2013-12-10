#include "qtglframework.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGLFramework w;
	w.show();
	return a.exec();
}
