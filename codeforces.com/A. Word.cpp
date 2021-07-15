#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	cin >> s;
	
	int n = s.size(), pom, duze = 0, male = 0;
	
	REP(i,0,n-1)
	{
		pom = (int)( s[i] );
		
		if( 65 <= pom  &&  pom <= 90 )
		{
			++duze;
		}
		else // 97 <= pom  &&  pom <= 122
		{
			++male;
		}
	}
	
	if( duze > male )
	{
		REP(i,0,n-1)
		{
			pom = (int)( s[i] );
		
			if( 97 <= pom  &&  pom <= 122 )
			{
				s[i] = (char)( pom - 32 );
			}	
		}
	}
	else
	{
		REP(i,0,n-1)
		{
			pom = (int)( s[i] );
		
			if( 65 <= pom  &&  pom <= 90 )
			{
				s[i] = (char)( pom + 32 );
			}	
		}
	}
	
	cout << s << endl;
	
	return 0;
}
