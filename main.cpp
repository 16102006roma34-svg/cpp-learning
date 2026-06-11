#include <iostream>
#include <vector> 
#include <map>
#include <memory>
#include <stdexcept>

class AuthManager {
    private: 
    std::map <std::string, std::string> users;

    public:
    AuthManager() {
        users["admin"]="1234";
        users["alex"]="qwerty";
    }

    void login(const std::string& username, const std::string& password) {
        auto it=users.find(username);
        if (it==users.end())
            throw std::runtime_error("Ошибка: пользователь " + username + "не найден");
        else if (it->second!=password) {
            throw std::runtime_error("Ошибка: пароль введён неверно");
        }
    }   
};

int main() {
    AuthManager authmanager;


    std::string login;
    getline(std::cin, login);
    std::string password;
    getline(std::cin, password);

    try {
    authmanager.login(login, password);
    }
    catch (std::runtime_error& error) {
        std::cout << "Перехвачено исключение. Причина:\n";
        std::cout << error.what(); 
    }
}