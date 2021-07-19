#include<iostream> // 100 pkt

using namespace std;

typedef long long LL;

int main()
{
    LL a,b,c;
    cin>>a>>b>>c;
    cout<<a*b*c<<endl<<2*((a*b)+(b*c)+(c*a))<<endl;
    //system("pause");
    return 0;   
}
