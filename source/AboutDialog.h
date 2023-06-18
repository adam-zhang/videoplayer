/********************************************************************************
> FileName:	AboutDialog
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Sun Jun 18 08:51:28 2023
********************************************************************************/

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

class AboutDialog : public QDialog
{
	Q_OBJECT
public:
	AboutDialog(QObject* = nullptr);
	~AboutDialog();
};
#endif//ABOUTDIALOG_H
