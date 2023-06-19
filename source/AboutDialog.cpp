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

QWidget* AboutDialog::createPictureWidget()
{
	auto label = new QLabel;
	QPixmap pixmap(":/images/zmp.head.png");
	label->setPixmap(pixmap);
	return label;
}

QLabel* createLink(const QString& text)
{
	auto label = new QLabel;
	label->setTextFormat(Qt::RichText);
	label->setTextInteractionFlags(Qt::TextBrowserInteraction);
	label->setOpenExternalLinks(true);
	label->setText(text);
	return label;
}

static QLabel* createMailLink()
{
	return createLink("<a href='mailto:zhangmingping@163.com'>mingpingzhang@163.com</a>");
}

static QLabel* createWeblink()
{
	return createLink("<a href='https://github.com/adam-zhang'>github.com/adam-zhang</a>");
}

QLayout* AboutDialog::createPersonalInfoWidgets()
{
	auto layout = new QGridLayout;
	layout->addWidget(new QLabel("Author:"), 0 ,0);
	layout->addWidget(new QLabel("Zhang Mingping"), 0, 1);
	layout->addWidget(new QLabel("Email:"), 1, 0);
	layout->addWidget(createMailLink(), 1, 1);
	layout->addWidget(new QLabel("Website:"), 2, 0);
	layout->addWidget(createWeblink(), 2, 1);
	return layout;
}

QLayout* AboutDialog::createInfoLayout()
{
	auto layout = new QVBoxLayout;
	layout->addLayout(createPersonalInfoWidgets());
	layout->addStretch();
	return layout;
}

QLayout* AboutDialog::createInfoWidgets()
{
	auto layout = new QHBoxLayout;
	layout->addWidget(createPictureWidget());
	layout->addLayout(createInfoLayout());
	return layout;
}



void AboutDialog::onAccpted()
{
	close();
}

