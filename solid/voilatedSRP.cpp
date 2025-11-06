#include<iostream>
#include<vector>
using namespace std;
// prodcut class
class Product{
    public:
    string name;
    double price;


    Product(string name,double price){
        this->name=name;
        this->price = price;

    }
};

// shopping cart class

class ShoppingCart{
    private:
    vector<Product*> products;

    public:

    void addProduct(Product* p){
        products.push_back(p);

    }

    const vector<Product*> getProducts(){
        return products;
    }

    // calculate total price in cart
    double calculateTotalPrice(){
        double total = 0.0;
        for(auto p:products){
            total += p->price;
        }
        return total;
    }

    void printInvoice(){
        cout << "shopping cart invoice:" << endl;
        for(auto p: products){
            cout << p->name << ": $" << p->price << endl;
        }

        cout << "Total: $" << calculateTotalPrice() << endl;
    }

    void saveToDB(){
        // save to database
        cout << "Saving to database..." << endl;
    }

};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 999.99));
    cart->addProduct(new Product("Mouse", 49.99));
    cart->addProduct(new Product("Keyboard", 79.99));
    cart->printInvoice();
    cart->saveToDB();
    return 0;

}

