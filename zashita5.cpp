#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <list>
#include <ctime>
#include <algorithm>
using namespace std;

class Aeroport
{
private:
    int BoardNumber;
    int Price;
    int Seats;
    int SoldCount;

public:
    Aeroport()
    {
        BoardNumber = 000;
        Price = 2000;
        Seats = 150;
        SoldCount = 150;
    }
    Aeroport(int bn, int p, int s, int c)
    {
        BoardNumber = bn;
        Price = p;
        Seats = s;
        SoldCount = c;
    }
    void outputTo() const
    {
        cout << "---------------------------------------------" << endl;
        cout << "Номер рейса: " << BoardNumber << endl;
        cout << "Стоимость билет: " << Price << endl;
        cout << "Число месь: " << Seats << endl;
        cout << "Количество проданных: " << SoldCount << " человек" << endl;
        cout << "---------------------------------------------" << endl;
    }
    int Income(){
        return Price*SoldCount;
    }

    int get_BoardNumber() const
    {
        return BoardNumber;
    }

    int get_Price() const
    {
        return Price;
    }

    int get_Seats() const
    {
        return Seats;
    }

    int get_SeoldCount() const
    {
        return SoldCount;
    }

    void set_BoardNumber(int t)
    {
        BoardNumber = t;
    }

    void set_Price(int a)
    {
        Price = a;
    }

    void set_Seats(int t)
    {
        Seats = t;
    }

    void set_SeatCount(int c)
    {
        SoldCount = c;
    }
};

void print_aeroports(list<Aeroport> aeroports)
{
    for (Aeroport aeroport : aeroports)
        aeroport.outputTo();
}

bool compareByIncome( Aeroport &a,  Aeroport &b)
{
    return a.Income() < b.Income();
}

int main()
{
    int n;
    system("chcp 65001 >> nul");
    cout << "Введите количество кинотеатров: ";
    cin >> n;
    ifstream f("aport.txt");
    if (!f.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }
    list<Aeroport> Aeroports;
    for (int i = 0; i < n; i++)
    {
        int BN, PR, SE, SO;
        f >> BN;
        f >> PR;
        f >> SE;
        f >> SO;
        Aeroport TempOBJ = Aeroport(BN, PR, SE, SO);
        
        if (TempOBJ.Income() > 1000000)
        {
            Aeroports.push_back(TempOBJ);
        }
        else
        {
            continue;
        }
    }
    f.close();
    print_aeroports(Aeroports);
    sort(Aeroports.begin(), Aeroports.end(), compareByIncome);
    ofstream f_out("aport.txt", ios::app);
    char addMore;
    do
    {
        cout << "Введите данные нового аэропорта:" << endl;
        int BN, PR, SE, SO;
        cout << "Номер рейса: ";
        f >> BN;
        cout << "Цена билета: ";
        f >> PR;
        cout << "Количесто место: ";
        f >> SE;
        cout << "Количество проданных: ";
        f >> SO;

        Aeroport newAero(BN, PR, SE, SO);
        Aeroports.push_back(newAero);
        cout << "Добавить еще один кинотеатр? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');
    f.close();
    
    return 0;
}
