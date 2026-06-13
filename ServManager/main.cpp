#include <iostream>
#include "ServManager.h" // Подключаем твою «витрину»

int main() {
    ClusterManager manager;
    manager.AddServer("Main-DB", "192.168.1.10");
    manager.addLogToServer(1, "Тестовый лог: всё работает!");
    manager.printReport();
    return 0;
}
