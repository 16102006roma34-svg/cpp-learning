#include "Broker.h"
#include <string> 
#include <map> 
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

const std::string& Broker::getName() {
    return name;
}

unsigned int Broker::getMaxLoad() const {
    return maxLoad;
}

size_t Broker::getCurLoad() const {
    return curTaskList.size();
}

void Broker::addTask(const std::string& addingTask) {
    if (curTaskList.size()<maxLoad)
        curTaskList.push_back(addingTask);
    else 
       throw runtime_error("Ошибка: брокер занят\n");
}

bool Broker::isAvaliable() {
    if (curTaskList.size()<maxLoad)
        return true;
    else
        return false;
}

void Broker::printInfo() const {
    cout << "Имя: " << name << endl;
    cout << "Макс. число задач: " << maxLoad << endl;
    cout << "Текущий список задач поочерёдно: " << endl;
    unsigned int numTask=1; //не придумал лучшего способа как пронумеровать задачи, так что костылёк
    for (const string& task : curTaskList) {
        cout << "[" << numTask++ << "] ";
        cout << task << endl;
    }
}

    Broker::Broker(std::string newName, unsigned int newMaxLoad):name(newName), maxLoad(newMaxLoad){}
    Broker::Broker():name(""), maxLoad(0) {}

void BrokerManager::printAllBrokers() const {
    cout << "Все брокеры: " << endl;
    for (const auto& [tempId, broker]:database) {
        cout << "[" << tempId << "] ";
        (*broker).printInfo(); 
    }
}

void BrokerManager::registerBroker(const string& newName, unsigned int newMaxLoad) {
    database[nextId++]=make_unique<Broker>(newName, newMaxLoad);
}

void BrokerManager::addTaskToBroker(unsigned int searchId, const string& addingTask) {
    auto it=database.find(searchId);
    if (it==database.end())
        throw runtime_error("Ошибка: брокер не найден\n");
    else if ((*it->second).getCurLoad()>=(*it->second).getMaxLoad())
        throw runtime_error("Ошибка: брокер занят");
    else 
        (*it->second).addTask(addingTask);
}