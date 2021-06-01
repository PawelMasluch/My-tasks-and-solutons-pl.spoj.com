#include<cstdio> // 100 pkt
#include<new>

using namespace std;

int main()
{
    int n, i, j, m = 0, *t;
    
    scanf("%d", &n);
    
    t = new int [n];
    
    for(i=0; i<=n-1; ++i)
    {
         scanf("%d", &t[i]);
         
         if( t[i] > m )
         {
             m = t[i];
         }
    }
    
    for(i=0; i<=m-1; ++i)
    {
         for(j=0; j<=n-1; ++j)
         {
                  if( t[j] >= m - i )
                  {
                      printf("#");
                  }
                  else
                  {
                      printf(".");
                  }
         }
         
         printf("\n");
    }
    
    delete [] t;
    
    return 0;
}
