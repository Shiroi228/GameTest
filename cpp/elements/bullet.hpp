#ifndef BULLET_H
#define BULLET_H

#include <QObject>

#include "element.hpp"

namespace elements {
    
class BulletElement : public QObject, public DefaultElement {
    Q_OBJECT
public:
    BulletElement();

public slots:
    void move();
};

}

#endif // BULLET_H
