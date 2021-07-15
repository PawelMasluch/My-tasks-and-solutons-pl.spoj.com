#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
LL min(LL a, LL b)
{
	return ( a < b ) ? a : b ;
}
 
 
LL NWD(LL a, LL b)
{
	LL tmp;
	
	while( b )
	{
		tmp = a % b;
		
		a = b;
		
		b = tmp;
	}
	
	return a;
}
 
 
LL NWW(LL a, LL b)
{
	return ( a / NWD( a, b ) ) * b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n, a, b, p, q;
	
	cin >> n >> a >> b >> p >> q;
	
	cout << ( n / a ) * p + ( n / b ) * q - ( n / ( NWW( a, b ) ) ) * min( p, q ) ;
	
	return 0;
}
