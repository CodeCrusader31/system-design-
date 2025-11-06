#include<iostream>
#include<vector>
using namespace std;

class Product{
    public:
    string name;
    double price;

    Product(string name,double price){
        this->name=name;
        this->price = price;

    }

};

// 1. Shopping cart class
class shoppingCart{
    private:
    vector<Product*>products;
    public:
    void addProduct(Product* p){
        products.push_back(p);

    }

    // geter for products
    const vector<Product*> getProducts(){
        return products;
    }

    // calculate total price in cart
    double calculateTotalPrice(){
        double total = 0.0;
        for (auto p:products){
            total += p->price;
        }

        return total;
    }


};

// 2. shopping cart Printing class
class ShoppingCartPrinter{
    private: 
        shoppingCart* cart;
    public:
    void printInvoice(shoppingCart* cart){
        cout << "Shopppint cart invoice:" << endl;
        for(auto p: cart->getProducts()){
            cout << p->name << ": $" << p->price << endl;
        } 
    }
};

// 3. shopping cart Database class
// Abstract class for database operations

class Persistence{
private:
    shoppingCart* cart;
public:
    virtual void save(shoppingCart* cart) = 0; // pure virtual function

};

class SQLpersistance : public Persistence{
public:
    void save(shoppingCart* cart) override{
        cout << "saving shopping cart to SQl DB ..." << endl;
    }    
};

class Mongopersistance : public Persistence{
public:
    void save(shoppingCart *cart) override{
        cout << " Saving shopping cart to MongoDB ..." << endl;
    }
};

class Filepersistance : public Persistence{
    public:
    void save(shoppingCart* cart) override{
        cout << " Saving to File ...."<< endl;
    }
};

int main(){
    shoppingCart* cart = new shoppingCart();
    cart->addProduct(new Product("Laptop",999.99));
    cart->addProduct(new Product("Mouse",49.99));
    cart->addProduct(new Product("Keyboard",79.99));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter();
    printer->printInvoice(cart);

   // ShoppingCartDatabase* db = new ShoppingCartDatabase(cart);
   Persistence* db = new SQLpersistance();
   Persistence* mongo = new Mongopersistance();
   Persistence* file = new Filepersistance();

    db->save(cart);
    db->save(cart);
    file->save(cart);

    return 0;
}


