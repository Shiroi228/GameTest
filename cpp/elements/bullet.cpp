#include <QDebug>
#include <QGraphicsScene>
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

    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;

        qDebug("Bullet deleted");
    }
}

}