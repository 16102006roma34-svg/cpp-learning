#include <vector>
#include <memory>
#include <iostream>
#include <string>

class PaymentProcessor {
protected: 
    std::string currency;
    float amount;

public:
    // Конструктор родителя — принимает общие для всех полей данные
    PaymentProcessor(std::string curr, float amt) : currency(curr), amount(amt) {}

    // Виртуальный деструктор (сделали через = default)
    virtual ~PaymentProcessor() = default; 

    // Чисто виртуальная функция. = 0 означает, что у самого PaymentProcessor 
    // нет реализации, это просто "шаблон", а дети ОБЯЗАНЫ её написать.
    virtual void process() = 0; 
};

class CardPayment : public PaymentProcessor {
private:
    std::string paymentSystem;

public:
    // Конструктор ребенка: сначала вызываем конструктор родителя через список инициализации,
    // а потом инициализируем свое собственное поле paymentSystem
    CardPayment(std::string curr, float amt, std::string sys) 
        : PaymentProcessor(curr, amt), paymentSystem(sys) {}

    void process() override {
        std::cout << "[Карта] Система: " << paymentSystem 
                  << " | Сумма: " << amount << " " << currency << std::endl;
    }
};

class CryptoPayment : public PaymentProcessor {
private: 
    std::string walletAddress;

public:
    // Точно так же: передаем часть данных родителю, часть забираем себе
    CryptoPayment(std::string curr, float amt, std::string wallet) 
        : PaymentProcessor(curr, amt), walletAddress(wallet) {}

    void process() override {
        std::cout << "[Крипта] Адрес: " << walletAddress 
                  << " | Сумма: " << amount << " " << currency << std::endl;
    }
};

class PaymentManager {
private:
    // Твой вектор умных указателей
    std::vector<std::unique_ptr<PaymentProcessor>> database;

public:
    // Метод добавления в базу. Юзаем std::move, потому что unique_ptr нельзя копировать!
    void addPayment(std::unique_ptr<PaymentProcessor> payment) {
        database.push_back(std::move(payment));
    }

    void printInfo(unsigned int id) const {
        // Проверяем, чтобы не выйти за границы вектора (защита от дурака)
        if (id < database.size()) {
            database[id]->process(); // Магия полиморфизма тут!
        }
    }
};

int main() {
    PaymentManager manager;

    // Создаем платежи через std::make_unique и сразу передаем аргументы в конструкторы
    auto card = std::make_unique<CardPayment>("USD", 150.50f, "Visa");
    auto crypto = std::make_unique<CryptoPayment>("BTC", 0.002f, "0x71C...3a9");

    // Кладем их в наш менеджер (базу данных)
    manager.addPayment(std::move(card));
    manager.addPayment(std::move(crypto));

    // Вызываем по ID. Менеджер вызовет правильный метод process() для каждого!
    manager.printInfo(0); // Выведет карту
    manager.printInfo(1); // Выведет крипту

    return 0;
}
