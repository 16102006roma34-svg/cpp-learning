#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Account {
    private: 
    unsigned int id;
    string owner;
    float balance; //я подумал лучше баланс сделать флоут 

    public:
    void setOwner(const string& newOwner) {
        if (newOwner.empty()) {
            owner="Пусто";
        }
        else {
            owner=newOwner;
        }
        cout << "Новое имя владельца счёта: " << owner << endl;
    }

    void setBalance(float newBalance) {
        if (newBalance<0) {
            balance=0;
            cout << "Вы ввели отрицательное число." << endl;
        }
        else {
            balance=newBalance;
        }
        cout << "Текущий баланс: " << balance << endl;
    }

    unsigned int getId() const {
        return id;
    }

    string getOwner() const {
        return owner;
    }

    float getBalance() const {
        return balance;
    }

    void deposit(int amount) {
        if (amount<=0) {
            cout << "Баланс не может быть увеличен на отрицательное значение" << endl;
            return;
        }
        else {
            balance+=amount;
        }
    }
 
    bool withdraw(int amount) {
        if (balance<amount) {
            cout << "На счёте недостаточно средств";
            return false;
        }
        else {
            cout << "Транзакция выполнена. Со счёта списано " << amount << "рублей." << endl << "На балансе осталось " << balance << "рублей"; 
        }
    }

    void print() const {
        cout << "ФИО: " << getOwner() << ". Баланс: " << getBalance() << " руб." << endl;
    }

    Account(unsigned int newId, const string& newOwner, float newBalance): id(newId), owner(newOwner), balance(newBalance) {
      id=newId;
      setBalance(newBalance);
      setOwner(newOwner);  
    }
};

class BankProceccor {
private:
    vector<Account> Accounts_bd;
    unsigned int nextId=1;

public:

    void registerAccount(const string& newOwner, float newBalance) {
        Accounts_bd.push_back(Account(nextId++, newOwner, newBalance));
        cout << "В базу данных добавлена новая учетная запись.\n ФИО:" << newOwner << ". Баланс: " << newBalance << endl; 
    }

    void showAllAccounts() const {
        if (Accounts_bd.empty()) {
            cout << "База данных пуста." << endl;
        }
        else {
        for (const Account& account : Accounts_bd) {
            account.print();
        }
        }
    }

    void processTransaction(int processId, int amount, bool isDeposit) {
     for (Account& account : Accounts_bd) {
        if (account.getId()==processId) {
            if(isDeposit) {//ну вот тут пиздец короче. понимаешь наверн о чём я 
                account.deposit(amount);
                return;
            }
            else {
                account.withdraw(amount);
                return;
            }            
        }
     }   
     cout << "Клиент с ID " << processId << " не найден" << endl; 
    }
};