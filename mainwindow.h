#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtWidgets>
#include "calendar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void addEvent();
    void removeEvent();
    void editEvent();
    void showInformation();
private:
    void closeEvent(QCloseEvent* event);

    Calendar* m_calendar;
};

#endif // MAINWINDOW_H
