#include <iostream>
#include <string>
#include <deque>
#include <fstream>
using namespace std;
class Apteka
{
private:
    string Title;
    string Address;
    string WorkTime;

public:
    Apteka()
    {
        Title = 100;
        Address = "Novosibirsk";
        WorkTime = "00-00";
    };

    Apteka(string Tit, string AD, string WT)
    {
        Title = Tit;
        Address = AD;
        WorkTime = WT;
    }

    string get_Title()
    {
        return Title;
    }
    string get_Address()
    {
        return Address;
    }
    string get_WorkTime()
    {
        return WorkTime;
    }
    void set_Title(string Tit)
    {
        Title = Tit;
    }
    void set_Address(string AD)
    {
        Address = AD;
    }
    void set_WorkTime(string WT)
    {
        WorkTime = WT;
    }
    void OutInfo(){
        cout<<"Название аптеки: "<<Title<<endl;
        cout<<"Адрес аптеки: "<<Address<<endl;
        cout<<"Время работы: "<<WorkTime<<endl<<endl;
    }
};

void view_deque(deque<Apteka> Aptekas){
    for (auto iter = Aptekas.begin(); iter != Aptekas.end(); iter++)
        (*iter).OutInfo();
    cout << endl;
}

int main()
{
    system("chcp 65001 >> nul");
    int aptekas_count;
    cout<<"Введите количество аптек"<<endl;
    cin>>aptekas_count;
    deque<Apteka> Aptekas;
    ifstream f("apteka.txt");
    if (f.is_open()){
        for (int i = 0; i<aptekas_count; i++){
            string title, Address, WorkTime;
            getline(f,title);
            getline(f,Address);
            getline(f,WorkTime);
            Aptekas.push_back(Apteka(title, Address, WorkTime));
    }
    }
    f.close();
    view_deque(Aptekas);
    return 0;
}
