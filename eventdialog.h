#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H

#include <QtWidgets>
#include "event.h"

class EventDialog : public QDialog
{
    Q_OBJECT
public:
    EventDialog();
    Event getUserEvent();
protected slots:
    void accept();
private:
    QDateEdit* m_eventDateEdit;
    QDialogButtonBox* m_buttons;
    QLineEdit* m_nameEdit;
    QLineEdit* m_descriptionEdit;
    Event m_tmpEvent;
};

#endif // EVENTDIALOG_H
