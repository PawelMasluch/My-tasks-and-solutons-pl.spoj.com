#include<iostream> // AC
#include<new>
#include<vector>
#include<algorithm>
 
 
using namespace std;
 
 
typedef pair < int, int > PII;
 
typedef vector < PII > VPII;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define PB push_back
 
#define MP make_pair
 
#define ST first
 
#define ND second
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	VPII v1, v2;
	
	v1.PB( MP( 0, 0 ) );
	
	v2.PB( MP( 0, 0 ) );
	
	int n, r1 = 1, r2 = 1, a, b;
	
	cin >> n;
	
	REP(i,0,n-1)
	{
		cin >> a >> b;
		
		if( a > 0 )
		{
			v2.PB( MP( a, b ) );
			
			++r2;
		}
		else
		{
			v1.PB( MP( -a, b ) );
			
			++r1;
		}
	}
	
	sort( v1.begin(), v1.end() );
	
	sort( v2.begin(), v2.end() );
	
	REP(i,1,r1-1)
	{
		v1[i].ND += v1[ i - 1 ].ND;
	}
	
	REP(i,1,r2-1)
	{
		v2[i].ND += v2[ i - 1 ].ND;
	}
	
	if( r1 == r2 )
	{
		cout << v1[ r1 - 1 ].ND + v2[ r2 - 1 ].ND << endl;
	}
	else
	{
		if( r1 > r2 )
		{
			cout << v2[ r2 - 1 ].ND + v1[ r2 ].ND << endl;
		}
		else // r1 < r2
		{
			cout << v1[ r1 - 1 ].ND + v2[ r1 ].ND << endl;
		}
	}
	
	return 0;
}
