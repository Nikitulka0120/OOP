#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class Animal
{
private:
    string species;
    string habitat;
    char gender;
    int age;
    double weight;

public:
    Animal(string sp, string hab, char g, int ag, double w)
    {
        species = sp;
        habitat = hab;
        gender = g;
        age = ag;
        weight = w;
    }
    void outputTo() const
    {
        cout << "---------------------------------------------" << endl;
        cout << "Вид животного: " << species << endl;
        cout << "Место обитания: " << habitat << endl;
        cout << "Пол: " << (gender == 'm' ? "мужской" : "женский") << endl;
        cout << "Возраст: " << age << " лет" << endl;
        cout << "Вес: " << weight << " кг" << endl;
        cout << "---------------------------------------------" << endl;
    }

    string get_Species() const
    {
        return species;
    }

    string get_Habitat() const
    {
        return habitat;
    }

    char get_Gender() const
    {
        return gender;
    }

    int get_Age() const
    {
        return age;
    }

    double get_Weight() const
    {
        return weight;
    }

    void set_Species(string sp)
    {
        species = sp;
    }

    void set_Habitat(string hab)
    {
        habitat = hab;
    }

    void set_Gender(char g)
    {
        gender = g;
    }

    void set_Age(int ag)
    {
        age = ag;
    }

    void set_Weight(double w)
    {
        weight = w;
    }
};

void printAnimals(const vector<Animal>& animals, const string& title) {
    cout << title << endl;
    if (animals.empty()) {
        cout << "Список пуст!" << endl;
        return;
    }
    for (int i = 0; i < (int)animals.size(); ++i) {
        animals[i].outputTo();
    }
}

bool compareByAge(const Animal& a, const Animal& b) {
    return a.get_Age() > b.get_Age();
}

void insertSorted(vector<Animal>& sortedAnimals, const Animal& newAnimal) {
    int position = 0;
    while (position < sortedAnimals.size() && sortedAnimals[position].get_Age() > newAnimal.get_Age()) {
        position++;
    }
    sortedAnimals.insert(sortedAnimals.begin() + position, newAnimal);
}

int main()
{
    int n;
    system("chcp 65001 >> nul");
    cout << "Введите количество животных: ";
    cin >> n;
    srand(unsigned(time(NULL)));
    
    vector<string> habitats_for_rand{
        "Саванна Африки", "Тропические леса Амазонки", "Сибирская тайга",
        "Австралийские пустыни", "Антарктида", "Северная Америка",
        "Европейские леса", "Азиатские степи", "Индийские джунгли",
        "Морские глубины", "Горные хребты", "Арктическая тундра"};

    vector<string> animals_for_rand{
        "Лев", "Тигр", "Слон", "Жираф", "Зебра",
        "Медведь", "Волк", "Лиса", "Заяц", "Олень",
        "Кенгуру", "Коала", "Панда", "Обезьяна", "Пингвин"};

    char genders[] = {'m', 'f'};

    int animalsSize = animals_for_rand.size();
    int habitatsSize = habitats_for_rand.size();
    int gendersSize = sizeof(genders) / sizeof(genders[0]);
    
    vector<Animal> animals;
    vector<Animal> Dolgoziteli;
    
    for (int i = 0; i < n; i++)
    {
        int randAge = rand() % 100;
        int randWeight = rand() % 150;
        animals.push_back(Animal(animals_for_rand[rand() % animalsSize],
                                 habitats_for_rand[rand() % habitatsSize],
                                 genders[rand() % gendersSize],
                                 randAge, randWeight));
    }
    printAnimals(animals, "Изначальный список зверушек");
    for (int i = 0; i < (int)animals.size(); ++i)
    {
        if(animals[i].get_Age() > 50){
            Dolgoziteli.push_back(animals[i]);
        }
    }
    sort(Dolgoziteli.begin(), Dolgoziteli.end(), compareByAge);
    printAnimals(Dolgoziteli, "Список долгожителей (Более 50 лет), отсортированный по возрасту:");
    cout << "\n=== ДОБАВЛЕНИЕ НОВЫХ ЖИВОТНЫХ В ОТСОРТИРОВАННЫЙ ВЕКТОР ===" << endl;
    char addMore;
    do {
        string species, habitat;
        char gender;
        int age;
        double weight;
        
        cout << "Введите данные нового животного:" << endl;
        cout << "Вид: ";
        cin >> species;
        cout << "Место обитания: ";
        cin.ignore();
        getline(cin, habitat);
        cout << "Пол (m/f): ";
        cin >> gender;
        cout << "Возраст: ";
        cin >> age;
        cout << "Вес: ";
        cin >> weight;
        
        Animal newAnimal(species, habitat, gender, age, weight);
        
        if (age > 50) {
            insertSorted(Dolgoziteli, newAnimal);
            cout << "Животное добавлено в список долгожителей!" << endl;
        } else {
            cout << "Животное не является долгожителем (возраст <= 50 лет)" << endl;
        }
        
        cout << "Добавить еще одно животное? (y/n): ";
        cin >> addMore;
        
    } while (addMore == 'y' || addMore == 'Y');
    printAnimals(Dolgoziteli, "\nФинальный список долгожителей:");
    
    if (!Dolgoziteli.empty()) {
        cout << "Статистика долгожителей:" << endl;
        cout << "Всего долгожителей: " << Dolgoziteli.size() << endl;
        cout << "Самый старший: " << Dolgoziteli[0].get_Age() << " лет (" << Dolgoziteli[0].get_Species() << ")" << endl;
        cout << "Самый младший из долгожителей: " << Dolgoziteli.back().get_Age() << " лет (" << Dolgoziteli.back().get_Species() << ")" << endl;
    } else {
        cout << "Долгожителей не найдено!" << endl;
    }

    return 0;
}
