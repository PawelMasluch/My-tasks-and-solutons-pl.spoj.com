#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
const LL p = 1000000007;
 
 
LL fpm(LL a, LL n)
{
	LL wyn = 1;
	
	while( n )
	{
		if( n & 1 )
		{
			wyn = ( wyn * a ) % p;
		}
		
		n >>= 1;
		
		a = ( a * a ) % p;
	}
	
	return wyn;
}
 
 
LL g(LL A, LL B, LL n, LL x)
{
	if( A == 1 )
	{
		return ( x + B * ( n % p ) ) % p;
	}
	
	LL pom = fpm( A, n );
	
	LL wyn = ( pom * x ) % p;
	
	wyn = ( wyn + ( ( ( pom + p - 1 ) * fpm( A - 1, p - 2 ) ) % p ) * B ) % p;
	
	return wyn;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL A, B, n, x;
	
	cin >> A >> B >> n >> x;
	
	cout << g( A, B, n, x ) << endl;
	
	return 0;
}
