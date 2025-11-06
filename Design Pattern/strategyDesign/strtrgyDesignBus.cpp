#include <iostream>
using namespace std;

class TravelStretegy{
public:
    virtual void speed(int speed) = 0;
    virtual void cost(int Price) = 0;
    virtual ~TravelStretegy() {}
};

class BusTravel : public TravelStretegy{
public:
    void speed(int speed) override{
        cout << "Bus speed is " << speed << " km/h." << endl;
    }

    void cost(int Price) override{
        cout << "Bus ticket price is " << Price << " dollars." << endl;
    }
};

class TrainTravel : public TravelStretegy{
public:
    void speed(int speed) override{
        cout << "Train speed is " << speed << " km/h." << endl;
    }
    void cost(int Price) override{
        cout << "Train ticket price is " << Price << " dollars." << endl;
    }   
};

class FlightTravel : public TravelStretegy{
public:
    void speed(int speed) override{
        cout << "Flight speed is " << speed << " km/h." << endl;
    }
    void cost(int Price) override{
        cout << "Flight ticket price is " << Price << " dollars." << endl;
    }   
};


class TravelContext {
private:
    TravelStretegy* strategy;
public:
    TravelContext(TravelStretegy* strategy) : strategy(strategy) {}
    void setStrategy(TravelStretegy* strategy) {
        this->strategy = strategy;
    }
    void travelDetails(int speed, int Price) {
        strategy->speed(speed);
        strategy->cost(Price);
    }
};

int main(){
    TravelStretegy *bus = new BusTravel();
    TravelStretegy *train = new TrainTravel();
    TravelStretegy *flight = new FlightTravel();

    TravelContext context(bus);
    context.travelDetails(60, 20);
    context.setStrategy(train);
    context.travelDetails(120, 50);
    context.setStrategy(flight);
    context.travelDetails(800, 200);

    delete bus;
    delete train;
    delete flight;

    return 0;
}