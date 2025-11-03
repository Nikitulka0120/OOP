#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <stack>
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



bool compareByAddress(const cinema &a, const cinema &b)
{
    return a.get_address() < b.get_address();
}

void printStack(stack<cinema> inst)
    {
        if (inst.empty())
        {
            cout << "Стек пуст" << endl;
            return;
        }

        for (std::stack<cinema> dump = inst; !dump.empty(); dump.pop())
        {
            dump.top().outputTo();
        }
    }

int main()
{
    int n;
    system("chcp 65001 >> nul");
    cout << "Введите количество кинотеатров: ";
    cin >> n;
    ifstream f("cinemas.txt");
    if (!f.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }
    stack<cinema> cinemaMore;
    stack<cinema> cinemaLess;
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
            cinemaMore.push(cinema(title, address, workingTime, capacity));
        }
        else if (capacity < 200)
        {
            cinemaLess.push(cinema(title, address, workingTime, capacity));
        }
        else
        {
            continue;
        }
        
    }
    
    cout<<"Кинотеатры с вместимостью менее 200"<<endl;
    printStack(cinemaLess);
    cout<<"Кинотеатры с вместимостью более 200"<<endl;
    printStack(cinemaMore);
    f.close();
}
