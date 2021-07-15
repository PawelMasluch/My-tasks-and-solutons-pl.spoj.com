#include<iostream>
#include<string> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
void zmien(string &s, int n)
{
	int pom;
	
	REP(i,0,n-1)
	{
		pom = (int)( s[i] );
		
		if( 65 <= pom  &&  pom <= 90 )
		{
			s[i] = (char)( pom + 32 );
		}
	}
}
 
 
int porownaj(string &a, string &b, int n)
{
	int pom1, pom2;
	
	REP(i,0,n-1)
	{
		pom1 = (int)( a[i] );
		
		pom2 = (int)( b[i] );
		
		if( pom1 < pom2 )
		{
			return -1;
		}
		
		if( pom2 < pom1 )
		{
			return 1;
		}
	}
	
	return 0;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n;
	
	string a, b;
	
	cin >> a >> b;
	
	n = a.size();
	
	zmien( a, n );
	
	zmien( b, n );
	
	cout << porownaj( a, b, n ) << endl;
	
	return 0;
}
