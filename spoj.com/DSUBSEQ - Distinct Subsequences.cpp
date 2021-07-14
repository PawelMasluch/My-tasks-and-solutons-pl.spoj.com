#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
const int MAX_N = 1e5, A = 26, p = 1e9 + 7;
 
 
string s;
 
int r, q, dp[MAX_N+1], last[A], ile, ind, gdzie;
 
 
void preprocessing()
{
	REP(i,0,A-1)
	{
		last[i] = -1;
	}
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	dp[0] = 1;
	
	cin >> q;
	
	while( q )
	{
		preprocessing();
		
		cin >> s;
		
		r = s.size();
		
		REP(i,1,r)
		{
			ind = s[ i - 1 ] - 'A'; // indeks aktualnej litery w tablicy "last"
			
			gdzie = last[ ind ]; // ostatnia pozycja w sA?owie aktualnie rozwaA1anej litery
			
			ile = ( gdzie == -1 ) ? 0 : dp[ gdzie ] ; // tyle odejmiemy od wyniku dla aktualnego prefiksu sA?owa
			
			dp[i] = ( ( ( 2 * dp[ i - 1 ] ) % p ) - ile + p ) % p ;
			
			last[ ind ] = i - 1; // teraz to jest ostatnia pozycja w sA?owie przed chwilÄ? rozwaA1onej litery
		}
		
		cout << dp[r] << endl;
		
		--q;
	}
	
	return 0;
}
