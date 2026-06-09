#include <iostream> 
#include <map>
#include <string>
using namespace std;
class Product {
    string name;
    unsigned int quantity; 

    public:
    Product(const string& newName, unsigned int newQuantity) : name(newName), quantity(newQuantity) {
    }

    Product():name(""), quantity(0){}
    
    void changeQuantity(int amount) {
        quantity+=amount;
    }

    const string& getName () const {
        return name; 
    }

    unsigned int getQuantity() const {
        return quantity;
    }

    void print() const {
        cout << "Название товара: " << name << ". Количество на складе: " << quantity << endl;
    }
};

class Warehouse {
    map <unsigned int, Product> database;
    int nextCode=101;
    
    public:
    void addProduct(const string& newName, unsigned int newQuantity) {
        database[nextCode++]=Product(newName, newQuantity);
    }

    bool updateStock(int barcode, unsigned int count) {
        auto it=database.find(barcode);

        if(it==database.end()) {
            return false;
        }
        else {
            it->second.changeQuantity(count);
            return true;
        }
    }

    void printAll() const {
        for (const auto & [barcode, product]:database) {
            cout << "[" << barcode << "] ";
            product.print();
        }
    }
};

