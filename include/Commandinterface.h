#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H

#include <map>
#include <Order.h>

class Commandinterface
{
    public:
        Commandinterface();
        ~Commandinterface();

        void registerEvent(const std::string Name, Order* Event);
        void executeEvent(const std::string Name);
        void enableEvent(const std::string Name);
        void disableEvent(const std::string Name);
        void deleteEvent(const std::string Name);

    protected:

        Order* getEvent(const std::string Name);

    std::map<std::string, Order*> Command;

    private:

};

#endif // COMMANDINTERFACE_H
