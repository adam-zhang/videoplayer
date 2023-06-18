#include "MainWindow.h"
#include "MainWidget.h"
#include <QMenuBar>

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
	
}


void MainWindow::createToolMenu()
{
	auto menu = menuBar()->addMenu("&Tools");

}

void MainWindow::createStatusbar()
{

}

