#ifndef SWITCHSLIDER_H
#define SWITCHSLIDER_H
#include <QCheckBox>

class SwitchSlider : public QCheckBox
{
    Q_OBJECT

public:
    SwitchSlider(QWidget* parent = nullptr);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // SWITCHSLIDER_H
