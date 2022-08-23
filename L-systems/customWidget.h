#include <QObject>
#include <QWidget>

class QPushButton;

class customWidget : public QWidget
{
  Q_OBJECT

public:
  customWidget(QWidget* parent);

  void processNewGeneration();

protected:
    void paintEvent(QPaintEvent *event) override;

    QPushButton* btn;
    std::string m_code;
    int m_generation;
};
