/********************************************************************************
> FileName:	ControlWidget
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Thu Jun 15 11:07:54 2023
********************************************************************************/

#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>

class ControlWidget : public QWidget
{
	Q_OBJECT
public:
	ControlWidget(QWidget* = nullptr);
	~ControlWidget();
};
#endif//CONTROLWIDGET_H
