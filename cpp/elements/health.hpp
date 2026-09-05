#ifndef HEALTH_H
#define HEALTH_H

#include "elements.hpp"

namespace elements {
    
class HealthElement : public TextElement {
public:
    HealthElement(QGraphicsItem *parent = nullptr);

    int health();

public slots:
    void decrease();
    void updateHealth(int health);

private:
    int health_;
};

}

#endif // HEALTH_H
