#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int f(int x)
{
	return (x>=0) ? x : -x ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	char zn;
	
	int n, t[2] = { 1, -1 }, wyn = 0;
	
	cin >> n;
	
	REP(i,1,n)
	{
		cin >> zn;
		
		wyn += t[ (int)( zn ) - 48 ];
	}
	
	cout << f( wyn ) << endl;
	
	return 0;
}
