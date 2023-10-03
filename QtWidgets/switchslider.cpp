#include "switchslider.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPropertyAnimation>

SwitchSlider::SwitchSlider(QWidget* parent) : QCheckBox(parent)
{
//    setWidthForHeight(true);
}

void SwitchSlider::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.save();
    painter.setBrush(Qt::lightGray);
    int width = painter.pen().width();
    painter.drawRoundedRect(rect().adjusted(width, width, -width, - width), rect().height()/2 - width, rect().height()/2 - width);
    painter.restore();

    QColor circleColor = isChecked() ? Qt::green : Qt::red;

    QRadialGradient gradient(calcSideCoords(isChecked()).x(), 0, rect().height());
    gradient.setColorAt(0, circleColor);
    gradient.setColorAt(0.75, circleColor);
    gradient.setColorAt(1, Qt::black);

    QString text = isChecked() ? "YES" : "NO";
    painter.drawText(calcSideCoords(!isChecked()), text);
    gradient.setSpread(QGradient::ReflectSpread);

    QBrush brush(gradient);
    brush.setStyle(Qt::BrushStyle::RadialGradientPattern);

    painter.save();
    painter.setBrush(brush);
    painter.drawEllipse(calcSideCoords(isChecked()), rect().height()/2 - width, rect().height()/2 - width);
    painter.restore();

    update();
}

QPointF SwitchSlider::calcSideCoords(bool isOn) {
    return isOn
        ? QPointF(rect().width() - rect().height()/2, rect().height()/2)
        : QPointF(rect().height()/2, rect().height()/2);
}

void SwitchSlider::mousePressEvent(QMouseEvent *event)
{
    QRect extendedRect = rect();
    if (extendedRect.contains(event->pos())) {
        if(!isChecked())
            setChecked(true);
        else
            setChecked(false);
    }
}

QSize SwitchSlider::minimumSizeHint() const
{
    return QSize(100, 50);
}

QSize SwitchSlider::sizeHint() const
{
    return QSize(rect().width()* 2, rect().height());
}

int SwitchSlider::heightForWidth(int width) const
{
    return width;
}

bool SwitchSlider::hasHeightForWidth() const
{
    return true;
}
