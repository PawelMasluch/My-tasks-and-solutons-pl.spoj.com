#include<cstdio> // 15 pkt; zaliczylem wszystkie testy

using namespace std;

int f(int a, int b)
{
    while(a!=b)
    {
               if(a>b)
               {
                      if(a % b == 0)
                      {
                           a = b;
                      } 
                      else
                      {
                          a %= b;
                      }
               }
               else
               {
                   if(b % a == 0)
                   {
                        b = a;
                   } 
                   else
                   {
                       b %= a;
                   }
               }
    }
    
    return 2*a;
}

int main()
{
    int t, a, b, i;
    
    scanf("%d", &t);
    
    for(i=1; i<=t; i++)
    {
         scanf("%d%d", &a, &b);
         printf("%d\n", f(a,b));
    }
    
    return 0;
}

