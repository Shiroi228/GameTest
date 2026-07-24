#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "defframework/mainwindow.hpp"
#include "elements/player.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    elements::PlayerElement *rect = new elements::PlayerElement();
    rect->setRect(0, 0, 100, 100);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addItem(rect);

    QGraphicsView view(scene);
    view.show();

    return a.exec();
}
