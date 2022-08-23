#include <QObject>
#include <QWidget>

class QPushButton;

class customWidget : public QWidget
{
  Q_OBJECT

public:
  customWidget(QWidget* parent);

protected:
    void paintEvent(QPaintEvent *event) override;

    QPushButton* btn;
    int rad = 100;
};
