#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order
{
    public:

        virtual ~Order();

        virtual void Run() = 0;

        void changeActiveflag();
        bool getActiveflag();

    protected:

    bool isActive;

    private:
};

#endif // ORDER_H
