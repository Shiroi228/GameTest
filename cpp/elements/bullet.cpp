#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>

#include "bullet.hpp"
#include "enemy.hpp"

namespace elements {

BulletElement::BulletElement() : QObject(), DefaultElement() {
    setRect(0, 0, 10, 50);

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &BulletElement::move);

    timer->start(50);
}

void BulletElement::move() {
    collidingItems_ = collidingItems();

    for (int i = 0, n = collidingItems_.size(); i < n; ++i) {
        if (typeid(*(collidingItems_[i])) == typeid(EnemyElement)) {
            scene()->removeItem(collidingItems_[i]);
            scene()->removeItem(this);

            delete collidingItems_[i];
            delete this;
            
            return;
        }
    }

    setPos(x(), y() - 10);

    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;

        qDebug("Bullet deleted");
    }
}

}