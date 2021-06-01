#include<cstdio> // AC
#include<new>
//#include<iostream>

using namespace std;

typedef long long LL;

int main()
{
    LL *DP = new LL [1000001], i, d, n;
    
    DP[1] = DP[2] = 1;
    
    DP[3] = 2;
    
    for(i=4; i<=1000000; ++i)
    {
             DP[i] = ( DP[i-1] + DP[i-2] + DP[i-3] ) % 1000000009;
    }
    
    scanf("%lld", &d);
    
    while( d > 0 )
    {
           scanf("%lld", &n);
           
           printf("%lld\n", DP[n]);
           
           --d;
    }
    
    delete [] DP;
    
    //system("pause");
    return 0;
} 

