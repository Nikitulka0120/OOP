#include <iostream>
#include <string>
#include <deque>
using namespace std;
class train
{
private:
    int TrainNumber;
    string DestinationStation;
    string DestinationTime;

public:
    train()
    {
        TrainNumber = 100;
        DestinationStation = "Novosibirsk";
        DestinationTime = "00-00";
    };

    train(int TN, string DS, string DT)
    {
        TrainNumber = TN;
        DestinationStation = DS;
        DestinationTime = DT;
    }

    int get_TrainNumber()
    {
        return TrainNumber;
    }
    string get_DestinationStation()
    {
        return DestinationStation;
    }
    string get_DestinationTime()
    {
        return DestinationTime;
    }
    void set_TrainNumber(int TN)
    {
        TrainNumber = TN;
    }
    void set_DestinationStation(string DS)
    {
        DestinationStation = DS;
    }
    void set_DestinationTime(string DT)
    {
        DestinationTime = DT;
    }
    void OutInfo(){
        cout<<"Номер поезда: "<<TrainNumber<<endl;
        cout<<"Станция прибытия: "<<DestinationStation<<endl;
        cout<<"Время отправления: "<<DestinationTime<<endl<<endl;
    }
};

void view_deque(deque<train> Trains){
    for (auto iter = Trains.begin(); iter != Trains.end(); iter++)
        (*iter).OutInfo();
    cout << endl;
}

void find_by_number(deque<train> Trains, int find_number){
    for (auto iter = Trains.begin(); iter != Trains.end(); iter++)
    if ((*iter).get_TrainNumber() == find_number){
        (*iter).OutInfo();
        return;
    }
    cout << endl;
}

void find_by_statin(deque<train> Trains, string find_Station){
    for (auto iter = Trains.begin(); iter != Trains.end(); iter++)
    if ((*iter).get_DestinationStation() == find_Station){
        (*iter).OutInfo();
    }
    cout << endl;
}

int main()
{
    system("chcp 65001 >> nul");
    deque<train> Trains;
    char addMore;
    do
    {
        cout << "Введите данные нового поезда:" << endl;
        int TN;
        string DS, DT;
        cout << "Номер поезда: ";
        cin >> TN;
        cout << "Станция назначения: ";
        cin >> DS;
        cout << "Время отправления: ";
        cin >> DT;
        Trains.push_back(train(TN,DS,DT));
        cout<<"Добавить ещё поезда? (Y/N)";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');
    view_deque(Trains);
    int find_number;
    cout<<"Введите номер поезда о котором хотите получить информацию:"<<endl;
    cin>>find_number;
    find_by_number(Trains,find_number);
    string find_station;
    cout<<"Введите название станции чтобы получить список поездов:"<<endl;
    cin>>find_station;
    find_by_statin(Trains,find_station);
    return 0;
}
