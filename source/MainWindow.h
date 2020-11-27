#ifndef __MAINWINDOW__H
#define __MAINWINDOW__H

#include <QDialog>
#include <QWidget>

class QMediaPlayer;

class MainWindow : public QWidget
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
	QWidget* makeOpenButton();
	void makePlayer();

	QMediaPlayer* player_;

private slots:
	void onOpenButtonClicked();
	void onPositionChanged(qint64);

};
#endif//__MAINWINDOW__H
