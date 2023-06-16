/********************************************************************************
> FileName:	Player
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Thu Jun 15 13:19:18 2023
********************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QVector>
#include <QString>

class Player : public QObject
{
	Q_OBJECT
public:
	explicit Player(const QVector<QString>& list);
	~Player();
public:
	QVector<QString> list_;
};
#endif//PLAYER_H
