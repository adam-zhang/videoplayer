#include "MainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QVideoWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QFileDialog>

MainWindow::MainWindow()
	: player_(0)
{
	createControls();
	setGeometry(100, 100, 800, 600);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createControls()
{
	makePlayer();
	auto layout = new QVBoxLayout(this);
	layout->addWidget(makeVideoWidget());
	layout->addWidget(makeProgressControl());
	layout->addLayout(makeControlWidget());
}

void MainWindow::makePlayer()
{
	player_ = new QMediaPlayer(this);
	connect(player_, &QMediaPlayer::positionChanged, this, &MainWindow::onPositionChanged);
}

void MainWindow::onPositionChanged(qint64 /*value*/)
{

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
	layout->addWidget(makeOpenButton());
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

QWidget* MainWindow::makeOpenButton()
{
	auto w = new QPushButton("&Open");
	connect(w, &QPushButton::clicked, this, &MainWindow::onOpenButtonClicked);
	return w;
}

void MainWindow::onOpenButtonClicked()
{
	auto fileName = QFileDialog::getOpenFileName(this, tr("Open Video"), ".", tr("Video Files(*.mp4)"));
	player_->setMedia(QUrl::fromLocalFile(fileName));
}
