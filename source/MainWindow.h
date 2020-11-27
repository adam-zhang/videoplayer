#ifndef __MAINWINDOW__H
#define __MAINWINDOW__H

#include <QDialog>

class MainWindow : public QDialog
{
public:
	MainWindow();
	~MainWindow();
private:
	void createControls();
	QWidget* makeVideoWidget();
	QWidget* makeProgressControl();
	QLayout* makeControlWidget();
	QWidget* makePlayButton();
	QWidget* makeStopButton();
};
#endif//__MAINWINDOW__H
