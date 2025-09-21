#include <iostream>
#include <cmath>
using namespace std;

class EquilateralTriangle
{
private:
    double sideLength;

public:
    EquilateralTriangle(double side = 1.0)
    {
        if (side > 0)
        {
            sideLength = side;
        }
        else
        {
            sideLength = 1.0;
            cout << "Ошибка: длина стороны должна быть положительной. Установлено значение по умолчанию 1.0" << endl;
        }
    }

    double calculateapoheme() const
    {
        return (sideLength * sqrt(3)) / 2;
    }

    double calculateBisector() const
    {
        return calculateapoheme();
    }

    double calculatePerimeter() const
    {
        return 3 * sideLength;
    }

    double calculateArea() const
    {
        return (sideLength * sideLength * sqrt(3)) / 4;
    }

    void printInfo() const
    {
        cout << "         РАВНОСТОРОННИЙ ТРЕУГОЛЬНИК       " << endl;
        cout << "Длина стороны: " << sideLength << endl;
        cout << "Высота:        " << fixed << calculateapoheme() << endl;
        cout << "Биссектриса:   " << calculateBisector() << endl;
        cout << "Периметр:      " << calculatePerimeter() << endl;
        cout << "Площадь:       " << calculateArea() << endl;
    }

    double getSideLength() const
    {
        return sideLength;
    }

    void setSideLength(double side)
    {
        if (side > 0)
        {
            sideLength = side;
        }
        else
        {
            cout << "Ошибка: длина стороны должна быть положительной" << endl;
        }
    }
};

class Pyramid : public EquilateralTriangle
{
private:
    double apoheme;

public:
    Pyramid(double side, double h) : EquilateralTriangle(side)
    {
        apoheme = h;
    }

    double calculateVolume() const
    {
        double baseArea = EquilateralTriangle::calculateArea();
        return (1.0 / 3.0) * baseArea * apoheme;
    }

    double calculateArea() const
    {
        double baseArea = EquilateralTriangle::calculateArea();
        double side = getSideLength();
        double lateralArea = 3 * (side * apoheme / 2.0);
        return baseArea + lateralArea;
    }

    void printInfo() const
    {
        cout << "\nПРАВИЛЬНАЯ ТРЕУГОЛЬНАЯ ПИРАМИДА" << endl;
        cout << "Длина стороны основания: " << getSideLength() << endl;
        cout << "Апофема: " << apoheme << endl;
        cout << "Объем: " << calculateVolume() << endl;
        cout << "Площадь полной поверхности: " << calculateArea() << endl;
    }

    double getapoheme() const { return apoheme; }
    void setapoheme(double h)
    {
        if (h > 0)
            apoheme = h;
    }
};

int main()
{
    system("chcp 65001 > nul");
    EquilateralTriangle triangle1(5.0);
    EquilateralTriangle triangle2(7.5);
    EquilateralTriangle triangle3;

    cout << "Треугольник 1:" << endl;
    triangle1.printInfo();

    cout << "\nТреугольник 2:" << endl;
    triangle2.printInfo();

    cout << "\nТреугольник 3:" << endl;
    triangle3.printInfo();

    cout << "\nДополнительные вычисления для треугольника 1:" << endl;
    cout << "Высота: " << triangle1.calculateapoheme() << endl;
    cout << "Площадь: " << triangle1.calculateArea() << endl;
    cout << "Периметр: " << triangle1.calculatePerimeter() << endl;

    cout << "\nПосле изменения размера треугольника 3:" << endl;
    triangle3.setSideLength(3.0);
    triangle3.printInfo();

    Pyramid pir1(5.0, 2.9);
    Pyramid pir2(7.5, 4.4);

    pir1.calculateVolume();
    pir1.printInfo();
    cout << "\n=====================================================" << endl;
    const int N = 4;
    const int M = 3;
    EquilateralTriangle triangles[N] = {
        EquilateralTriangle(5.0),
        EquilateralTriangle(7.5),
        EquilateralTriangle(3.0),
        EquilateralTriangle(6.0)};

    Pyramid pyramids[M] = {
        Pyramid(5.0, 3.0),
        Pyramid(7.5, 4.4),
        Pyramid(6.0, 5.0)};

    cout << "Список треугольников:" << endl;
    for (int i = 0; i < N; i++)
    {
        triangles[i].printInfo();
    }

    cout << "\nСписок пирамид:" << endl;
    for (int i = 0; i < M; i++)
    {
        pyramids[i].printInfo();
    }
    double sumArea = 0;
    for (int i = 0; i < N; i++)
    {
        sumArea += triangles[i].calculateArea();
    }
    double avgArea = sumArea / N;
    cout << "\nСредняя площадь треугольников = " << avgArea << endl;

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (triangles[i].calculateArea() > avgArea)
            count++;
    }
    cout << "Количество треугольников с площадью больше средней: " << count << endl;

    double maxVolume = pyramids[0].calculateVolume();
    int maxIndex = 0;
    for (int i = 1; i < M; i++)
    {
        if (pyramids[i].calculateVolume() > maxVolume)
        {
            maxVolume = pyramids[i].calculateVolume();
            maxIndex = i;
        }
    }

    cout << "\nПирамида с наибольшим объёмом:" << endl;
    pyramids[maxIndex].printInfo();

    return 0;
}
