#include<cstdio>
//#include<iostream>
#include<new>

using namespace std;

typedef long long LL;

LL max(LL a, LL b)
{
          return (a>b) ? a : b ;
}

int main()
{
    LL n, i, *t, wyn = -1;
    
    scanf("%lld", &n);
    
    t = new LL [n];
    
    for(i=0; i<=n-1; ++i)
    {
             scanf("%lld", &t[i]);
    }
    
    for(i=1; i<=n-1; ++i)
    {
         if( t[i] != t[0] )
         {
             wyn = i;
         }
    }
    
    for(i=n-2; i>=0; --i)
    {
         if( t[i] != t[n-1] )
         {
             wyn = max(wyn,n-1-i);
         }
    }
    
    if( wyn == -1 )
    {
        printf("BRAK\n");
    }
    else
    {
        printf("%lld\n", wyn);
    }
    
    //system("pause");
    return 0;
}
