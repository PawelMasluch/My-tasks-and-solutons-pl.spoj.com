#include<iostream> // 100 pkt
using namespace std;
int main()
{
    char z;
    cin>>z;
    if((int)(z)>=97)
    {
                     cout<<(int)(z)-96;
    }
    else
    {
        cout<<(int)(z)-64;
    }
    //system("pause");
    return 0;
}
