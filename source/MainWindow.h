#ifndef __MAINWINDOW__H
#define __MAINWINDOW__H

#include <QDialog>
#include <QWidget>

class QMediaPlayer;
class VideoWidget;
class QSlider;
class QKeyEvent;

class MainWindow : public QWidget
{
	Q_OBJECT
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
	VideoWidget* videoWidget_;
	QSlider* slider_;
	QWidget* screen_;
public:
	void showFullScreen();
private slots:
	void onOpenButtonClicked();
	void onPositionChanged(qint64);
	void onExitFullScreen();
private:
	void keyPressEvent(QKeyEvent* event);
	QSize getScreenSize();

};
#endif//__MAINWINDOW__H
