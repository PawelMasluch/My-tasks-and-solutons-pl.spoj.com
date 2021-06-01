#include<iostream> // 100 pkt
#include<cstdio>
using namespace std;
int main()
{
int n;
cin>>n;
int tab[n];
for(int z=0; z<n; z++)
{
cin>>tab[z];
}
for(int i = n-1; i >= 1; i--)
    {
        for(int j=0; j<i; j++)
        {
            if (tab[j]<=tab[j+1])
            {
                swap(tab[j], tab[j+1]);
            }
        }
    }
    for(int u=0; u<n; u++)
    {
            cout<<tab[u]<<" ";
    }
    return 0;
}
