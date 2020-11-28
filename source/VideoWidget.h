#ifndef __VIDEOWIDGET__H
#define __VIDEOWIDGET__H

#include <QVideoWidget>

class QKeyEvent;

class VideoWidget : public QVideoWidget
{
	Q_OBJECT
public:
	VideoWidget(QWidget* parent = 0);
	~VideoWidget();
signals:
	void exitFullScreen();
	void enterFullScreen();
protected:
	void keyPressEvent(QKeyEvent* e);
	void mouseDoubleClickEvent(QMouseEvent* e);
};
#endif//__VIDEOWIDGET__H
