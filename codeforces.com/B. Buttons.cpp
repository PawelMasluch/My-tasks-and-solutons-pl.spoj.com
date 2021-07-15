#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
 
LL f(LL n)
{
	return n + ( n * n * ( n - 1 ) / 2 ) - ( ( n - 1 ) * n * ( 2 * n - 1 ) / 6 );
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n, wyn;
	
	cin >> n;
	
	cout << f( n ) << endl;
	
	return 0;
}
