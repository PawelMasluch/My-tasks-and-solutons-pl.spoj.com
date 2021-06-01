#include<cstdio> // 100 pkt
#include<new>
//#include<iostream>

using namespace std;

inline int min(int a, int b)
{
       return (a>b) ? b : a ;
}

int main()
{
    int n, m, i, j, **DP, *pref_n, *pref_m, smak_n, smak_m;
    
    scanf("%d%d", &n, &m);
    
    pref_n = new int [n+1];  pref_n[0] = 0;
    
    pref_m = new int [m+1];  pref_m[0] = 0;
    
    DP = new int *[n+1];
    
    for(i=0; i<=n; i++)
    {
         DP[i] = new int [m+1];
    }
    
    for(i=1; i<=n; i++)
    {
         scanf("%d", &smak_n);
         pref_n[i] = pref_n[i-1] + smak_n;
    }
    
    for(i=1; i<=m; i++)
    {
         scanf("%d", &smak_m);
         pref_m[i] = pref_m[i-1] + smak_m;
    }
    
    DP[0][0] = 0;
    
    for(j=1; j<=m; j++)
    {
             DP[0][j] = pref_m[j] - DP[0][j-1];
    }
    
    for(i=1; i<=n; i++)
    {
         DP[i][0] = pref_n[i] - DP[i-1][0];
    }
    
    for(i=1; i<=n; i++)
    {
         for(j=1; j<=m; j++)
         {
              DP[i][j] = pref_n[i] + pref_m[j] - min(DP[i-1][j],DP[i][j-1]);
         }
    }
    
    printf("%d\n", DP[n][m]);
    
    delete [] pref_n;
    delete [] pref_m;
    
    for(i=0; i<=n; i++)
    {
         delete [] DP[i];
    }
    
    delete [] DP;
    
    //system("pause");
    return 0;
}
