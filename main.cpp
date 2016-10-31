#include <QApplication>
#include <QTimer>
#include "qtdialog.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QtDialog w;
  w.show();

  //In demo mode, close after 1 second
  if (argc == 2 && argv[1] == std::string("--demo"))
  {
    QTimer * const timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), &w, SLOT(close()));
    timer->start(1000);
  }
  
  return a.exec();
}
