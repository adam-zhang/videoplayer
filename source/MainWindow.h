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
	void createPlaybackMenu();
private:
	//QAction* playAction_ = nullptr;
	//QAction* pauseAction_ = nullptr;
	//QAction* stopAction_ = nullptr;
private slots:
	void onOpenAction();	
	void onExitAction();
	void onAboutAction();
	void onTestAction();
	//void onPlayAction();
	//void onPauseAction();
	//void onStopAction();
};

#endif//MAINWINDOW_H
