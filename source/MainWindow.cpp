#include "MainWindow.h"
#include <QTimer>
#include <QKeyEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include "VideoWidget.h"
#include <QMouseEvent>
#include <QPushButton>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QGuiApplication>
#include <QScreen>

MainWindow::MainWindow()
	: player_(0)
	  ,videoWidget_(0)
	  ,slider_(0)
	  , screen_(0)
	  , timer_(0)
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
	//connect(player_, &QMediaPlayer::positionChanged, this, &MainWindow::onPositionChanged);
	connect(player_, &QMediaPlayer::mediaChanged, this, &MainWindow::onMediaChanged);
}

void MainWindow::onPositionChanged(qint64 value)
{
	if (player_->duration() == 0)
		return;
	int v = value / float(player_->duration()) * 100;
	qDebug() << "before set value:" << value << ":" << player_->duration() << ":" << v;
	//slider_->setValue(0);
}

void MainWindow::skip(qint64 value)
{
	player_->setPosition(player_->position() + value * 1000);
	qDebug() << "current position:" << player_->position();
}


QWidget* MainWindow::makeVideoWidget()
{
	auto w = new VideoWidget;
	videoWidget_ = w;
	connect(w, &VideoWidget::exitFullScreen, this, &MainWindow::onExitFullScreen);
	connect(w, &VideoWidget::enterFullScreen, this, &MainWindow::onEnterFullScreen);
	return w;
}

QWidget* MainWindow::makeProgressControl()
{
	auto w = new QSlider;
	w->setOrientation(Qt::Horizontal);
	w->setMinimum(0);
	w->setMaximum(100);
	slider_ = w;
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
	player_->setVolume(100);
	player_->setVideoOutput(videoWidget_);
	player_->play();
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Enter|| event->key() == Qt::Key_F)
		showFullScreen();
	else if (event->key() == Qt::Key_Up)
		skip(30);
	else if (event->key() == Qt::Key_Down)
		skip(-30);
	else if (event->key() == Qt::Key_Right)
		skip(10);
	else if (event->key() == Qt::Key_Left)
		skip(-10);
}
void MainWindow::showFullScreen()
{
	videoWidget_->setFullScreen(true);
}

void MainWindow::onExitFullScreen()
{
	videoWidget_->setFullScreen(false);
}

QSize MainWindow::getScreenSize()
{
	auto screen = QGuiApplication::primaryScreen();
	auto rect = screen->availableGeometry();
	return QSize(rect.width(), rect.height());
}


void MainWindow::mouseDoubleClickEvent(QMouseEvent* )
{
	videoWidget_->setFullScreen(true);
}

void MainWindow::onEnterFullScreen()
{
	videoWidget_->setFullScreen(true);
}

void MainWindow::onMediaChanged()
{
	if (player_->mediaStatus() == QMediaPlayer::NoMedia && timer_ != nullptr)
	{
		timer_->stop();
		delete timer_;
		timer_ = nullptr;
	}
	else
	{
		timer_ = new QTimer(this);
		timer_->setInterval(1000);
		connect(timer_, &QTimer::timeout, this, &MainWindow::onTimeout);
		timer_->start();
	}
}

void MainWindow::onTimeout()
{
	auto percentage = player_->position() / float(player_->duration()) * 100;
	slider_->setValue(percentage);
}
