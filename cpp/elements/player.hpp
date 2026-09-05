#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include "elements.hpp"

namespace elements {
    
class PlayerElement : public QObject, public DefaultElement {
    Q_OBJECT
public:
    PlayerElement(QGraphicsItem *parent = nullptr);

    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void spawn();
};

}

#endif // PLAYER_H
