#include<iostream> // 100 pkt
#include<algorithm>
using namespace std;
int main()
{
    int t[4],i;
    for(i=0; i<4; i++)
    {
             cin>>t[i];
    } 
    sort(t,t+4);
    cout<<(long long)t[1]*t[2]<<endl;
    //system("pause");
    return 0;
}
