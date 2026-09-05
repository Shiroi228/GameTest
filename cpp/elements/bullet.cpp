#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>

#include "bullet.hpp"
#include "enemy.hpp"
#include "game.hpp"

namespace elements {

BulletElement::BulletElement() : QObject(), DefaultElement(), mediaPlayer_(new QMediaPlayer(this)), audioOutput_(new QAudioOutput(this)) {
    QPixmap pixmap(":/images/bullet.png");
    pixmap = pixmap.scaled(10, 50);

    setPixmap(pixmap);
    audioOutput_->setVolume(0.8);
    
    mediaPlayer_->setAudioOutput(audioOutput_);
    mediaPlayer_->setSource(QUrl("qrc:/sounds/bullet.mp3"));
    mediaPlayer_->play();

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &BulletElement::move);

    timer->start(50);
}

void BulletElement::move() {
    collidingItems_ = collidingItems();

    for (int i = 0, n = collidingItems_.size(); i < n; ++i) {
        if (typeid(*(collidingItems_[i])) == typeid(EnemyElement)) {
            GameView::instance()->scoreElement()->increase();

            scene()->removeItem(collidingItems_[i]);
            scene()->removeItem(this);

            delete collidingItems_[i];
            delete this;
            
            return;
        }
    }

    setPos(x(), y() - 10);

    if (pos().y() + boundingRect().height() < 0) {
        scene()->removeItem(this);
        delete this;

        qDebug("Bullet deleted");
    }
}

}