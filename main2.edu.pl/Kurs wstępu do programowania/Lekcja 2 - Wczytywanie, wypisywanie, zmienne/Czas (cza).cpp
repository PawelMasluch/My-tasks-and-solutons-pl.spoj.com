#include<iostream> // 100 pkt

using namespace std;

typedef long long LL;

int main()
{
    LL t,g,m,s;
    cin>>t;
    s = t % 60;
    g = t/3600;
    m = (t - (g*3600) - s)/60;
    cout<<g<<"g"<<m<<"m"<<s<<"s\n";
    //system("pause");
    return 0;   
}
