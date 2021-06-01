#include<string> // AC
#include<iostream>
using namespace std;
int main()
{
    int t,n,i,j;
    bool tab[10001];
    for(i=2; i<=10000; i++)
    {
             tab[i]=true;
    }
    for(i=2; i<=10000; i++)
    {
             if(tab[i]==true)
             {
                             for(j=2*i; j<=10000; j+=i)
                             {
                                        tab[j]=false;
                             }
             }
    }
    cin>>t;
    for(i=0; i<t; i++)
    {
             cin>>n;
             if(tab[n]==true)
             {
                             cout<<"TAK\n";
             }
             else
             {
                 cout<<"NIE\n";
             }
    }
    return 0;
}

