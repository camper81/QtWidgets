#include "pressedbutton.h"
#include <QPainter>
#include <QTimer>
#include <QRandomGenerator>

PressedButton::PressedButton(QWidget* parent) : m_text("MyButton")
{
    setParent(parent);
//    QTimer* timer = new QTimer(this);
//    timer->setInterval(200);
    connect(this, &PressedButton::pressed,
                 this, &PressedButton::changeBackgroundColor);

//    timer->start();
}

void PressedButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    int pen_width = painter.pen().width();
    QBrush brush;
    brush.setColor(m_background);
    painter.save();
    painter.setBrush(brush);
    painter.drawRoundedRect(rect().adjusted(pen_width, pen_width,-pen_width, -pen_width), rect().height()/2 - pen_width, rect().height()/2 - pen_width);
    painter.drawText(rect(), Qt::AlignCenter, m_text);
    painter.restore();



    update();
}

void PressedButton::changeBackgroundColor() {
    QVector<quint32> vector;
    vector.resize(3);
    std::generate(vector.begin(), vector.end(), []() { return QRandomGenerator::global()->generate()%255; });
    m_background.setRgb(vector[0], vector[1], vector[2]);
}

QSize PressedButton::sizeHint() const
{
    return QSize(rect().width(), rect().height());
}
