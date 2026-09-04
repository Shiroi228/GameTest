#include "QFont"

#include "score.hpp"

namespace elements {

ScoreElement::ScoreElement(QGraphicsItem *parent) : TextElement(parent), score_(0) {
    updateScore(score_);
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
}

int ScoreElement::score() {
    return score_;
}

void ScoreElement::updateScore(int score) {
    setPlainText(QString(tr("Score: %1")).arg(score));
}

void ScoreElement::increase() {
    updateScore(++score_);
}


}