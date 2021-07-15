#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
LL G(LL x)
{
	return x * ( x - 1 ) / 2;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n, m, wyn1, wyn2, r, ile;
	
	cin >> n >> m;
	
	ile = n / m;
	
	r = n % m;
	
	wyn1 = r * G( ( n + m - 1 ) / m ) + ( m - r ) * G( ile );
	
	wyn2 = G( n - m + 1 );
	
	cout << wyn1 << " " << wyn2 << endl;
	
	return 0;
}
