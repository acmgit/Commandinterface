#include <iostream>
#include <string>

#include "Commandinterface.h"
#include "Order.h"

Commandinterface::Commandinterface()
{
    //ctor
}

Commandinterface::~Commandinterface()
{
    //dtor
}

void Commandinterface::registerEvent(const std::string Name, Order* Event)
{
    if(!Event->getActiveflag())
    {
        Event->changeActiveflag();

    }

    std::pair<std::string, Order*> Ev(Name, Event);
    Command.insert(Ev);

} // registerEvent()

Order* Commandinterface::getEvent(const std::string Name)
{
    std::map<std::string, Order*>::iterator comm = Command.find(Name);
    if(comm != Command.end())
    {
        return comm->second;
    }
    else
    {
        return 0;
    }

} // getEvent()

void Commandinterface::executeEvent(const std::string Name)
{
        Order* Event = getEvent(Name);

        if(Event)
        {
            if(Event->getActiveflag())
            {
                Event->Run();

            } // if Event = active

        } // if Event = valid

} // executeEvent()

void Commandinterface::enableEvent(const std::string Name)
{
    Order* Event = getEvent(Name);

    if(Event)
    {
        if(!Event->getActiveflag())
        {
            Event->changeActiveflag();

        }

    }

} // enableEvent()

void Commandinterface::disableEvent(const std::string Name)
{
    Order* Event = getEvent(Name);

    if(Event)
    {
        if(Event->getActiveflag())
        {
            Event->changeActiveflag();

        }

    }

} // disableEvent()

void Commandinterface::deleteEvent(const std::string Name)
{
    std::map<std::string, Order*>::iterator comm = Command.find(Name);

    if(comm != Command.end())
    {
        Command.erase(comm);
    }

} // deleteEvent

