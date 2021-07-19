#include<cstdio> // 100 pkt

using namespace std;

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for(i=2; i*i<=n; i++)
    {
         if( n % i == 0 )
         {
             printf("zlozona\n");
             return 0;
         }
    }
    
    printf("pierwsza\n");
    return 0;
}
