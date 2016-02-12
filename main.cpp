#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationDomain("iwaszkiewcz.pl");
    app.setApplicationName("Calendar");
    app.setApplicationVersion("1.0");
    MainWindow window;
    window.show();

    return app.exec();
}
