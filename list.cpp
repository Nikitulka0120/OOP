#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <ctime>
using namespace std;

#define records 15
#define maxfloors 20
#define maxrooms 5

class apartment
{
private:
    int rooms_count;
    int floor;
    int area;
    string address;

public:
    apartment()
    {
        rooms_count = 1;
        floor = 1;
        area = 30;
        address = "Default address";
    }
    apartment(int r, int f, int ar, string ad)
    {
        rooms_count = r;
        floor = f;
        area = ar;
        address = ad;
    }
    int get_rooms_count()
    {
        return rooms_count;
    }
    int get_floor()
    {
        return floor;
    }
    int get_area()
    {
        return area;
    }
    string get_address()
    {
        return address;
    }
    void set_rooms_count(int arg)
    {
        rooms_count = arg;
    }
    void set_floor(int arg)
    {
        floor = arg;
    }
    void set_area(int arg)
    {
        area = arg;
    }
    void set_address(string arg)
    {
        address = arg;
    }
    void outputTo() const
    {
        cout << "---------------------------------------------" << endl;
        cout << "Адрес: " << address << endl;
        cout << "Количество комнат: " << rooms_count << endl;
        cout << "Этаж: " << floor << endl;
        cout << "Площадь: " << area << " м. кв." << endl;
        cout << "---------------------------------------------" << endl;
    }
};

void init_kartoteka(list<apartment> &apartments)
{
    srand(unsigned(time(NULL)));

    string addresses_for_rand[]{
        "ул. Сибирская 78 кв. 20", "ул. Южная 18 кв. 22", "ул. Массивная 6 кв. 2",
        "ул. Колбасная 7 кв. 55", "ул. Объектно ориентированная 56 кв. 99", "ул. Четная 9 кв. 78",
        "ул. Нечетная 2 кв. 79"};

    int AddressesSize = sizeof(addresses_for_rand) / sizeof(addresses_for_rand[0]);
    for (int i = 0; i < records; i++)
    {
        int rand_rooms = 1 + rand() % maxrooms;
        int rand_dloor = 1 + rand() % maxfloors;
        int rand_area = 20 + rand() % 100;
        apartments.push_back(apartment(rand_rooms, rand_dloor, rand_area, addresses_for_rand[rand() % AddressesSize]));
    }
}

void print_krtoteka(list<apartment> apartments)
{
    for (apartment apart : apartments)
        apart.outputTo();
}

void find_and_remove_matches(list<apartment> &kartoteka, int target_rooms, int target_floor)
{
    list<apartment> matches;
    list<apartment>::iterator iter = kartoteka.begin();
    while (iter != kartoteka.end())
    {
        if ((*iter).get_rooms_count() == target_rooms && (*iter).get_floor() == target_floor)
        {
            matches.push_back(*iter);
        }
        ++iter;
    }
    if (matches.empty())
    {
        cout << "Подходящих вариантов не найдено." << endl;
    }
    else if (matches.size() == 1)
    {
        cout << "Найден подходящий вариант:" << endl;
        matches.front().outputTo();
        iter = kartoteka.begin();
        while (iter != kartoteka.end())
        {
            if ((*iter).get_rooms_count() == target_rooms && (*iter).get_floor() == target_floor)
            {
                cout<<"Найден подходящий вариант:"<<endl;
                (*iter).outputTo();
                iter = kartoteka.erase(iter);
                break;
            }
            else
            {
                ++iter;
            }
        }
        cout << "Квартира удалена из картотеки." << endl;
    }
    else
    {
        cout << "Найдено несколько подходящих вариантов (" << matches.size() << "):" << endl;
        print_krtoteka(matches);
    }
}

int main()
{
    system("chcp 65001 >> nul");
    list<apartment> kartoteka;
    init_kartoteka(kartoteka);
    cout << "Сгенерированный список квартир" << endl;
    print_krtoteka(kartoteka);
    cout<<"\n\n\n"<<endl;
    cout << "Введите данные квартиры на обмен:" << endl;
    int floor, area, count;
    string address;
    cout << "Введите адрес: ";
    getline(cin, address);
    cout << "Введите этаж: ";
    cin >> floor;
    cout << "Введите площадь: ";
    cin >> area;
    cout << "Введите количество комнат: ";
    cin >> count;
    cout<<"\n\n\n"<<endl;
    find_and_remove_matches(kartoteka, count, floor);
    cout<<"\n\n\n"<<endl;
    cout << "Итоговая картотека после обмена" << endl;
    print_krtoteka(kartoteka);
}
