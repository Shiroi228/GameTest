#include "QFont"

#include "health.hpp"

namespace elements {

HealthElement::HealthElement(QGraphicsItem *parent) : TextElement(parent), health_(5) {
    updateHealth(health_);
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
    setDefaultTextColor(QColor(Qt::black));
}

int HealthElement::health() {
    return health_;
}

void HealthElement::updateHealth(int health) {
    setPlainText(QString(tr("Health: %1")).arg(health));
}

void HealthElement::decrease() {
    updateHealth(--health_);
}


}