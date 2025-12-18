#include<iostream>
using namespace std;

// Abstract Product: Burger
class Burger {
    public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Basic Burger" << endl;
    }

};

class StandardBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};

class PremiumBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Premium Burger" << endl;
    }
};

// Abstract Product: GarlicBread

class GarlicBread {
    public:
    virtual void bake() = 0;
    virtual ~GarlicBread() {}

};

class BasicGarlicBread : public GarlicBread {
    public:
    void bake() override {
        cout << "Baking Basic Garlic Bread" << endl;
    }
};

class StandardGarlicBread : public GarlicBread {
    public:
    void bake() override {
        cout << "Baking Standard Garlic Bread" << endl;
    }
};
class PremiumGarlicBread : public GarlicBread {
    public:
    void bake() override {
        cout << "Baking Premium Garlic Bread" << endl;
    }
};

// Abstract Factory
class MealFactory {
    public:
    virtual Burger* createBurger( string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
    virtual ~MealFactory() {}
};



class singhBurger : public MealFactory {
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

    GarlicBread* createGarlicBread(string& type) override {
        if(type == "Basic") {
            return new BasicGarlicBread();
        } else if(type == "Standard") {
            return new StandardGarlicBread();
        } else if(type == "Premium") {
            return new PremiumGarlicBread();
        } else {
            return nullptr;
        }
    }
};

int main() {
    MealFactory* factory = new singhBurger();

    string burgerType = "Standard";
    string breadType = "Premium";

    Burger* burger = factory->createBurger(burgerType);
    GarlicBread* garlicBread = factory->createGarlicBread(breadType);

    if(burger) {
        burger->prepare();
        delete burger;
    } else {
        cout << "Invalid Burger Type" << endl;
    }

    if(garlicBread) {
        garlicBread->bake();
        delete garlicBread;
    } else {
        cout << "Invalid Garlic Bread Type" << endl;
    }

    delete factory;
    return 0;
}