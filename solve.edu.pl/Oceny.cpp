#include<cstdio> // 100 pkt
using namespace std;
int main()
{
    int n,i;
    scanf("%d", &n);
    int t[n],pom[101];
    for(i=0; i<=100; i++)
    {
             pom[i]=0;
    }
    for(i=0; i<n; i++)
    {
             scanf("%d", &t[i]);
             pom[t[i]]++;
    }
    for(i=0; i<=100; i++)
    {
             if(pom[i]>0)
             {
                         printf("%d %d\n", i, pom[i]);
             }
    }
    //system("pause");
    return 0;
}