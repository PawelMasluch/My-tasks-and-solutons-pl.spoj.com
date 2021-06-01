#include<iostream> // 100 pkt
#include<string>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 1000000, p = 1000000007, A = 26;


string s;

int n, DP[MAX_N+1], gdzie[A], tmp, ind, ile;


int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> s;
	
	n = s.size();
	
	s = '#' + s;
	
	DP[0] = 1;
	
	REP(i,1,n)
	{
		tmp = s[i] - 'a';
		
		ind = gdzie[ tmp ];
		
		ile = ( ( ind > 0 ) ? DP[ ind - 1 ] : 0 ) ;
		
		DP[i] = ( 2 * DP[ i - 1 ] ) % p;
		
		DP[i] = ( DP[i] + p - ile ) % p;
		
		gdzie[ tmp ] = i;
	}
	
	cout << DP[n] << endl;
	
	return 0;
}
