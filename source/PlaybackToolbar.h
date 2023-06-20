/********************************************************************************
> FileName:	PlaybackToolbar
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Tue Jun 20 09:29:15 2023
********************************************************************************/

#ifndef PLAYBACKTOOLBAR_H
#define PLAYBACKTOOLBAR_H

#include <QWidget>

class PlaybackToolbar : public QWidget
{
	Q_OBJECT
public:
	PlaybackToolbar(QWidget* = nullptr);
	~PlaybackToolbar();
};
#endif//PLAYBACKTOOLBAR_H
