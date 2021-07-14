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
 
int f(int *t, int n)
{
    int i, wyn = 2, ile = 2;
    
    for(i=2; i<=n-1; ++i)
    {
         if( t[i] - t[i-1] == t[i-1] - t[i-2] )
         {
             ++ile;
             wyn = max(wyn,ile); 
         }
         else
         {   
             ile = 2;   
         }
    }
    
    return wyn;
}
 
void g(int *t, int n)
{
     if( n <= 2 )
     {
         printf("%d\n", n);
     }
     else
     {
         printf("%d\n", f(t,n));
     }
}
 
int main()
{
    int q, n, *t;
    
    scanf("%d", &q);
    
    while( q > 0 )
    {
           scanf("%d", &n);
           
           t = new int [n];
           
           wczytaj(t,n);
           
           g(t,n);
           
           delete [] t;
           
           --q;
    }
    
    //system("pause");
    return 0;
}
 
