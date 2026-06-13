#include "ServManager.h"
#include <vector> 
#include <map> 
#include <iostream>
#include <string>
#include <memory>
using namespace std;


    const string& Server::getName() {
        return name;
    }

    const string& Server::getIp() {
        return ip;
    }

    void Server::addLog(const string& log) {
        logs.push_back(log);
    }

    void Server::printServer() const {
        cout << "Название сервера: " << name << endl;
        cout << "IP-адрес: " << ip << endl;
        cout << "Список логов: " << endl;
        for (const string& tempLog : logs) {
            cout << tempLog << endl;
        }
    }

    Server::Server(string newName, string newIp):name(newName), ip(newIp) {}
    

    Server::Server() : name(""), ip("") {}


    bool ClusterManager::AddServer (const string& newName, const string& newIp) {
        database[nextId++]=make_unique<Server>(newName, newIp);
        return true;
    }
    

    bool ClusterManager::addLogToServer(unsigned int serverId, const string& newLog) {
        auto it=database.find(serverId);
        if (it==database.end()) 
            return false;
        else {
            it->second->addLog(newLog);
            return true;
        } 
    }

    void ClusterManager::printReport() const {
        for (const auto& [curId, server]:database) {
            cout << "Все сервера:\n";
            cout << "[" << curId << "] ";
            server->printServer(); 
        }
    }


