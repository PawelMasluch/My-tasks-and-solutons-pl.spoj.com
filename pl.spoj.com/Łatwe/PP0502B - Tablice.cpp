#include<iostream> // AC
#include<cstdio>
using namespace std;
int main()
{
    int t, n;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
            scanf("%d", &n);
            int tab[n];
            for(int j=0; j<n; j++)
            {
                    scanf("%d", &tab[j]);
            }
            for(int k=n-1; k>=0; k--)
            {
                    printf("%d ", tab[k]);
            }
            printf("\n");
    }
    return 0;
}
