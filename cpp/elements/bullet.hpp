#ifndef BULLET_H
#define BULLET_H

#include <QList>
#include <QObject>
#include <QGraphicsItem>

#include "elements.hpp"

namespace elements {
    
class BulletElement : public QObject, public DefaultElement {
    Q_OBJECT
public:
    BulletElement();

public slots:
    void move();

private:
    QList<QGraphicsItem *> collidingItems_;
};

}

#endif // BULLET_H
