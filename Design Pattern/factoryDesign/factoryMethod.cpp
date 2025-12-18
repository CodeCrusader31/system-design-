#include <iostream>
using namespace std;

class Burger{
    public:
    virtual void prepare() = 0;
    virtual ~Burger() {}

};

class BasicBurger : public Burger{
    public:
    void prepare() override {
        cout << "Preparing Basic Burger" << endl;
    }
};

class StandardBurger : public Burger{
    public:
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger{
    public:
    void prepare() override {
        cout << "Preparing Premium Burger" << endl; 
    }
};

class BurgerFactory{
    public:
    virtual Burger* createBurger(string& type) = 0;
    virtual ~BurgerFactory() {}
};

class SinghBurgerFactory : public BurgerFactory{
    public:
    Burger* createBurger(string& type) override {
        if(type == "Basic") {
            return new BasicBurger();
        } else if(type == "Standard") {
            return new StandardBurger();
        } else if(type == "Premium") {
            return new PremiumBurger();
        } else {
            return nullptr;
        }
    }
};

class KingBurgerFactory : public BurgerFactory{
    public:
    Burger* createBurger(string& type) override {
        if(type == "Basic") {
            cout << "King Burger Factory: ";
            return new BasicBurger();
        } else if(type == "Standard") {
            cout << "King Burger Factory: ";
            return new StandardBurger();
        } else if(type == "Premium") {
            cout << "King Burger Factory: ";
            return new PremiumBurger();
        } else {
            return nullptr;
        }
    }
};

int main() {
    string factoryType;
    cout << "Enter Burger Factory Type (Singh/King): ";
    cin >> factoryType;

    BurgerFactory* factory = nullptr;

    if(factoryType == "Singh") {
        factory = new SinghBurgerFactory();
    } else if(factoryType == "King") {
        factory = new KingBurgerFactory();
    } else {
        cout << "Invalid Factory Type!" << endl;
        return 1;
    }

    string burgerType;
    cout << "Enter Burger Type (Basic/Standard/Premium): ";
    cin >> burgerType;

    Burger* burger = factory->createBurger(burgerType);
    if(burger) {
        burger->prepare();
        delete burger;
    } else {
        cout << "Invalid Burger Type!" << endl;
    }

    delete factory;
    return 0;
}