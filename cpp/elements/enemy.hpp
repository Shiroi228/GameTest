#ifndef ENEMY_H
#define ENEMY_H

#include "element.hpp"

namespace elements {
    
class EnemyElement : public QObject, public DefaultElement {
    Q_OBJECT
public:
    EnemyElement(int sceneWidth); // вместо int можно передавать ссылку на сцену
    
public slots:
    void move();
};

}

#endif // ENEMY_H
