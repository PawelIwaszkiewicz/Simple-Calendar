#include "event.h"

Event::Event()
{
    setDate(QDate::currentDate());
}

Event::Event(QDate date, QString name, QString description)
{
    setDate(date);
    m_name = name;
    m_description = description;
}

void Event::setDate(QDate date)
{
   m_date.setDate(date.year(), date.month(), date.day());
}

void Event::setName(QString name)
{
    m_name = name;
}

void Event::setDescription(QString description)
{
    m_description = description;
}

