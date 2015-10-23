#include "Order.h"
Order::~Order()
{

}

void Order::changeActiveflag()
{
    if(isActive)
    {
        isActive = false;

    }
    else
    {
        isActive = true;

    }

} // changeActiveflag()

bool Order::getActiveflag()
{
    return isActive;

} // getActiveflag()
