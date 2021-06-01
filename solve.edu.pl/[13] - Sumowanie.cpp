#include<cstdio> // 100 pkt
using namespace std;
int main()
{
    long long w=0;
    int n,i,a;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
             scanf("%d", &a);
             w+=a;
    }
    printf("%lld\n", w);
    return 0;
}
