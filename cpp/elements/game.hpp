#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMediaPlayer>
#include <QSharedPointer>

#include "health.hpp"
#include "player.hpp"
#include "score.hpp"

namespace elements {

class GameView : public QGraphicsView {
public:
    GameView(QWidget *parent = nullptr);

    static QSharedPointer<GameView> instance();

    QGraphicsScene *scene() const;
    PlayerElement *player() const;
    ScoreElement *scoreElement() const;
    HealthElement *healthElement() const;

private:
    QGraphicsScene *scene_;
    PlayerElement *player_;
    ScoreElement *scoreElement_;
    HealthElement *healthElement_;

    QMediaPlayer *mediaPlayer_;
};

}

#endif // GAME_H
