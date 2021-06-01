#include<iostream> // AC
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector <int> tab1;
    int d,n;
    scanf("%d", &d);
    for(int i=0; i<d; i++)
    {
            scanf("%d", &n);
            int tab[n];
            for(int j=0; j<n; j++)
            {
                    scanf("%d" ,&tab[j]);
            }
    sort(tab, tab+n);
    for(int y=0; y<n; y++)
    {
            tab1.push_back(tab[y]);
    }
    int max=tab1[n-1];
    int k=0, z=n-1;
    
    while(tab[z]==max)
    {
                      printf("%d ", tab1[z]);
                      k++;
                      z--;
    }
    
    
    /*for(int i=n-1; i>=0; i--)    // alternatywne (choæ wolniejsze) dla pêtli while
    {
            if(tab1[i]==max)
            {
                            printf("%d ", tab1[i]);
                            k++;
            }
    }*/
    
    
    for(int i=0; i<=n-k-1; i++)
    {
            printf("%d ", tab1[i]);
    }
    printf("\n");
    tab1.erase(tab1.begin(), tab1.begin()+n);
    }
    return 0;
}
