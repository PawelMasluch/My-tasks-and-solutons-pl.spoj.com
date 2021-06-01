#include<cstdio> // AC
#include<new>
//#include<iostream>

using namespace std;

void wczytaj(int *t, int n)
{
     int i;
     
     for(i=1; i<=n-2; ++i)
     {
          scanf("%d", &t[i]);
     }
}

bool f(int *t, int n, int d)
{
     int i, j;
     
     bool *odw = new bool [d+1];
     
     odw[0] = true;
     
     for(i=1; i<=d; ++i)
     {
          odw[i] = false;
     }
     
     for(j=1; j<=n-1; ++j)
     {
          for(i=0; i<j; ++i)
          {
               odw[ t[j] - t[i] ] = true;
          }
     }
     
     for(i=0; i<=d; ++i)
     {
          if( odw[i] == false )
          {
              delete [] odw;
              
              return false;
          }
     }
     
     delete [] odw;
     
     return true;
}

void g(int *t, int n, int d)
{
     if( f(t,n,d) == true )
     {
         printf("Tak\n");
     }
     else
     {
         printf("Nie\n");
     }
}

int main()
{
    int n, d, *t;
    
    while( scanf("%d%d", &d, &n ) != EOF )
    {
           t = new int [n+2];
           
           t[0] = 0;
           
           t[n+1] = d;
           
           wczytaj(t,n+2);
           
           g(t,n+2,d);
           
           delete [] t;
    }
    
    //system("pause");
    return 0;
}


