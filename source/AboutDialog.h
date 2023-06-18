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
	AboutDialog(QWidget* = nullptr);
	~AboutDialog();
private:
	void initialize();
	QLayout* createInfoWidgets();
	QWidget* createButton();
private slots:
	void onAccpted();
};
#endif//ABOUTDIALOG_H
