#include <QApplication>
#include "MainWindow.h"

int main(int argc, char** argv)
{
	QApplication a(argc, argv);
	MainWindow d;
	d.show();
	return a.exec();
}
