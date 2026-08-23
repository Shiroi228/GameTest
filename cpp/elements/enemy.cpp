#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

#include <stdlib.h>

#include "enemy.hpp"

namespace elements {

EnemyElement::EnemyElement(int sceneWidth) : QObject(), DefaultElement() { 
    setRect(0, 0, 100, 100);
    
    int randomPos = rand() % static_cast<int>(sceneWidth - rect().width());
    setPos(randomPos, 0);

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &EnemyElement::move);

    timer->start(50);
}

void EnemyElement::move() {
    setPos(x(), y() + 5);

    if (pos().y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;

        qDebug("EnemyElement::move(): Enemy deleted");
    }
}

}