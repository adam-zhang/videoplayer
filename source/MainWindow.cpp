#include "MainWindow.h"
#include <QHBoxLayout>
#include <QSlider>
#include <QVideoWidget>
#include <QPushButton>

MainWindow::MainWindow()
{
	createControls();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createControls()
{
	auto layout = new QHBoxLayout(this);
	layout->addWidget(makeVideoWidget());
	//layout->addWidget(makeProgressControl());
	//layout->addLayout(makeControlWidget());
}


QWidget* MainWindow::makeVideoWidget()
{
	auto w = new QVideoWidget;
	return w;
}

QWidget* MainWindow::makeProgressControl()
{
	auto w = new QSlider;
	return w;
}

QLayout* MainWindow::makeControlWidget()
{
	auto layout = new QHBoxLayout;
	layout->addStretch();
	layout->addWidget(makePlayButton());
	layout->addWidget(makeStopButton());
	layout->addStretch();
	return layout;
}

QWidget* MainWindow::makePlayButton()
{
	auto w = new QPushButton("&Play");
	return w;
}

QWidget* MainWindow::makeStopButton()
{
	auto w = new QPushButton("&Stop");
	return w;
}
