#include <iostream>
#include <string>
using namespace std;

class City
{
public:
    string name;
    double distance;

    City(string name, double distance) : name(name), distance(distance) {}
};

class Transport
{
public:
    City from;
    City to;

    Transport(City from, City to) : from(from), to(to) {}

    virtual double calculateTime() = 0;
    virtual double calculateCost() = 0;
};

class Car : public Transport
{
public:
    Car(City from, City to) : Transport(from, to) {}

    double calculateTime() override
    {
        return to.distance / 60;
    }

    double calculateCost() override
    {
        return to.distance * 1.5;
    }
};

class Bus : public Transport
{
public:
    Bus(City from, City to) : Transport(from, to) {}
    double calculateTime() override
    {
        return to.distance / 44; //км/год
    }

    double calculateCost() override
    {
        return to.distance * 1;
    }
};

class Train : public Transport
{
public:
    Train(City from, City to) : Transport(from, to) {}
    double calculateTime() override
    {
        return to.distance /130; //км/год
    }

    double calculateCost() override
    {
        return to.distance * 2;
    }
};

class Tram : public Transport
{
public:
    Tram(City from, City to) : Transport(from, to) {}
    double calculateTime() override
    {
        return to.distance / 27; //км/год
    }

    double calculateCost() override
    {
        return to.distance * 1.5;
    }
};

class Airplane : public Transport
{
public:
    Airplane(City from, City to) : Transport(from, to) {}
    double calculateTime() override
    {
        return to.distance / 290; //км/год
    }

    double calculateCost() override
    {
        return to.distance * 38;
    }
};

class Bicycle : public Transport
{
public:
    Bicycle(City from, City to) : Transport(from, to) {}
    double calculateTime() override
    {
        return to.distance / 11; //км/год
    }

    double calculateCost() override
    {
        return 0; // гроші не потрібні, якщо велосипед свій (а в нас він свій ;))
    }
};

int main()
{
    City odesa("Odesa", 474.3);
    City kharkiv("Kharkiv", 474.3);

    Car car(odesa, kharkiv);
    Bus bus(odesa, kharkiv);
    Train train(odesa, kharkiv);
    Tram tram(odesa, kharkiv);
    Airplane airplane(odesa, kharkiv);
    Bicycle bicycle(odesa, kharkiv);

    cout << "Car time: " << car.calculateTime() << " hours\n";
    cout << "Car cost: " << car.calculateCost() << " UAH";
    cout << "\n";

    cout << "\nBus time: " << bus.calculateTime() << " hours\n";
    cout << "Bus cost: " << bus.calculateCost() << " UAH";
    cout << "\n";

    cout << "\nTrain time: " << train.calculateTime() << " hours\n";
    cout << "Train cost: " << train.calculateCost() << " UAH";
    cout << "\n";

    cout << "\nTram time: " << tram.calculateTime() << " hours\n";
    cout << "Tram cost: " << tram.calculateCost() << " UAH";
    cout << "\n";

    cout << "\nAirplane time: " << airplane.calculateTime() << " hours\n";
    cout << "Airplane cost: " << airplane.calculateCost() << " UAH";
    cout << "\n";

    cout << "\nBicycle time: " << bicycle.calculateTime() << " hours\n";
    cout << "Bicycle cost: " << bicycle.calculateCost() << " UAH";
    cout << "\n";

    return 0;
}