#ifndef PLAYER_H
#define PLAYER_H

#include "element.hpp"

namespace elements {
    
class PlayerElement : public DefaultElement {
public:
    void keyPressEvent(QKeyEvent *event) override;
};

}

#endif // PLAYER_H
