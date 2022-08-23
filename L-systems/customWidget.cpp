#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <iostream>

#include "customWidget.h"

#include <QPainter>
#include <QPen>
#include <QPushButton>

#include <math.h>

using namespace std;

customWidget::customWidget(QWidget* parent) :
  QWidget(parent),
  m_code(""),
  m_generation(0)
{
  btn = new QPushButton("new generation",this);
  connect(btn,&QPushButton::clicked,this,[this](){
    ++m_generation;
    processNewGeneration();
    std::cout << m_code << std::endl;
    this->update();
  });

  m_code = "F";
}

void customWidget::processNewGeneration()
{
  std::string newCode("");

  for (char c : m_code)
  {
    switch (c)
    {
    case 'F':
      newCode.append("FF+[+F-F-F]-[-F+F+F]");
      //newCode.append("F[+F]F[−F]F");
      break;
    case '+':
      newCode.append("+");
      break;
    case '-':
      newCode.append("-");
      break;
    case '[':
      newCode.append("[");
      break;
    case ']':
      newCode.append("]");
      break;
    }
  }

  m_code = newCode;
}

void customWidget::paintEvent(QPaintEvent*)
{
  setMaximumSize(static_cast<QWidget*>(parent())->size());
  QPainter painter(this);

  // move to the bottom and change coordinates to point upwards
  //painter.setPen(Qt::GlobalColor::transparent);
  painter.translate(width()/2,height()*0.9);
  painter.rotate(180);

  painter.setPen(QPen(Qt::GlobalColor::black,2));
  //painter.drawRoundRect(-rad,-10,2*rad,20,10,20);

  int alpha = 25;
  int L = 10;
  //int L = 40 * std::pow(0.5,(m_generation-1));

  for (char c : m_code)
  {
    switch (c)
    {
    case 'F':
      painter.drawLine(0,0,0,L);
      painter.translate(0, L);
      break;
    case '+':
      painter.rotate(alpha);
      break;
    case '-':
      painter.rotate(-alpha);
      break;
    case '[':
      painter.save();
      break;
    case ']':
      painter.restore();
      break;
    }
  }
}

#endif // CUSTOMWIDGET_H
