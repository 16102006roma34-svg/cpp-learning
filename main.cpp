#include <map>
#include <iostream>
#include <string>

using namespace std;


class Translator {
private: 
    map <string, string> slovar;
public:
    void addTranslate(const string& keyword, const string& translate) {
        auto it=slovar.find(keyword);

        if (it!=slovar.end()) {
            cout << "перевод слова " << keyword << " уже записан как " << it->second << endl;
            cout << "Хотите заменить перевод? 1 - да, 0 - нет";
            bool hochu;
            cin >> hochu;
            cin.ignore();
            if (!hochu)
                return;
        }
        slovar[keyword]=translate;
    }

    void printTranslate(const string& keyword) const {
        auto it=slovar.find(keyword);

        if(it!=slovar.end()) {
            cout << "Перевод слова " << keyword << ": " << it->second << endl;
        }
        else {
            cout << "Слово " << keyword << " не найдено в словаре" << endl;
        }
    }

    void printAll() const {
        cout << "Полный словарь: " << endl ;
        if (slovar.empty()) {
            cout << "Словарь пуст!" << endl;
            return;
        }
        for (const auto& [key, value] : slovar) {
            cout <<  key << "->" << value << endl;
        }
    }
};


int main() {
    Translator slovar;

    slovar.addTranslate("apple", "яблоко");
    slovar.addTranslate("banana","банан");
    slovar.addTranslate("potato","картопля");

    string keyword;

    getline(cin, keyword);

    slovar.printTranslate(keyword);

    slovar.printAll();
}