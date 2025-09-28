#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct BuyTea
{
    char TeaType[50];
    char PackForm[50];
    char Manufacturer[50];
    float price;
    int amount;
    float sum;

    BuyTea() {
        strcpy(TeaType, "");
        strcpy(PackForm, "");
        strcpy(Manufacturer, "");
        price = 0;
        amount = 0;
        sum = 0;
    }

    BuyTea(const char* tea, const char* pack, const char* manu, float p, int am) {
        strncpy(TeaType, tea, 49); TeaType[49] = '\0';
        strncpy(PackForm, pack, 49); PackForm[49] = '\0';
        strncpy(Manufacturer, manu, 49); Manufacturer[49] = '\0';
        price = p;
        amount = am;
        sum = price * amount;
    }

    void print() {
        cout << "Тип: " << TeaType << endl;
        cout << "Форма упаковки: " << PackForm << endl;
        cout << "Производитель: " << Manufacturer << endl;
        cout << "Цена: " << price << endl;
        cout << "Количество: " << amount << endl;
        cout << "Сумма: " << sum << endl;
        cout << "-------------------" << endl;
    }
};

void bubbleSort(BuyTea* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].sum > arr[j + 1].sum) {
                BuyTea temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    system("chcp 65001 > nul");

    ifstream f("firstinput.txt");
    if (!f.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int records_count;
    f >> records_count;
    f.ignore();

    BuyTea* allteas = new BuyTea[records_count];

    for (int i = 0; i < records_count; i++) {
        string teaType, packForm, manufacturer;
        float price;
        int amount;
        getline(f, teaType);
        getline(f, packForm);
        getline(f, manufacturer);
        f >> price >> amount;
        f.ignore();
        allteas[i] = BuyTea(teaType.c_str(), packForm.c_str(), manufacturer.c_str(), price, amount);
    }
    f.close();

    cout << "Считано " << records_count << " записей из текстового файла:\n" << endl;
    for (int i = 0; i < records_count; i++)
        allteas[i].print();

    bubbleSort(allteas, records_count);

    ofstream bout("bin.dat", ios::binary);
    if (!bout.is_open()) {
        cout << "Ошибка открытия бинарного файла!" << endl;
        return 2;
    }

    bout.write((char*)&records_count, sizeof(records_count));

    float totalSum = 0;
    for (int i = 0; i < records_count; i++) {
        bout.write((char*)&allteas[i], sizeof(BuyTea));
        totalSum += allteas[i].sum;
    }
    bout.write((char*)&totalSum, sizeof(totalSum));
    bout.close();
    cout << "Все записи сохранены в бинарный файл bin.dat\n" << endl;

    ifstream bin("bin.dat", ios::binary);
    if (!bin.is_open()) {
        cout << "Ошибка открытия бинарного файла для чтения!" << endl;
        return 3;
    }

    int read_count;
    bin.read((char*)&read_count, sizeof(read_count));
    BuyTea* binTeas = new BuyTea[read_count];

    for (int i = 0; i < read_count; i++) {
        bin.read((char*)&binTeas[i], sizeof(BuyTea));
    }

    float read_totalSum;
    bin.read((char*)&read_totalSum, sizeof(read_totalSum));
    bin.close();

    cout << "Считано " << read_count << " записей из бинарного файла:\n" << endl;
    for (int i = 0; i < read_count; i++)
        binTeas[i].print();

    cout << "Всего: " << read_totalSum << endl;

    delete[] allteas;
    delete[] binTeas;

    return 0;
}
