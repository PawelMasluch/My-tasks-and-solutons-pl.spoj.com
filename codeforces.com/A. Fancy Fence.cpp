#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
void g(int a)
{
	if( 360 % ( 180 - a ) == 0 )
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int q, a;
	
	cin >> q;
	
	REP(i,1,q)
	{
		cin >> a;
		
		g(a);
	}
	
	return 0;
}
