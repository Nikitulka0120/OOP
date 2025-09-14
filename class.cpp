#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string FIO;
    char gender;
    int age;
    double average;

public:
    Student(string F, char g, int ag, double av)
    {
        FIO = F;
        gender = g;
        age = ag;
        average = av;
    }
    // Метод для вывода информации о студенте в консоль
    void outputTo()
    {
        // Здесь команды вывода значений всех полей объекта на экран
        cout << "Фамилия студента: " << FIO << endl;
        cout << "пол: " << (gender == 'm' ? "мужской" : "женский") << endl;
        cout << "возраст: " << age << endl;
        cout << "средний балл = " << average << endl;
    }
    // Метод для получения значения ФИО студента
    string get_FIO()
    {
        return FIO;
    }
    // Метод для изменения значения ФИО студента
    void set_FIO(string f)
    {
        FIO = f;
    }
    // Метод для получения значения возраста студента
    int get_Age()
    {
        return age;
    }
    // Метод для изменения значения возраста студента
    void set_Age(int ag)
    {
        age = ag;
    }
    // Метод для получения значения среднего балла студента
    double get_Average()
    {
        return average;
    }
    // Метод для изменения значения среднего балла студента
    void set_Average(double av)
    {
        average = av;
    }
    // Метод для изменения значения пола студента
    void set_Age(char pol)
    {
        gender = pol;
    }
    // Метод для получения значения пола студента
    char get_Gender()
    {
        return gender;
    }
};

int main()
{
    Student Ivanov = Student("Иванов Василий Петрович", 'm', 21, 4.6);
    Student *Petrov = new Student("Петров Николай Романович", 'm', 19, 3.6);
    Petrov->outputTo();
    Ivanov.outputTo();
    Petrov->set_Age(Petrov->get_Age() + 1);
    Ivanov.set_Average(3.8);
    cout << "Возраст Петрова " << Petrov->get_Age() << "\n";
    cout << "Возраст Иванова " << Ivanov.get_Age();
    Petrov->outputTo();
    Ivanov.outputTo();
    return 0;
}
