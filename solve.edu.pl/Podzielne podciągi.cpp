#include<cstdio> // 100 pkt
#include<new>
using namespace std;
int main()
{
    long long wyn=0;
    int n,k,i,a,sum=0;
    scanf("%d%d", &n, &k);
    int *t = new int [k];
    t[0]=1;
    for(i=1; i<k; i++)
    {
             t[i]=0;
    }
    for(i=0; i<n; i++)
    {
             scanf("%d", &a);
             sum=(sum+a)%k;
             wyn+=t[sum];
             t[sum]++;
    }
    printf("%lld\n", wyn);
    delete [] t;
    return 0;
}
