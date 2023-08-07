#include "switchslider.h"
#include <QPainter>

SwitchSlider::SwitchSlider(QWidget* parent) : QCheckBox(parent)
{

}

void SwitchSlider::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPoint begin{0,0}, end{10,10};
    if(isChecked())
        painter.drawRoundRect(rect());

    if(isTristate()) {
        painter.drawLine(begin, end);
        begin.setX(begin.x() + 20);
        painter.drawLine(begin, end);
    }
    update();
}
