#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
bool duza_litera(char zn)
{
	int pom = (int)( zn );
	
	if( 65 <= pom  &&  pom <= 90 )
	{
		return true;
	}
	
	return false;
}
 
 
bool f(string &s)
{
	int n = s.size(), pom;
	
	REP(i,1,n-1)
	{
		pom = (int)( s[i] );
		
		if( duza_litera( s[i] ) == false )
		{
			return false;
		}
	}
	
	return true;
}
 
 
void zamien(string &s)
{
	int n = s.size(), pom;
	
	REP(i,0,n-1)
	{
		pom = (int)( s[i] );
		
		if( duza_litera( s[i] ) == true )
		{
			s[i] = (char)( pom + 32 );
		}
		else
		{
			s[i] = (char)( pom - 32 );
		}
	}
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	cin >> s;
	
	if( f( s ) == true )
	{
		zamien( s );
	}
	
	cout << s << endl;
	
	return 0;
}
