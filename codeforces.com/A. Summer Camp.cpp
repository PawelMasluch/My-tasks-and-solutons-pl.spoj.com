#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define FORD(i,b,a) for(int i=b; i>=a; --i)
 
 
string s;
 
int n, t[3], r = 0;
 
 
void f(int x)
{
	while( x > 0 )
	{
		t[r] = x % 10;
		
		x /= 10;
		
		++r;
	}
	
	FORD(i,r-1,0)
	{
		s = s + (char)( 48 + t[i] );
	}
	
	r = 0;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	REP(i,1,370)
	{
		f( i );
	}
	
	cin >> n;
	
	cout << s[ n - 1 ] << endl;
	
	return 0;
}
