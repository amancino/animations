#include <QObject>
#include <QWidget>
#include <QVector2D>
#include <QPointF>
#include <QTimer>

#include <memory>


class QPushButton;

class Particle
{
public:
  Particle(const QPointF& pos, const QVector2D& speed) :
    m_position(pos),
    m_speed(speed)
  {}

  void update(){
    m_position += m_speed.toPointF();
  }

  inline const QPointF pos(){return m_position;}

private:
  QPointF m_position;
  QVector2D m_speed;
};

class customWidget : public QWidget
{
  Q_OBJECT

public:
  customWidget(QWidget* parent);

  void setupInitialScene();
  void processNextStep();

protected:
    void paintEvent(QPaintEvent *event) override;

  QPushButton* btn;
  std::vector<std::shared_ptr<Particle>> m_particles;
  QTimer m_timer;
};
