#ifndef PRESSEDBUTTON_H
#define PRESSEDBUTTON_H
#include <QPushButton>

class PressedButton : public QPushButton
{
public:
    PressedButton(QWidget* parent);


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;

public slots:
    void changeBackgroundColor();
private:
    QString m_text;
    QColor m_background;
};

#endif // PRESSEDBUTTON_H

