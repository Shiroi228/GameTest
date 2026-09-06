#include <QAudioOutput>
#include <QTimer>
#include <QImage>

#include "game.hpp"

namespace elements {

static QSharedPointer<GameView> game_ = {};

QSharedPointer<GameView> GameView::instance() {
    if (game_) { return game_; }

    game_ = QSharedPointer<GameView>(new GameView);
    return game_;
}

GameView::GameView(QWidget *parent) : QGraphicsView(parent), scene_(new QGraphicsScene(this)), player_(new PlayerElement()), scoreElement_(new ScoreElement()),
    healthElement_(new HealthElement()), mediaPlayer_(new QMediaPlayer(this)) {

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);
    setScene(scene_);
    setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));
    
    scene_->addItem(scoreElement_);
    scene_->addItem(healthElement_);
    scene_->addItem(player_);
    scene_->setSceneRect(0, 0, 800, 600);

    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();
    player_->setPos(width() / 2 - player_->boundingRect().width() / 2, height() - player_->boundingRect().height());

    healthElement_->setPos(healthElement_->x(), healthElement_->y() + scoreElement_->boundingRect().height());

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, player_, &PlayerElement::spawn);
    timer->start(2000);

    QAudioOutput *audioOutput = new QAudioOutput();

    mediaPlayer_->setAudioOutput(audioOutput);
    mediaPlayer_->setSource(QUrl("qrc:/sounds/background.mp3"));
    mediaPlayer_->play();

    connect(mediaPlayer_, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status){
        if (status == QMediaPlayer::EndOfMedia) {
            mediaPlayer_->setPosition(0);
            mediaPlayer_->play();
        }
    });
}

QGraphicsScene *GameView::scene() const {
    return scene_;
}

PlayerElement *GameView::player() const {
    return player_;
}

ScoreElement *GameView::scoreElement() const {
    return scoreElement_;
}

HealthElement *GameView::healthElement() const {
    return healthElement_;
}
}