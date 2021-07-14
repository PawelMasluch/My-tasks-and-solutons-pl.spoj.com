#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
#define D delete
 
 
const LL p = 1000000009;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	char zn;
	
	LL q, n, **DP;
	
	cin >> q;
	
	while( q )
	{
		cin >> n;
		
		DP = new LL *[n+1];
		
		REP(i,0,n)
		{
			DP[i] = new LL [n+1];
			
			REP(j,0,n)
			{
				DP[i][j] = 0;
			}
		}
		
		DP[1][0] = 1;
		
		REP(i,1,n)
		{
			REP(j,1,n)
			{
				cin >> zn;
				
				if( zn == '.' )
				{
					DP[i][j] = ( DP[ i - 1 ][j] + DP[i][ j - 1 ] ) % p;
				}
			}
		}
		
		cout << DP[n][n] << endl;
		
		REP(i,0,n)
		{
			D [] DP[i];
		}
		
		D [] DP;
		
		--q;
	}
		
	return 0;
} 
