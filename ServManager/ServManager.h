#include <vector> 
#include <map> 
#include <string>
#include <memory>
using namespace std;

class Server {
    private:
    string name;
    string ip;
    vector <string> logs;

    public:
    const string& getName();

    const string& getIp();

    void addLog(const string& log);

    void printServer() const;

    Server(string newName, string newIp);

    Server();
};

class ClusterManager {
    private:
    unsigned int nextId=1;
    map <unsigned int, unique_ptr<Server>> database;

    public:
    bool AddServer (const string& newName, const string& newIp);
    

    bool addLogToServer(unsigned int serverId, const string& newLog);

    void printReport() const;
};

