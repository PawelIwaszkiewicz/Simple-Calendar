#include "eventdialog.h"

EventDialog::EventDialog()
{
    m_eventDateEdit = new QDateEdit();
    m_nameEdit = new QLineEdit();
    m_descriptionEdit = new QLineEdit();
    m_buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    m_eventDateEdit->setDisplayFormat("dd/MM/yyyy");
    m_eventDateEdit->setDate(QDate::currentDate());
    m_nameEdit->setText(tr("name"));
    m_descriptionEdit->setText(tr("description"));

    QHBoxLayout* dateEditLayout = new QHBoxLayout();
    dateEditLayout->addWidget(new QLabel(tr("date: ")));
    dateEditLayout->addWidget(m_eventDateEdit);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(dateEditLayout);
    mainLayout->addWidget(m_nameEdit);
    mainLayout->addWidget(m_descriptionEdit);
    mainLayout->addWidget(m_buttons);

    this->setLayout(mainLayout);

    connect(m_buttons, SIGNAL(accepted()), this, SLOT(accept()));
    connect(m_buttons, SIGNAL(rejected()), this, SLOT(reject()));
}

Event EventDialog::getUserEvent()
{
    return m_tmpEvent;
}

void EventDialog::accept()
{
    m_tmpEvent.setDate(m_eventDateEdit->date().day(),
                       m_eventDateEdit->date().month(),
                       m_eventDateEdit->date().year());
    m_tmpEvent.setName(m_nameEdit->text());
    m_tmpEvent.setDescription(m_descriptionEdit->text());
    QDialog::accept();
}
