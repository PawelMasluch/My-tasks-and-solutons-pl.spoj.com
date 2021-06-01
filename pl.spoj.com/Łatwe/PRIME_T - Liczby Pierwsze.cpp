#include<cstdio> // AC
using namespace std;
int main()
{
    int t,n,i,j;
    bool tab[10001];
    tab[0]=false;
    tab[1]=false;
    for(i=2; i<=10000; i++)
    {
             tab[i]=true;
    }
    for(i=2; i<=10000; i++)
    {
             if(tab[i]==true)
             {
                             for(j=2*i; j<=10000; j+=i)
                             {
                                        tab[j]=false;
                             }
             }
    }
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
             scanf("%d", &n);
             if(tab[n]==true)
             {
                             printf("TAK\n");
             }
             else
             {
                 printf("NIE\n");
             }
    }
    return 0;
}

