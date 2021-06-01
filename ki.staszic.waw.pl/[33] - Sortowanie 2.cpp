#include<iostream> // 100 pkt
#include<algorithm>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int t[n];
    for(i=0; i<n; i++)
    {
             cin>>t[i];
    }
    sort(t,t+n);
    for(i=0; i<n; i++)
    {
             cout<<t[i]<<" ";
    }
    cout<<endl;
    return 0;
}
