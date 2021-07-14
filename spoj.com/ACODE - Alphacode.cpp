#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
const int MAX_N = 5e3;
 
 
string s;
 
LL DP[MAX_N+1];
 
int r, tmp;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	DP[0] = 1;
	
	cin >> s;
	
	while( s != "0" )
	{
		r = s.size();
		
		REP(i,1,r)
		{
			if( s[ i - 1 ] == '0' )
			{
				DP[i] = DP[ i - 2 ];
			}
			else
			{
				tmp = (int)( s[ i - 1 ] ) + 10 * (int)( s[ i - 2 ] ) - 528; 
				
				if( tmp <= 26  &&  s[ i - 2 ] > '0' )
				{
					DP[ i ] = DP[ i - 1 ] + DP[ i - 2 ];
				}
				else
				{
					DP[ i ] = DP[ i - 1 ]; 
				}
			}
		}
		
		cout << DP[r] << endl;
		
		cin >> s;
	}
	
	return 0;
} 
