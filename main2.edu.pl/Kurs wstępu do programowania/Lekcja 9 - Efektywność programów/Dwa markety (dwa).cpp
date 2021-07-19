#include<cstdio>
//#include<iostream>
#include<new>

using namespace std;

typedef long long LL;

LL min(LL a, LL b)
{
          return (a<b) ? a : b ;
}

int main()
{
    LL n, m, i, j, **t, wyn = 1000000009, temp = 0, l;
    
    scanf("%lld%lld", &n, &m);
    
    t = new LL *[n];
    
    for(i=0; i<=n-1; ++i)
    {
         t[i] = new LL [m];
    }
    
    /*** Wczytywanie danych oraz 1. faza algorytmu ***/
    
    for(i=0; i<=n-1; ++i)
    {
         for(j=0; j<=m-1; ++j)
         {
              scanf("%lld", &t[i][j]);
              
              temp += t[i][j];
         }
         
         wyn = min(wyn,temp);
         
         temp = 0;
    }
    
    /*** 2. faza algorytmu ***/
    
    for(i=0; i<=n-2; ++i)
    {
         for(j=i+1; j<=n-1; ++j)
         {
                    for(l=0; l<=m-1; ++l)
                    {
                         temp += min(t[i][l],t[j][l]);
                    }
                    
                    wyn = min(wyn,temp);
                    
                    temp = 0;
         }
    }
    
    printf("%lld\n", wyn);
    
    //system("pause");
    return 0;
}
