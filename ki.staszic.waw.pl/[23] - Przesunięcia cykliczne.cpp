#include<iostream> // 100 pkt
#include<cstdio>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int tab[n];
    for(int i=0; i<n; i++)
    {
            cin>>tab[i];
    }
    for(int j=k; j<n; j++)
    {
            cout<<tab[j]<<" ";
    }
    for(int h=0; h<k; h++)
    {
            cout<<tab[h]<<" ";
    }
    return 0;
}
