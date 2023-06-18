/********************************************************************************
> FileName:	AboutDialog
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Sun Jun 18 08:51:28 2023
********************************************************************************/

#include "AboutDialog.h"
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QLabel>

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
	auto layout = new QVBoxLayout(this);
	layout->addLayout(createInfoWidgets());
	layout->addWidget(createButton());
}

QWidget* AboutDialog::createButton()
{
	auto w = new QDialogButtonBox(QDialogButtonBox::Ok, this);
	connect(w, &QDialogButtonBox::accepted, this, &AboutDialog::onAccpted);
	return w;
}

QLayout* AboutDialog::createInfoWidgets()
{
	auto layout = new QGridLayout;
	layout->addWidget(new QLabel("Author:"), 0 ,0);
	layout->addWidget(new QLabel("Zhang Mingping"), 0, 1);
	layout->addWidget(new QLabel("Email:"), 1, 0);
	layout->addWidget(new QLabel("mingpingzhang@163.com"), 1 , 1);
	layout->addWidget(new QLabel("Website:"), 2, 0);
	layout->addWidget(new QLabel("github.com/adam-zhang"), 2, 1);
	return layout;
}



void AboutDialog::onAccpted()
{
	close();
}

