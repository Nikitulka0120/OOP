#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Straight
{
private:
    int a;
    int b;
public:
    Straight(){
        a=0;
        b=0;
    }
    Straight(int A, int B)
    {
        a=A;
        b=B;
    }

    int get_A()
    {
        return a;
    }

    void set_A(int A)
    {
        a = A;
    }

    int get_B()
    {
        return b;
    }

    void set_B(int B)
    {
        b = B;
    }

    void get_Y(){
        cout << "y="<<get_A()<<"x+"<<get_B()<<endl;
    }

    int is_par(){
        if (get_A()==0){
            return 1;
        }
        else{
            return 0;
        }
    }

};

int main()
{
    Straight st0;
    Straight st1(1,2);
    Straight st2(3,0);
    Straight st3(0,5);
    Straight st4(14,22);
    Straight st5(11,223);
    st0.get_Y();
    st1.get_Y();
    st2.get_Y();
    st3.get_Y();
    st4.get_Y();
    st5.get_Y();
    int k1 = st0.is_par()+st1.is_par()+st2.is_par()+st3.is_par()+st4.is_par()+st5.is_par();
    cout<<"Количество параллельных: "<<k1<<endl;

}
