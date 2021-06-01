#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


LL n, t0 = 0, tk = 0, v0 = 0, vk = 0, a, t, s = 0;


LL f(LL x)
{
	return (x>=0) ? x : -x;
}


int main()
{
	scanf( "%lld", &n );
	
	while( n )
	{
		scanf( "%lld %lld", &a, &t );
		
		tk += t;
		
		vk += ( a * t );
		
		s += ( tk - t0 ) * ( ( a * ( tk + t0 ) ) + ( 2 * ( v0 - ( a * t0 ) ) ) );
		
		t0 = tk;
		
		v0 = vk;
		
		--n;
	}
	
	vk = f( vk );
	
	s = f( s );
	
	printf( "%lld.00 %lld", vk, s / 2 );
	
	if( s % 2 == 1 )
	{
		printf( ".50\n" );
	}
	else
	{
		printf( ".00\n" );
	}
	
	return 0;
}
