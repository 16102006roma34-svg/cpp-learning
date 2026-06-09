#include <iostream> 
#include <vector>
#include <map> 
#include <string> 
using namespace std;

class Courier {
    string name;
    bool isBusy;
    vector <int> curOrders;

    public: 
    Courier (string newName) : name(newName), isBusy(false) { // пустой вектор ж мжно так задать? 

    }

    Courier () : name(""), isBusy(false), curOrders() {}

    const string& getName () const {
        return name;
    } 

    bool getStatus () const{
        return isBusy;
    }

    void takeOrder(int orderId) {
        curOrders.push_back(orderId);
        isBusy=true;
    }

    void print() const {
        cout << "Данные о курьере: \n";
        cout << "ФИО: " << name << "; Статус: ";
        if (isBusy) {
            cout << "занят; Список активных заказов: ";
            for (int tempOrd:curOrders) {
                cout << tempOrd << " ";
            } 
        }
        else {
            cout << "свободен";
        }
        cout << "." << endl;
    }
};

class LogisticSystem {
    map <int, Courier> database;
    int nextCourierId=1;
    int nextOrderId=501;

    public:
    LogisticSystem() {};

    void printReport() const {
        for (const auto& [courierId, courier]:database) {
            cout << "[" << courierId << "] ";
            courier.print();
        }
    }

    void registerCourier(const string& newName) {
        Courier courier(newName);
        database[nextCourierId++]=courier;
    }

    bool assignOrderToCourier(int courierId) {
        auto it=database.find(courierId);

        if(it==database.end()) {
                return false;
            }
        else {
            it->second.takeOrder(nextOrderId);
            return true;
            }
        }
}; 