#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "defframework/mainwindow.hpp"
#include "elements/player.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    elements::PlayerElement *player = new elements::PlayerElement();
    player->setRect(0, 0, 100, 100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(player);
    
    QGraphicsView view(scene);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.show();
    view.setFixedSize(800, 600);
    
    scene->setSceneRect(0, 0, 800, 600);

    player->setPos(view.width() / 2 - player->rect().width() / 2, view.height() - player->rect().height());

    return a.exec();
}
