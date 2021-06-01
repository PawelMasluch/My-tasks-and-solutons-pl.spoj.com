#include<cstdio> // 100 pkt
#include<new>

using namespace std;

typedef long long LL;

LL max(LL a, LL b)
{
          return (a>b) ? a : b ;
}

int main()
{
    LL n, i, *t, *DP;
    
    scanf("%lld", &n);
    
    t = new LL [n];
    
    for(i=0; i<=n-1; i++)
    {
         scanf("%lld", &t[i]);
    }
    
    DP = new LL [n];
    
    DP[0] = max(0,t[0]);
    
    if(n>=2)
    {
            DP[1] = max(DP[0],t[1]);
    }
    
    for(i=2; i<=n-1; i++)
    {
         DP[i] = max(DP[i-1], DP[i-2] + t[i]);
    }
    
    printf("%lld\n", max(0, DP[n-1]));
    
    return 0;
}
