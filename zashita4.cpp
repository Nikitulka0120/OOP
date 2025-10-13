#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class cinema
{
private:
    string title;
    string address;
    string workingTime;
    int capacity;

public:
    cinema(string t, string a, string w, int c)
    {
        title = t;
        address = a;
        workingTime = w;
        capacity = c;
    }
    void outputTo() const
    {
        cout << "---------------------------------------------" << endl;
        cout << "Название: " << title << endl;
        cout << "Адрес: " << address << endl;
        cout << "Время работы: " << workingTime << endl;
        cout << "Вместимость: " << capacity << " человек" << endl;
        cout << "---------------------------------------------" << endl;
    }

    string get_title() const
    {
        return title;
    }

    string get_address() const
    {
        return address;
    }

    string get_workingTime() const
    {
        return workingTime;
    }

    int get_capacity() const
    {
        return capacity;
    }

    void set_title(string t)
    {
        title = t;
    }

    void set_address(string a)
    {
        address = a;
    }

    void set_workingTime(string t)
    {
        workingTime = t;
    }

    void set_capacity(int c)
    {
        capacity = c;
    }
};

void printCinemas(const vector<cinema> &cinemas, const string &title)
{
    cout << title << endl;
    if (cinemas.empty())
    {
        cout << "Список пуст!" << endl;
        return;
    }
    for (int i = 0; i < (int)cinemas.size(); ++i)
    {
        cinemas[i].outputTo();
    }
}

bool compareByAddress(const cinema &a, const cinema &b)
{
    return a.get_address() < b.get_address();
}

void insertSorted(vector<cinema> &cinemas, const cinema &cinema)
{
    int position = 0;
    while (position < cinemas.size() && cinemas[position].get_address() > cinema.get_address())
    {
        position++;
    }
    cinemas.insert(cinemas.begin() + position, cinema);
}

int main()
{
    int n;
    system("chcp 65001 >> nul");
    cout << "Введите количество кинотеатров: ";
    cin >> n;
    ifstream f("apteka.txt");
    if (!f.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }
    vector<cinema> spaciousCinema;
    for (int i = 0; i < n; i++)
    {
        string title, address, workingTime;
        int capacity;
        getline(f, title);
        getline(f, address);
        getline(f, workingTime);
        f >> capacity;
        f.ignore();
        if (capacity > 200)
        {
            spaciousCinema.push_back(cinema(title, address, workingTime, capacity));
        }
        else
        {
            continue;
        }
    }
    f.close();

    ofstream f_out("apteka.txt", ios::app); // открываем файл в режиме добавления
    char addMore;
    do
    {
        string title, address, workingTime;
        int capacity;

        cout << "Введите данные нового кинотеатра:" << endl;
        cout << "Название: ";
        cin.ignore(); // очищаем буфер
        getline(cin, title);
        cout << "Адрес: ";
        getline(cin, address);
        cout << "Время работы: ";
        getline(cin, workingTime);
        cout << "Вместимость: ";
        cin >> capacity;

        cinema newCinema(title, address, workingTime, capacity);
        if (capacity > 200)
        {
            insertSorted(spaciousCinema, newCinema);
            cout << "Кинотеатр добавлен в список вместительных!" << endl;
            f_out<<endl;
            f_out << title << endl;
            f_out << address << endl;
            f_out << workingTime << endl;
            f_out << capacity << endl;
        }
        else
        {
            cout << "Кинотеатр не попадает в категорию вместительных!" << endl;
        }

        cout << "Добавить еще один кинотеатр? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');
    f.close();
    printCinemas(spaciousCinema, "================================Список вместительных залов===============================");
    sort(spaciousCinema.begin(), spaciousCinema.end(), compareByAddress);
    printCinemas(spaciousCinema, "================================Упорядоченный список вместительных залов================================");

    return 0;
}
