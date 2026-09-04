#ifndef ELEMENT_H
#define ELEMENT_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

namespace elements {
    
class DefaultElement : public QGraphicsRectItem {};

class TextElement : public QGraphicsTextItem {
public:
    TextElement(QGraphicsItem *parent = nullptr) : QGraphicsTextItem(parent) {};
};

}

#endif // ELEMENT_H
