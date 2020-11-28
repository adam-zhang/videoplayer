#include "VideoWidget.h"
#include <QKeyEvent>

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
