#include "Broker.h"
#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{   
    try {
    Broker broker1("рамазан", 4);

    cout << broker1.getMaxLoad() << endl;
    cout << broker1.isAvaliable();
    broker1.addTask("Почесать пузо");
    cout << broker1.getCurLoad();
    broker1.printInfo();

    BrokerManager broker_manager;
    broker_manager.registerBroker("иван", 5);
    broker_manager.registerBroker("банан", 67);
    broker_manager.addTaskToBroker(1, "выпить пива");
    broker_manager.addTaskToBroker(2, "в хлам нажраться");
    broker_manager.printAllBrokers();
}
    catch (runtime_error& error) {
        cerr << "Перехвачено исключение. Причина:\n";
        cerr << error.what();
    }
}
