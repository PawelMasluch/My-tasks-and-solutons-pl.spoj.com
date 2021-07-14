#include<cstdio> // AC
#include<vector>
 
 
using namespace std;
 
 
typedef pair < int, int > PII;
 
typedef vector < PII > VPII;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define PB push_back
 
#define S size
 
#define C clear
 
#define MP make_pair
 
#define ST first
 
#define ND second
 
 
const int MAX_N = 1e7;
 
 
VPII v;
 
 
int rozklad(int a)
{
	int tmp = a, ile = 0, x = 2;
	
	while( x * x <= a  &&  tmp > 1 )
	{
		while( tmp % x == 0 )
		{
			tmp /= x;
			
			++ile;
		}
		
		if( ile > 0 )
		{
			v.PB( MP( x, ile ) );
		}
		
		ile = 0;
		
		++x;
	}
	
	if( tmp > 1 )
	{
		v.PB( MP( tmp, 1 ) );
	}
}
 
 
int ile(int n, int p)
{
	int wyn = 0, tmp = p;
	
	while( n >= tmp )
	{
		wyn += ( n / tmp );
		
		if( n / p >= tmp )
		{
			tmp *= p;
		}
		else
		{
			break;
		}
	}
	
	return wyn;
}
 
 
int bin(int p, int exp)
{
	int pocz = 1, kon = MAX_N, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( ile( sr, p ) >= exp )
		{
			wyn = sr;
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return wyn;
}
 
 
int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}
 
 
int fun(int a)
{
	rozklad( a );
	
	int r = v.S(), wyn = 1, p, exp;
	
	REP(i,0,r-1)
	{
		p = v[i].ST;
		
		exp = v[i].ND;
		
		wyn = max( wyn, bin( p, exp ) );
	}
	
	v.C();
	
	return wyn;
}
 
 
int f(int a, int b)
{
	int ia = fun( a ), ib = fun( b );
	
	return ( ( ib > ia ) ? ib - ia : 0 ) ;
}
 
 
int main()
{
	int a, b;
	
	scanf( "%d %d", &a, &b );
	
	printf( "%d\n", f( a, b ) );
	
	return 0;
} 
