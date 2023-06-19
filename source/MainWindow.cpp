#include "MainWindow.h"
#include "MainWidget.h"
#include "AboutDialog.h"
#include <QMenuBar>
#include <QLabel>

MainWindow::MainWindow(QWidget* parent)
	:QMainWindow(parent)
{
	initialize();
};

MainWindow::~MainWindow()
{
}

void MainWindow::initialize()
{
	setGeometry(100, 100, 800, 600);
	setCentralWidget(new MainWidget);
	createMenu();
	createStatusbar();
}

void MainWindow::createMenu()
{
	createFileMenu();
	createToolMenu();
	createHelpMenu();
}
void MainWindow::createFileMenu()
{
	auto menu = menuBar()->addMenu("&File");
	auto action = menu->addAction("&Open...");
	connect(action, &QAction::triggered, this, &MainWindow::onOpenAction);
	action = menu->addAction("E&xit...");
	connect(action, &QAction::triggered, this, &MainWindow::onExitAction);
}

void MainWindow::onExitAction()
{
	close();
}


void MainWindow::onOpenAction()
{

}

void MainWindow::createHelpMenu()
{
	auto menu = menuBar()->addMenu("&Help");
	auto action = menu->addAction("&About...");
	connect(action, &QAction::triggered, this, &MainWindow::onAboutAction);
}

void MainWindow::onAboutAction()
{
	auto dialog = new AboutDialog(this);
	dialog->exec();
}


void MainWindow::createToolMenu()
{
	auto menu = menuBar()->addMenu("&Tools");
	auto action = menu->addAction("&Test");
	connect(action, &QAction::triggered, this, &MainWindow::onTestAction);
}

void MainWindow::onTestAction()
{
	//auto label = new QLabel(this);
	//auto pixmap = QPixmap(":/zmp.head.png");
	//label->setPixmap(pixmap);
	//label->show();
}

void MainWindow::createStatusbar()
{

}

