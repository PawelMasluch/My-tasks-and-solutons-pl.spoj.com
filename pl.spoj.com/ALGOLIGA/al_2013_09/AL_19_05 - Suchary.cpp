#include<cstdio> // AC
#include<new>
#include<algorithm>
 
using namespace std;
 
typedef long long LL;
 
struct elem
{
       LL value;
       LL ind;
       LL kiedy;
};
 
bool f1(elem a, elem b)
{
     return (a.value > b.value);
}
 
bool f2(elem a, elem b)
{
     return (a.ind < b.ind);
}
 
int main()
{
    LL n, *k, *t, i, m, j;
    
    scanf("%lld", &n);
    
    k = new LL [n+1];  k[n] = -1;
    
    t = new LL [n+1];  t[n] = -1;
    
    for(i=0; i<=n-1; i++)
    {
                scanf("%lld%lld", &k[i], &t[i]);
    }
    
    scanf("%lld", &m);
    
    elem *K = new elem [m], *T = new elem [m];
    
    for(i=0; i<=m-1; i++)
    {
         scanf("%lld%lld", &K[i].value, &T[i].value);
         
         K[i].ind = i;
         
         T[i].ind = i;
    }
 
 
    
    sort(K,K+m,f1); // obliczenia dla Karola
    
    j = 0;
    i = 0;
    
    while(j<=m-1)
    {
                 while( K[j].value <= k[i])
                 {
                        i++;
                 }
                 
                 K[j].kiedy = i;
                 
                 j++;
    }
    
    
    sort(T,T+m,f1); // obliczenia dla Tadeusza
    
    j = 0;
    i = 0;
    
    while(j<=m-1)
    {
                 while( T[j].value <= t[i])
                 {
                        i++;
                 }
                 
                 T[j].kiedy = i;
                 
                 j++;
    }
    
    
    delete [] k;
    
    delete [] t;
    
    
    sort(K,K+m,f2);
    
    sort(T,T+m,f2);
    
    
    for(i=0; i<=m-1; i++)
    {
         if( K[i].kiedy == T[i].kiedy )
         {
             printf("Remis\n");
         }
         
         if( K[i].kiedy > T[i].kiedy )
         {
             printf("Karol\n");
         }
         
         if( K[i].kiedy < T[i].kiedy )
         {
             printf("Tadeusz\n");
         }
    }
    
    delete [] K;
    
    delete [] T;
    
    return 0;
} 
