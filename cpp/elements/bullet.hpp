#ifndef BULLET_H
#define BULLET_H

#include <QAudioOutput>
#include <QGraphicsItem>
#include <QList>
#include <QMediaPlayer>
#include <QObject>

#include "elements.hpp"

namespace elements {
    
class BulletElement : public QObject, public DefaultElement {
    Q_OBJECT
public:
    BulletElement();

public slots:
    void move();

private:
    QList<QGraphicsItem *> collidingItems_;
    QMediaPlayer *mediaPlayer_;
    QAudioOutput *audioOutput_;
};

}

#endif // BULLET_H
