#include <QGraphicsScene>
#include <QKeyEvent>

#include "bullet.hpp"
#include "enemy.hpp"
#include "player.hpp"

namespace elements {

void PlayerElement::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Left: {
        if (pos().x() >= 0) { setPos(x() - 10, y()); }

        break;
    }
    case Qt::Key_Right: {
        if (pos().x() + rect().width() < scene()->width()) { setPos(x() + 10, y()); }
        break;
    }
    // case Qt::Key_Up: {
    //     setPos(x(), y() - 10);
    //     break;
    // }
    // case Qt::Key_Down: {
    //     setPos(x(), y() + 10);
    //     break;
    // }
    case Qt::Key_Space: {
        BulletElement *bullet = new BulletElement();
        bullet->setPos(x() + rect().width() / 2 - (bullet->rect().width() / 2), y());
        scene()->addItem(bullet);
    }
    default:
        break;
    }
}

void PlayerElement::spawn() {
    EnemyElement *enemy = new EnemyElement(scene()->width());
    scene()->addItem(enemy);
}

}