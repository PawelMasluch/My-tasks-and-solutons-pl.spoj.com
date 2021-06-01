#include<cstdio> // AC
#include<new>
//#include<iostream>

using namespace std;

int max(int a, int b)
{
    return (a>b) ? a : b ;
}

void wczytaj(int *t, int n)
{
     int i;
     
     for(i=0; i<=n-1; ++i)
     {
          scanf("%d", &t[i]);
     }
}

void odwroc(int *t, int n)
{
     int i;
     
     for(i=0; i<=n-1; ++i)
     {
          t[i] *= -1;
     }    
}

int bin(int *S, int n, int a)
{
    int pocz = 1, kon = n - 1, sr;
    
    while( pocz <= kon )
    {
           sr = ( pocz + kon ) >> 1;
           
           if( S[ sr - 1 ] <= a  &&  a < S[ sr ] )
           {
               return sr;
           }
           else
           {
               if( S[ sr - 1 ] > a )
               {
                   kon = sr - 1;
               }
               else
               {
                   pocz = sr + 1;
               }
           }
    }
}

int f(int *t, int n)
{
    int *S = new int [n+1], INF = 1000000001, i, ind;
    
    S[0] = -INF;
    
    for(i=1; i<=n; ++i)
    {
             S[i] = INF;
    }
    
    for(i=0; i<=n-1; ++i)
    {
             ind = bin(S,n+1,t[i]);
             S[ind] = t[i];
    }
    
    i = n;
    
    while( S[i] == INF )
    {
           --i;
    }
    
    delete [] S;
    
    return i;
}

int main()
{
    int d, n, *t, wyn;
    
    scanf("%d", &d);
    
    while( d > 0 )
    {
           scanf("%d", &n);
           
           t = new int [n];
           
           wczytaj(t,n);
           
           wyn = f(t,n);
           
           odwroc(t,n);
           
           wyn = max( wyn, f(t,n) );
           
           printf("%d\n", n - wyn);
           
           delete [] t;
           
           --d;
    }
    
    //system("pause");
    return 0;
}

