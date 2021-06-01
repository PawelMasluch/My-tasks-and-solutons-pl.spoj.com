#include<iostream> // AC
//#include<algorithm>
using namespace std;
typedef unsigned long long int ull;
ull NWD(ull a, ull b)
{
         ull temp;
         while(b)
         {
                 temp=a%b;
                 a=b;
                 b=temp;
         }
         return a;
}
ull NWW(ull a, ull b)
{
         return a*(b/NWD(a,b));
}
int main()
{
    int t,n,i,j;
    ull wynik=1;
    cin>>t;
    for(i=0; i<t; i++)
    {
             cin>>n;
             ull tab[n];
             for(j=0; j<n; j++)
             {
                      cin>>tab[j];
             }
             //sort(tab,tab+n);
             for(j=0; j<n; j++)
             {
                      wynik=NWW(wynik,tab[j]);
             }
             cout<<wynik<<endl;
             wynik=1;
    }
    //system("pause");
    return 0;
}
