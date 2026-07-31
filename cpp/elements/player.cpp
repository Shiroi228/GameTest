#include <QKeyEvent>
#include <QGraphicsScene>

#include "player.hpp"
#include "bullet.hpp"

namespace elements {

void PlayerElement::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Left: {
        setPos(x() - 10, y());
        break;
    }
    case Qt::Key_Right: {
        setPos(x() + 10, y());
        break;
    }
    case Qt::Key_Up: {
        setPos(x(), y() - 10);
        break;
    }
    case Qt::Key_Down: {
        setPos(x(), y() + 10);
        break;
    }
    case Qt::Key_Space: {
        BulletElement *bullet = new BulletElement();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
    default:
        break;
    }
}

}