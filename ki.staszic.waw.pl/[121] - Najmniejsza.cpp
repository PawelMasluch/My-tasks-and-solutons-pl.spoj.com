#include<cstdio> // 100 pkt
//#include<iostream>
using namespace std;
int main()
{
    int t[1000001],i,n,a,k;
    for(i=1; i<=1000000; i++)
    {
             t[i]=0;
    }
    scanf("%d%d", &n, &k);
    for(i=0; i<n; i++)
    {
             scanf("%d", &a);
             t[a]++;
    }
    i=1;
    while(k>0)
    {
        k-=t[i];
        if(k<=0)
        {
                printf("%d\n", i);
                break;
        }      
        else
        {
            i++;
        }
    }
    //system("pause");
    return 0;
}
