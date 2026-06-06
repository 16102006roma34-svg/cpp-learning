#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
    private:
    int Id;
    string Name;
    int Age;
    double AverageGrade;

    public:
    Student(int newId, string newName, int newAge, double newAverageGrade):Id(newId), Name(newName), Age(newAge), AverageGrade(newAverageGrade) {
        if (Id<0)
        {
            cout << "Некорректный айди. присвоен id=0";
            Id=0;
        }

        if(Name.empty()) {
            cout << "имя не введено";
            Name="имя не введено";
        }

        if (Age<0) {
            cout << "\nВозраст введён некорректно.";
            Age=0; // я не стал делать ограничение по 16, мало ли какой то вункирдырдыр поступит которому 10. 
        }

        if ((AverageGrade<2.0 or AverageGrade>5.0) and AverageGrade!=0.0) {
            cout << "\nНекорректный средний балл.";
            AverageGrade=0.0;
        }
    }
    
    void setId(int newId) {
        if (newId<0)
        {
            cout << "Некорректный айди. присвоен id=0";
            Id=0;
        }
        else {
        Id=newId;
        }
        }
    void setName(const string& newName) {
         if(newName.empty()) {
            cout << "имя не введено";
            Name="имя не введено";
        }
        else {
        Name=newName;
        }
    }

    void setAge(int newAge) {
        if (newAge<0)
        {
            cout << "Некорректный возраст";
            Age=0;
        }
        else {
            Age=newAge;
        }
    }
    
        void setGrade(double newAverageGrade) {
         if((newAverageGrade<2.0 or newAverageGrade>5.0) and newAverageGrade!=0.0) {
            cout << "некорренктно введён средний балл";
            AverageGrade=0.0;
        }
        else {
            AverageGrade=newAverageGrade;
        }
    }

    void print() const {
        cout << "ID: " << Id << " Name: " << Name << " Age: " << Age << " AverageGrade " << AverageGrade << endl;
    }

    string getName() const {
        return Name;
    }
};

class University {
private:
    vector<Student> students_list;
public:
    University() {}
    
    void addstudent(int id, const string& name, int age) {
        students_list.push_back(Student(id, name, age, 0.0));
    }

    void printAllStudents() const {
        for (const Student& student:students_list)
        {
            student.print();
        }
    }

    void updateGradeFor(const string& needName, double newGrade) {
        for (Student& student:students_list)
        {
            if (student.getName()==needName) {
            student.setGrade(newGrade);
        }
    }
    }
};

int main() {
    // 1. Создаем университет. Внутри него сам по себе рождается пустой вектор.
    University polytech;

    // 2. Добавляем студентов. Метод addStudent сам создаст объекты класса Student.
    // При создании у всех средний балл автоматически будет равен 0.0
    polytech.addstudent(1, "Алексей", 19);
    polytech.addstudent(2, "Мария", -5); // Специально проверяем защиту: возраст исправится на 0
    polytech.addstudent(3, "Влад", 20);

    // 3. Обновляем оценки студентам по их именам
    polytech.updateGradeFor("Алексей", 4.8);
    polytech.updateGradeFor("Мария", 3.9);
    
    // Специально проверяем защиту: ищем несуществующего студента
    polytech.updateGradeFor("КтоТоЕще", 5.0); 

    // 4. Выводим весь список студентов в терминал, чтобы увидеть финальный результат
    polytech.printAllStudents();

    return 0;
}
