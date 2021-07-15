#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
 
const LL MAX_N = 100000;
 
 
LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL *ile = new LL [MAX_N+1], n, a, *DP = new LL [MAX_N+1];
	
	REP(i,0,MAX_N)
	{
		ile[i] = 0;
	}
	
	cin >> n;
	
	REP(i,1,n)
	{
		cin >> a;
		
		++ile[a];
	}
	
	DP[0] = 0 * ile[0];
	
	DP[1] = 1 * ile[1];
	
	REP(i,2,MAX_N)
	{
		DP[i] = max( DP[ i - 1 ], i * ile[i] + DP[ i - 2 ] );
	}
	
	cout << DP[ MAX_N ] << endl;
	
	return 0;
}
