#ifndef SCORE_H
#define SCORE_H

#include "elements.hpp"

namespace elements {
    
class ScoreElement : public TextElement {
public:
    ScoreElement(QGraphicsItem *parent = nullptr);

    int score();

public slots:
    void increase();
    void updateScore(int score);

private:
    int score_;
};

}

#endif // SCORE_H
