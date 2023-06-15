/********************************************************************************
> FileName:	Player
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Thu Jun 15 13:19:18 2023
********************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject
{
	Q_OBJECT
public:
	Player(QObject* = nullptr);
	~Player();
};
#endif//PLAYER_H
