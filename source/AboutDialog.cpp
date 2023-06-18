/********************************************************************************
> FileName:	AboutDialog
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Sun Jun 18 08:51:28 2023
********************************************************************************/

#include "AboutDialog.h"
#include <QDialogButtonBox>

AboutDialog::AboutDialog(QWidget* parent)
	: QDialog(parent)
{
	initialize();
}

AboutDialog::~AboutDialog()
{

}

void AboutDialog::initialize()
{
	auto box = new QDialogButtonBox(QDialogButtonBox::Ok, this);
	connect(box, &QDialogButtonBox::accepted, this, &AboutDialog::onAccpted);
}

void AboutDialog::onAccpted()
{
	close();
}

