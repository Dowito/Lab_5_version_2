#include "control.h"

Control::Control(QObject *parent)
    : QObject{parent}
{

}

void Control::removeBomb()
{
    auto it = bombas.begin();
    bombas.erase(it);
}
