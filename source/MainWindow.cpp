#include "MainWindow.h"
#include "MainWidget.h"

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
	setCentralWidget(new MainWidget);
	createMenu();
	createStatusbar();
}

void MainWindow::createMenu()
{
	createFileMenu();
	createHelpMenu();
	createToolMenu();
}
void MainWindow::createFileMenu()
{

}
void MainWindow::createHelpMenu()
{

}
void MainWindow::createToolMenu()
{

}




void MainWindow::createStatusbar()
{

}

