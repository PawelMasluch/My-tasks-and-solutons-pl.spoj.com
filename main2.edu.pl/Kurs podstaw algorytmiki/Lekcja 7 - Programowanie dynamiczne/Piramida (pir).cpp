#include<iostream>
#include<new>

using namespace std;

typedef long long LL;

int main()
{
    LL n, k, i, *DP, j;
    
    cin >> n >> k;
    
    char *t = new char [n];
    
    for(i=0; i<=n-1; i++)
    {
             cin >> t[i];
    }
    
    DP = new LL [n];
    
    DP[0] = 1;
    
    for(i=1; i<=n-1; i++)
    {
             DP[i] = 0;
             
             if(t[i] == '1')
             {
                     for(j=1; j<=6; j++)
                     {
                              if(i-j >= 0)
                              {
                                     DP[i] = ( DP[i] + DP[i-j] ) % k;
                              }
                     }
             }
    }
    
    cout << DP[n-1] << endl;
    
    //system("pause");
    return 0;
}