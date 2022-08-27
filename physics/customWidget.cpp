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
  QWidget(parent)
{
  m_timer.setInterval(50);

  btn = new QPushButton("start",this);
  connect(btn,&QPushButton::clicked,this,[this](){
    m_timer.start();
  });

  connect(&m_timer, &QTimer::timeout, this, [this](){
    processNextStep();
  });

  setupInitialScene();
}

void customWidget::setupInitialScene()
{
  m_particles.push_back(std::make_shared<Particle>(QPointF(0.,0.),QVector2D(0.1,0.5)));
}


void customWidget::processNextStep()
{
  for (std::shared_ptr<Particle>& particle : m_particles)
  {
    particle->update();
  }
  update();
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

  for (std::shared_ptr<Particle>& particle : m_particles)
  {
    painter.drawEllipse(particle->pos(),2,2);
    particle->update();
  }


}

#endif // CUSTOMWIDGET_H
