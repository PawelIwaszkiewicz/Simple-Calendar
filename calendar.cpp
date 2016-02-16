#include "calendar.h"
#include "eventdialog.h"

Calendar::Calendar(QWidget *parent) : QWidget(parent)
{
    m_calendarWidget = new QCalendarWidget();
    m_eventsList = new QListWidget();

    m_calendarWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_eventsList->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    QVBoxLayout* vLayout = new QVBoxLayout();
    vLayout->addWidget(m_eventsList);

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->addLayout(vLayout);
    mainLayout->addWidget(m_calendarWidget);

    this->setLayout(mainLayout);

    connect(m_eventsList, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(eventClicked(QListWidgetItem*)));
    connect(m_eventsList, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(eventDoubleClicked(QListWidgetItem*)));
}

void Calendar::writeData()
{

    QFile file("data.txt");
    file.open(QFile::WriteOnly);
    QTextStream fileStream(&file);

    if(!m_events.empty())
    {
        QMapIterator<QString, Event> itr(m_events);
        while(itr.hasNext())
        {
            QString name = itr.next().key();
            QString date = m_events[itr.key()].getDate().toString("dd.MM.yyyy");
            QString description = m_events[itr.key()].getDescription();

            fileStream << name << "\n" << date << "\n" << description << "\n\n";

        }
    }

     file.close();

}

void Calendar::readData()
{
    QFile file("data.txt");
    if(file.open(QFile::ReadOnly))
    {
       QString name, description;
       QDate date;
       QTextStream fileStream(&file);
       while(!fileStream.atEnd())
       {
           name = fileStream.readLine();
           if(name.isEmpty())
               continue;
           date = QDate::fromString(fileStream.readLine(), "dd.MM.yyyy");
           description = fileStream.readLine();

           addEvent(Event(date, name, description));
       }
       
       file.close();
    }
}

void Calendar::eventClicked(QListWidgetItem* item)
{
    QDate selectedEventDate = m_events[item->text()].getDate();
    m_calendarWidget->setSelectedDate(selectedEventDate);
}

void Calendar::eventDoubleClicked(QListWidgetItem *item)
{
    QString name = m_events[item->text()].getName();
    QString description = m_events[item->text()].getDescription();
    QString message = QString("<b>%1</b><br> %2").arg(name).arg(description);

    QMessageBox::information(this, "Information", message);
}

void Calendar::addEvent(Event event)
{
    if(!isEventNameInUse(event.getName()))
    {
        m_events.insert(event.getName(), event);
        m_eventsList->addItem(event.getName());
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Event already exist");
    }
}

void Calendar::removeEvent()
{

    QListIterator<QListWidgetItem*> itr(m_eventsList->selectedItems());
    while(itr.hasNext())
    {
        m_events.remove(itr.next()->text());
    }

    qDeleteAll(m_eventsList->selectedItems());
}

void Calendar::editEvent()
{
    QListIterator<QListWidgetItem*> itr(m_eventsList->selectedItems());
    while(itr.hasNext())
    {
        QString id = itr.next()->text();
        EventDialog dialog;
        dialog.setWindowTitle(tr("Edit Event"));
        dialog.setModal(true);
        dialog.setDefault(m_events[id].getDate(),
                m_events[id].getName(),
                m_events[id].getDescription());

        if(dialog.exec() == QDialog::Accepted)
        {
            Event tmpEvent = dialog.getUserEvent();

            if((!tmpEvent.getName().isEmpty()) && (!tmpEvent.getDescription().isEmpty()))
            {
                m_events[id].setDate(tmpEvent.getDate());
                m_events[id].setDescription(tmpEvent.getDescription());
                m_events[id].setName(tmpEvent.getName());
            }

            else
            {
                QMessageBox::warning(this, tr("Warning"),
                                        tr("can not create event with empty name or description!"));
            }
        }

    }

}

bool Calendar::isEventNameInUse(QString name)
{
    if(m_events.contains(name))
    {
        return true;
    }
    return false;
}
