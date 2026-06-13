#include <string> 
#include <map> 
#include <vector>
#include <memory>
class Broker {
    private:
    std::string name;
    unsigned int maxLoad;
    std::vector <std::string> curTaskList;

    public:
    const std::string& getName();

    unsigned int getMaxLoad() const;

    size_t getCurLoad() const;

    void addTask(const std::string& addingTask);

    bool isAvaliable();

    void printInfo() const;

    Broker(std::string newName, unsigned int newMaxLoad);
    Broker();

};

    class BrokerManager {
        private:
        unsigned int nextId=0;
        std::map<unsigned int, std::unique_ptr<Broker>> database;

        public:
        void printAllBrokers() const;

        void registerBroker(const std::string& newName, unsigned int newMaxLoad);

        void addTaskToBroker(unsigned int searchId, const std::string& newTask);
    };