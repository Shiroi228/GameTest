#include <QTimer>

#include "bullet.hpp"

namespace elements {

BulletElement::BulletElement() {
    setRect(0, 0, 10, 50);

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &BulletElement::move);

    timer->start(50);
}

void BulletElement::move() {
    setPos(x(), y() - 10);
}

}