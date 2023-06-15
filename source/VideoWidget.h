/********************************************************************************
> FileName:	VideoWidget
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Thu Jun 15 11:07:25 2023
********************************************************************************/

#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>

class VideoWidget : public QWidget
{
	Q_OBJECT
public:
	VideoWidget(QWidget* = nullptr);
	~VideoWidget();
};
#endif//VIDEOWIDGET_H
