#ifndef BUTTON_H
#define BUTTON_H

#include <gameitem.h>
#include <QGraphicsScene>
#include <iostream>

class button : public GameItem
{
public:
    button(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};
#endif // BUTTON_H
