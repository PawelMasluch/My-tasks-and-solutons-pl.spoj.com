#include<iostream> // 100 pkt
#include<cstdio>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int tab[n];
    for(int i=0; i<n; i++)
    {
            cin>>tab[i];
    }
    for(int k=n-1; k>=0; k--)
    {
            cout<<tab[k]<<" ";
    }
    cout<<endl;
    return 0;
}
