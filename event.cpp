#include "event.h"

Event::Event()
{
    m_date.setDate(QDate::currentDate().year(), QDate::currentDate().month(), QDate::currentDate().day());
}

Event::Event(uint day, uint month, uint year, QString name, QString description)
{
    if(validateDate(day, month))
    {
        m_date.setDate(year, month, day);
    }

    m_name = name;
    m_description = description;
}

void Event::setDate(uint day, uint month, uint year)
{
    if(validateDate(day, month))
    {
        m_date.setDate(year, month, day);
    }
}

void Event::setName(QString name)
{
    m_name = name;
}

void Event::setDescription(QString description)
{
    m_description = description;
}

bool Event::validateDate(uint day, uint month)
{
    if(day <= 31 && month <= 12)
        return true;
    else
        return false;
}
