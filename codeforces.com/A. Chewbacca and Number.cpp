#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	cin >> s;
	
	int r = s.size(), pom = (int)( s[0] ) - 48;
	
	if( 5 <= pom  &&  pom <= 8 )
	{
		pom = 9 - pom;
		
		s[0] = (char)( pom + 48 );
	}
	
	REP(i,1,r-1)
	{
		pom = (int)( s[i] ) - 48;
	
		if( 5 <= pom  &&  pom <= 9 )
		{
			pom = 9 - pom;
			
			s[i] = (char)( pom + 48 );
		}
	}
	
	cout << s << endl;
	
	return 0;
}
