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
    QPointF calcSideCoords(bool isOn);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;

    // QWidget interface
public:
    QSize minimumSizeHint() const override;

    // QWidget interface
public:
    QSize sizeHint() const;

    // QWidget interface
public:
    int heightForWidth(int) const;

    // QWidget interface
public:
    bool hasHeightForWidth() const;
};

#endif // SWITCHSLIDER_H
