#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <iostream>

#include "customWidget.h"

#include <QPainter>
#include <QPen>
#include <QPushButton>

using namespace std;

customWidget::customWidget(QWidget* parent) :
  QWidget(parent),
  m_code(""),
  m_generation(1)
{
  btn = new QPushButton("new generation",this);
  connect(btn,&QPushButton::clicked,this,[this](){
    ++m_generation;
    processNewGeneration();
    std::cout << m_code << std::endl;
    this->update();
  });

  m_code = "ABA";
}

void customWidget::processNewGeneration()
{
  std::string newCode;

  for (char c : m_code)
  {
    if (c == 'A')
    {
      newCode.append("ABA");
    }
    else if (c == 'B')
    {
      newCode.append("BBB");
    }
  }

  m_code = newCode;
}

void customWidget::paintEvent(QPaintEvent*)
{
  setMaximumSize(static_cast<QWidget*>(parent())->size());
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
