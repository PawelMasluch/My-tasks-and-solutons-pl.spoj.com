#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
 
const LL p = 1010101011, MAX = 999; // "MAX" oznacza, ile najwiÄ?cej gwiazdek moA1e byÄ? w rozwaA1anej liczbie
 
 
string s;
 
LL DP[MAX+1][3], t[3], c, q, a, r, R = 0, ile = 0;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> c;
	
	while( c )
	{
		cin >> a;
		
		++t[ a % 3 ];
		
		--c;
	}
	
	DP[0][0] = 1;
	
	REP(i,1,MAX)
	{
		REP(j,0,2)
		{
			REP(k,0,2)
			{
				DP[i][j] = ( DP[i][j] + DP[ i - 1 ][ ( j + 3 - k ) % 3 ] * t[k] ) % p;
			}
		}
	}
	
	cin >> q;
	
	while( q )
	{
		cin >> s;
		
		r = s.size();
		
		REP(i,0,r-1)
		{
			if( s[i] != '*' )
			{
				R += (LL)( s[i] );
			}
			else
			{
				++ile;
			}
		}
		
		R -= 48 * ( r - ile );
		
		R %= 3;
		
		cout << DP[ ile ][ ( 3 - R ) % 3 ] << endl;
		
		R = 0;  ile = 0;
		
		--q;
	}
	
	return 0;
} 
