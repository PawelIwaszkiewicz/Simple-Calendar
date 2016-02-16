#include "mainwindow.h"
#include "event.h"
#include "eventdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(QSize(1240, 720));

    m_calendar = new Calendar();

    QMenu* applcationMenu = new QMenu(tr("&Applcation"), this);
    this->menuBar()->addMenu(applcationMenu);
    applcationMenu->addAction(tr("&Add Event"), this, SLOT(addEvent()));
    applcationMenu->addAction(tr("&Remove Event"), this, SLOT(removeEvent()));
    applcationMenu->addAction(tr("&Edit Event"), this, SLOT(editEvent()));
    applcationMenu->addAction(tr("&Close"), this, SLOT(close()));

    QMenu* helpMenu = new QMenu(tr("&Help"), this);
    this->menuBar()->addMenu(helpMenu);
    helpMenu->addAction(tr("&About"), this, SLOT(showInformation()));

    this->setCentralWidget(m_calendar);
    m_calendar->readData();
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_calendar->writeData();
    event->accept();
}

void MainWindow::addEvent()
{
    EventDialog dialog;
    dialog.setWindowTitle(tr("Add Event"));
    dialog.setModal(true);

    if(dialog.exec() == QDialog::Accepted)
    {
        Event tmpEvent = dialog.getUserEvent();

        if((!tmpEvent.getName().isEmpty()) && (!tmpEvent.getDescription().isEmpty()))
        {
            m_calendar->addEvent(tmpEvent);
        }

        else
        {
            QMessageBox::warning(this, tr("Warning"),
                                    tr("can not create event with empty name or description!"));
        }
    }
}

void MainWindow::removeEvent()
{
    m_calendar->removeEvent();
}

void MainWindow::editEvent()
{
    m_calendar->editEvent();
}

void MainWindow::showInformation()
{
    QMessageBox::information(this, "Information",
                                tr("<b>This app will help you storage your events information."
                                " Click application menu to show all options. <br>"
                                " created by: Paweł Iwaszkiewicz</b>"));
}
