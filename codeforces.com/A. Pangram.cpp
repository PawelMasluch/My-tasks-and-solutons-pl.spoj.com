#include<iostream> // AC
#include<new>
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, pom, *czy = new int [26];
	
	REP(i,0,25)
	{
		czy[i] = 0; // i-ta litera alfabetu nie wyst?pi?a
	}
	
	string s;
	
	cin >> n >> s;
	
	REP(i,0,n-1)
	{
		pom = (int)( s[i] );
		
		if( 65 <= pom  &&  pom <= 90 ) // je?li s[i] to du?a litera
		{
			pom += 32; // to zamie? j?
			
			s[i] = (char)( pom ); // na ma??
		}
		
		czy[ pom - 97 ] = 1; // ta litera wyst?pi?a
	}
	
	REP(i,0,25)
	{
		if( czy[i] == 0 )
		{
			cout << "NO\n";
			
			return 0;
		}
	}
	
	cout << "YES\n";
	
	return 0;
}
