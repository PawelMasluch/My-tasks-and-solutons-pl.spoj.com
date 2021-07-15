#include<iostream> // AC
#include<new>
#include<algorithm>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int min(int a, int b)
{
	return (a<b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, m, *t, wyn = 1090709;
	
	cin >> n >> m;
	
	t = new int [m];
	
	REP(i,0,m-1)
	{
		cin >> t[i];
	}
	
	sort( t, t + m );
	
	REP(i,n-1,m-1)
	{
		wyn = min( wyn, t[i] - t[ i - n + 1 ] );
	}
	
	cout << wyn << endl;
	
	return 0;
}
