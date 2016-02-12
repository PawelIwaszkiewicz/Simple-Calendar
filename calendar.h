#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <QtWidgets>
#include <QtCore>
#include "event.h"

class Calendar : public QWidget
{
    Q_OBJECT
public:
    explicit Calendar(QWidget *parent = 0);

    void addEvent(Event event);
    void removeEvent();
    void readData();
    void writeData();
protected slots:
    void eventClicked(QListWidgetItem* item);
    void eventDoubleClicked(QListWidgetItem* item);
private:
    bool isEventNameInUse(QString name);

    QCalendarWidget* m_calendarWidget;
    QListWidget* m_eventsList;
    QMap<QString, Event> m_events;
};

#endif // CALENDAR_H
