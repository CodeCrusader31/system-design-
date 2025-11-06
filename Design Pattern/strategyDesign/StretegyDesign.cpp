// Defining Stretegy Design Pattern in C++

#include <iostream>
using namespace std;
class PaymentStretegy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStretegy() {}
};

// Create Concrete Strategy classes

class UpiPayment : public PaymentStretegy{
public:
    void pay(int amount) override{
        cout << "Paid " << amount << " using UPI Payment." << endl;
    }

};

class CreditCardPayment : public PaymentStretegy{
public:
    void pay(int amount) override{
        cout << "Paid" << amount << " using Credit Card Payment." << endl;
    }
};

class PaypalPayment : public PaymentStretegy{
public:
    void pay(int amount) override{
        cout << "Paid " << amount << " using Paypal Payment." << endl;
    }
};

// Create Context class
class PaymentContext {
private:
    PaymentStretegy* strategy;
public:
    PaymentContext(PaymentStretegy* strategy) : strategy(strategy) {}
    void setStrategy(PaymentStretegy* strategy) {
        this->strategy = strategy;
    }
    void pay(int amount) {
        strategy->pay(amount);
    }
};

// main function to demonstrate the strategy pattern

int main(){
    PaymentStretegy *upi = new UpiPayment();
    PaymentStretegy *card = new CreditCardPayment();
    PaymentStretegy *paypal = new PaypalPayment();

    PaymentContext context(upi);
    context.pay(1000);
    context.setStrategy(card);
    context.pay(2000);
    context.setStrategy(paypal);
    context.pay(3000);

    delete upi;
    delete card;
    delete paypal;

    return 0;
}



