#include <QApplication>

#include <QPushButton>
#include <QMainWindow>

#include "customWidget.h"

using namespace std;

int main(int argc, char* argv[])
{
  QApplication app(argc,argv);
  QMainWindow mw;

  customWidget widget(&mw);
  widget.setFixedWidth(400);
  widget.setFixedHeight(400);

  mw.setCentralWidget(&widget);
  mw.show();

  return app.exec();
}

