#include "VideoWidget.h"
#include <QKeyEvent>
#include <QMouseEvent>

VideoWidget::VideoWidget(QWidget* parent)
	: QVideoWidget(parent)
{
}

VideoWidget::~VideoWidget()
{
}

void VideoWidget::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Escape)
		emit exitFullScreen();
}

void VideoWidget::mouseDoubleClickEvent(QMouseEvent*)
{
	if (isFullScreen())
		emit enterFullScreen();
	else
		emit exitFullScreen();
}
