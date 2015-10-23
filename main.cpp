#include <iostream>
#include "Commandinterface.h"
#include "Order.h"

using namespace std;

class Ausgabe: public Order
{
    public:
    void Run()
    {
        std::cout << "Das erste Kommando" << std::endl;

    }

}; // Ausgabe

class Abgabe: public Order
{
    public:
    void Run()
    {
        std::cout << "Das zweite Kommando ..." << std::endl;

    }

}; // Abgabe

class Rechne: public Order
{
    public:
    Rechne(int Zahl)
    {
        multi = Zahl;

    }

    void Run()
    {
        std::cout << "Die Zahl ist " << multi << "." << std::endl;
        std::cout << multi << " + " << multi << " = " << multi+multi << "." << std::endl;
    }

    private:

    int multi;


}; // Rechne

void Outline()
{
    std::cout << " --------------------- " << std::endl;

}; // OUtline

int main()
{

    Commandinterface Comms = Commandinterface();
    Order* Eins = new Ausgabe();
    Order* Zwei = new Abgabe();
    Order* Vier = new Rechne(5);

    Comms.registerEvent("Eins", Eins);
    Comms.registerEvent("Zwei", Zwei);
    Comms.registerEvent("Vier", Vier);

    Comms.executeEvent("Eins");
    Comms.executeEvent("Zwei");
    Comms.executeEvent("Eins");
    Outline();

    Comms.disableEvent("Eins");
    Comms.executeEvent("Eins");
    Comms.enableEvent("Eins");
    Comms.executeEvent("Eins");
    Outline();

    Comms.deleteEvent("Eins");
    Comms.executeEvent("Eins");
    Comms.executeEvent("Zwei");
    Outline();

    Comms.executeEvent("Eins");
    Comms.executeEvent("Zwei");
    Comms.executeEvent("Drei");
    Outline();

    Comms.executeEvent("Vier");
    Outline();

    delete Eins;
    delete Zwei;
    delete Vier;

    return 0;
}
