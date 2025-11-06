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
class ShoppingCartDatabase{
    private:
        shoppingCart* cart;
    public:
    ShoppingCartDatabase(shoppingCart* cart){
        this->cart = cart;
    }   
    void saveToSQLDB(shoppingCart* cart){
        // save to database
        cout << "Saving to database..." << endl;
    }
    void saveToNoSQLDB(shoppingCart* cart){
        // save to database
        cout << "Saving to NoSQL database..." << endl;
    }
    void saveToXMLDB(shoppingCart* cart){
        // save to database
        cout << "Saving to XML database..." << endl;
    }
};


int main(){
    shoppingCart* cart = new shoppingCart();
    cart->addProduct(new Product("Laptop",999.99));
    cart->addProduct(new Product("Mouse",49.99));
    cart->addProduct(new Product("Keyboard",79.99));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter();
    printer->printInvoice(cart);

    ShoppingCartDatabase* db = new ShoppingCartDatabase(cart);
    db->saveToSQLDB(cart);

    return 0;
}


