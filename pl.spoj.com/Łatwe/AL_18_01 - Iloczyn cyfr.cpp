#include<cstdio> // AC
#include<stack>

using namespace std;

typedef long long LL;

LL min(LL a, LL b)
{
          return (a<b) ? a : b ;
}

void f(LL n)
{
     if(n == 0)
     {
         printf("10\n");
         return;
     }
     
     if(n == 1)
     {
         printf("1\n");
         return;
     }
     
     LL ile2 = 0, ile3 = 0, ile5 = 0, ile7 = 0;
     
     while(n % 2 == 0)
     {
             n /= 2;
             ile2++;
     }
     
     while(n % 3 == 0)
     {
             n /= 3;
             ile3++;
     }
     
     while(n % 5 == 0)
     {
             n /= 5;
             ile5++;
     }
     
     while(n % 7 == 0)
     {
             n /= 7;
             ile7++;
     }
     
     if(n >= 11)
     {
         printf("NIE\n");
         return;
     }
     
     stack <LL> S;
     
     LL i, pom;
     
     for(i=1; 2*i<=ile3; i++) // 9
     {
          S.push(9);
     }
     ile3 %= 2;
     
     for(i=1; 3*i<=ile2; i++) // 8
     {
          S.push(8);
     }
     ile2 %= 3;
     
     for(i=1; i<=ile7; i++) // 7
     {
          S.push(7);
     }
     ile7 = 0;
     
     pom = min(ile2,ile3); // 6
     for(i=1; i<=pom; i++)
     {
          S.push(6);
     }
     ile2 -= pom;
     ile3 -= pom;
     
     for(i=1; i<=ile5; i++) // 5
     {
          S.push(5);
     }
     ile5 = 0;
     
     for(i=1; 2*i<=ile2; i++) // 4
     {
          S.push(4);
     }
     ile2 %= 2;
     
     for(i=1; i<=ile3; i++) // 3
     {
          S.push(3);
     }
     ile3 = 0;
     
     for(i=1; i<=ile2; i++) // 2
     {
          S.push(2);
     }
     ile2 = 0;
     
     
     while(!S.empty())
     {
                      printf("%lld", S.top());
                      S.pop();
     }
     
     printf("\n");
     
}

int main()
{
    LL t, i, n;
    
    scanf("%lld", &t);
    
    for(i=1; i<=t; i++)
    {
         scanf("%lld", &n);
         f(n);
    }
       
    return 0;
}
