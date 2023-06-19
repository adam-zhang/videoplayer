#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();

private:
	void initialize();
	void createMenu();
	void  createStatusbar();
	void createFileMenu();
	void createHelpMenu();
	void createToolMenu();
private slots:
	void onOpenAction();	
	void onExitAction();
	void onAboutAction();
	void onTestAction();

};

#endif//MAINWINDOW_H
