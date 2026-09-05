#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QTransform>

#include <stdlib.h>

#include "enemy.hpp"
#include "game.hpp"

namespace elements {

EnemyElement::EnemyElement(int sceneWidth) : QObject(), DefaultElement() {
    QTransform transform;
    transform.rotate(180);

    QPixmap pixmap(":/images/player.png");
    pixmap = pixmap.scaled(100, 100);
    pixmap = pixmap.transformed(transform);

    setPixmap(pixmap);
    
    int randomPos = rand() % static_cast<int>(sceneWidth - boundingRect().width());
    setPos(randomPos, 0);

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &EnemyElement::move);

    timer->start(50);
}

void EnemyElement::move() {
    setPos(x(), y() + 5);

    if (pos().y() > scene()->height()) {
        GameView::instance()->healthElement()->decrease();
        scene()->removeItem(this);
        delete this;

        qDebug("EnemyElement::move(): Enemy deleted");
    }
}

}