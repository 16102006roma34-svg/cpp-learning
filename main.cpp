#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Datchik {
    private:
        //int id;
        string roomName;
        float curTemp;
        float maxTemp;
    public:
        void setRoomName(const string& newRoomName) {
            if (newRoomName.empty()) 
                roomName="Пусто";
            cout << "Название комнаты изменено на " << roomName << endl; 
        }

        void setMaxTemp(float newMaxTemp) {
            if (newMaxTemp<0.0) {
                cout << "температура не ниже нуля" << endl;
                maxTemp=0.0;
            }
            else {
                maxTemp=newMaxTemp;
            }
        }

        void setTemperature(float newCurTemp) {
            if(newCurTemp>maxTemp)
                cout << "ПЕРЕГРЕВ" << endl;
            curTemp=newCurTemp;
        }

        void print() const {
            cout << "Комната: " << roomName << "; текущая температура: " << curTemp << "; максимальная температура: " << maxTemp << endl;
            if(curTemp>maxTemp)
                cout << "ПЕРЕГРЕВ\n";
        }
    
        string getRoomName() const {
            return roomName;
        }

        Datchik(string newRoomName, float newCurTemp, float newMaxTemp):roomName(newRoomName), curTemp(newCurTemp), maxTemp(newMaxTemp) {
            setRoomName(newRoomName);
            setMaxTemp(newMaxTemp);
            setTemperature(newCurTemp);
        }
    };

    class Remote_Control {
        private:
            vector<Datchik> Datchik_List;
        
        public:
            Remote_Control() {}

            void addDatchik(const string& newRoomName, float newMaxTemp) {
                Datchik_List.push_back(Datchik(newRoomName, 0.0, newMaxTemp)); 
            }

            void printAll() const {
                for (const Datchik datchik:Datchik_List) 
                    datchik.print();
            }

            void updateTemp(const string& infoRoomName, float newCurTemp) {
                bool found=0;
                for (Datchik& datchik:Datchik_List) {
                    //ну это я могу через костыль сделать про датчик не найден.
                    if(datchik.getRoomName()==infoRoomName) {
                        datchik.setTemperature(newCurTemp);
                        found=1;
                    }
                }
                if (found==0)
                    cout << "Датчик не найден";
            }
    };

    int main()
    {
        Remote_Control rem1;

        rem1.addDatchik("Серверная", 25.5);

        rem1.addDatchik("Основной цех", 30.0);

        rem1.addDatchik("Холодильник", 5.0);

        rem1.updateTemp("Серверная", 22.0);

        rem1.updateTemp("Холодильник", 8.5);

        rem1.printAll();
    }