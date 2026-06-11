#include <vector> 
#include <map> 
#include <iostream>
#include <string>
using namespace std;

class Server {
    string name;
    string ip;
    vector <string> logs;

    public:
    const string& getName() {
        return name;
    }

    const string& getIp() {
        return ip;
    }

    void addLog(const string& log) {
        logs.push_back(log);
    }

    void printServer() const {
        cout << "Название сервера: " << name << endl;
        cout << "IP-адрес: " << ip << endl;
        cout << "Список логов: " << endl;
        for (const string& tempLog : logs) {
            cout << tempLog << endl;
        }
    }

    Server(string newName, string newIp):name(newName), ip(newIp) {

    }

    Server() : name(""), ip("") {}
};

class ClusterManager {
    unsigned int nextId=1;
    map <unsigned int, Server> database;

    public:
    bool AddServer (const string& newName, const string& newIp) {
        database[nextId++]=Server(newName, newIp);
        return true;
    }

    bool addLogToServer(unsigned int serverId, const string& newLog) {
        auto it=database.find(serverId);
        if (it==database.end()) 
            return false;
        else {
            it->second.addLog(newLog);
            return true;
        } 
    }

    void printReport() const {
        for (const auto& [curId, server]:database) {
            cout << "Все сервера:\n";
            cout << "[" << curId << "] ";
            server.printServer(); 
        }
    }
};

int main() {
    ClusterManager manager;
    Server server4("server4", "8.8.8.8");
    Server server5("server5", "8.8.4.4");
    Server server6("server6", "192.168.31.8");
    string log1="абуагагагагагга";
    
    server4.addLog(log1);
    server4.printServer();

    manager.AddServer("server4", "4.4.4.4");
    cout << manager.addLogToServer(1, log1) << endl; //ничего, что айди я просто выдумал? подразумевается же что раз надо добавить лог то программист айди сервера куда добавляем уже знает
    cout << manager.addLogToServer(2, log1) << endl;
}