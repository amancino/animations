#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <iostream>

#include "customWidget.h"

#include <QPainter>
#include <QPen>
#include <QPushButton>

using namespace std;

customWidget::customWidget(QWidget* parent) : QWidget(parent)
{
  btn = new QPushButton("new generation",this);
  connect(btn,&QPushButton::clicked,this,[this](){
    rad += 2;
    this->update();
  });
}

void customWidget::paintEvent(QPaintEvent*)
{
  setMaximumSize(static_cast<QWidget*>(parent())->size());
  cout << "size: " << width() << ", " << height() << endl;
  QPainter painter(this);

  // move to the bottom and change coordinates to point upwards
  painter.setPen(Qt::GlobalColor::transparent);
  painter.translate(width()/2,height()*0.9);
  painter.rotate(180);

  painter.setPen(QPen(Qt::GlobalColor::black,2));
  //painter.drawRoundRect(-rad,-10,2*rad,20,10,20);

  painter.drawLine(0, 0, 0, 40);
}

#endif // CUSTOMWIDGET_H
