#ifndef EVENT_H
#define EVENT_H

#include <QtCore>

class Event
{
public:
    Event(QDate date, QString name, QString description);
    Event();

    QDate getDate() { return m_date; }
    QString getName() { return m_name; }
    QString getDescription() { return m_description; }

    void setDate(QDate date);
    void setName(QString name);
    void setDescription(QString description);
private:
    QDate m_date;
    QString m_name;
    QString m_description;

};

#endif // EVENT_H
