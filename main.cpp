#include <iostream>
#include <QApplication>
#include <ui_GUI.h>

#include "gui.h"
#include "Repository.h"
#include "Service.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repository repo;
    Service service{repo};
    gui gui{nullptr,service};
    gui.show();
    return a.exec();
}