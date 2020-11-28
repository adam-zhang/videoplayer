#ifndef __MAINWINDOW__H
#define __MAINWINDOW__H

#include <QDialog>
#include <QWidget>

class QMediaPlayer;
class VideoWidget;
class QSlider;
class QKeyEvent;
class QTimer;

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
	QTimer* timer_;
public:
	void showFullScreen();
private slots:
	void onOpenButtonClicked();
	void onPositionChanged(qint64);
	void onExitFullScreen();
	void onEnterFullScreen();
	void onMediaChanged();
	void onTimeout();
protected:
	void keyPressEvent(QKeyEvent* event);
	void mouseDoubleClickEvent(QMouseEvent* e);
private:
	QSize getScreenSize();
	void skip(qint64);

};
#endif//__MAINWINDOW__H
