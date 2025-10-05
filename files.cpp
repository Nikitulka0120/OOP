#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct BuyTea {
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

    void print() const {
        cout << "Тип: " << TeaType << endl;
        cout << "Форма упаковки: " << PackForm << endl;
        cout << "Производитель: " << Manufacturer << endl;
        cout << "Цена: " << price << endl;
        cout << "Количество: " << amount << endl;
        cout << "Сумма: " << sum << endl;
        cout << "-------------------" << endl;
    }
};

class TeaFileManager {
private:
    BuyTea* teas = nullptr;
    int count = 0;
    float totalSum = 0;

public:
    bool readFromText(const char* filename) {
        ifstream f(filename);
        if (!f.is_open()) {
            cout << "Ошибка открытия файла: " << filename << endl;
            return false;
        }

        f >> count;
        f.ignore();

        delete[] teas;
        teas = new BuyTea[count];

        for (int i = 0; i < count; i++) {
            string teaType, packForm, manufacturer;
            float price;
            int amount;

            getline(f, teaType);
            getline(f, packForm);
            getline(f, manufacturer);
            f >> price >> amount;
            f.ignore();

            teas[i] = BuyTea(teaType.c_str(), packForm.c_str(), manufacturer.c_str(), price, amount);
        }

        f.close();
        cout << "Считано " << count << " записей из текстового файла\n" << endl;
        return true;
    }

    void sortBySum() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (teas[j].sum > teas[j + 1].sum) {
                    BuyTea temp = teas[j];
                    teas[j] = teas[j + 1];
                    teas[j + 1] = temp;
                }
            }
        }
    }

    bool writeToBinary(const char* filename) {
        ofstream bout(filename, ios::binary);
        if (!bout.is_open()) {
            cout << "Ошибка открытия бинарного файла: " << filename << endl;
            return false;
        }

        bout.write((char*)&count, sizeof(count));

        totalSum = 0;
        for (int i = 0; i < count; i++) {
            bout.write((char*)&teas[i], sizeof(BuyTea));
            totalSum += teas[i].sum;
        }

        bout.write((char*)&totalSum, sizeof(totalSum));
        bout.close();

        cout << "Данные записаны в бинарный файл: " << filename << "\n" << endl;
        return true;
    }

    bool readFromBinary(const char* filename) {
        ifstream bin(filename, ios::binary);
        if (!bin.is_open()) {
            cout << "Ошибка открытия бинарного файла: " << filename << endl;
            return false;
        }

        bin.read((char*)&count, sizeof(count));

        delete[] teas;
        teas = new BuyTea[count];

        for (int i = 0; i < count; i++) {
            bin.read((char*)&teas[i], sizeof(BuyTea));
        }

        bin.read((char*)&totalSum, sizeof(totalSum));
        bin.close();

        cout << "Считано " << count << " записей из бинарного файла\n" << endl;
        return true;
    }

    void printAll() const {
        for (int i = 0; i < count; i++) {
            teas[i].print();
        }
        cout << "Общая сумма: " << totalSum << endl;
    }
};

int main() {
    system("chcp 65001 > nul");

    TeaFileManager manager;

    if (!manager.readFromText("firstinput.txt"))
        return 1;

    manager.sortBySum();
    manager.printAll();

    if (!manager.writeToBinary("bin.dat"))
        return 2;

    TeaFileManager binManager;
    if (!binManager.readFromBinary("bin.dat"))
        return 3;

    binManager.printAll();
    return 0;
}
