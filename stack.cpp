#include <iostream>
#include <stack>
using namespace std;

class WorkWithStack
{
private:
    stack<char> initialStack;
    stack<char> resultStack;
    stack<char> tempStack;

public:
    void displayStacks()
    {
        cout << "\n=== ПЕРВОНАЧАЛЬНЫЙ СТЕК ===" << endl;
        printStack(initialStack);

        cout << "\n=== РЕЗУЛЬТИРУЮЩИЙ СТЕК (каждый третий элемент) ===" << endl;
        printStack(resultStack);
    }
    void printStack(stack<char> inst) const
    {
        if (inst.empty())
        {
            cout << "Стек пуст" << endl;
            return;
        }

        cout << "Верхний элемент стека" << endl;
        for (std::stack<char> dump = inst; !dump.empty(); dump.pop())
        {
            std::cout << dump.top() << '\n';
        }
        cout << "Нижний элемент стека" << endl;
    }
    void inputToStack()
    {
        cout << "Введите символы для заполнения стека (нажмите Enter для завершения ввода):" << endl;

        string input;
        getline(cin, input);
        for (char symbol : input)
        {

            initialStack.push(symbol);
        }
    }
    void fillSecondStack()
    {
        for (std::stack<char> dump = initialStack; !dump.empty(); dump.pop())
        {
            tempStack.push(dump.top());
        }
        for (int i = 1; !tempStack.empty(); tempStack.pop())
        {
            if (i % 3 == 0)
            {
                resultStack.push(tempStack.top());
            }
            i++;
        }
    }
};

int main()
{
    WorkWithStack operate;
    system("chcp 65001 >> nul");
    operate.inputToStack();
    operate.fillSecondStack();
    operate.displayStacks();
    return 0;
}
