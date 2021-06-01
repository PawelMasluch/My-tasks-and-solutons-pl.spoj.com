#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef pair < int, int > PII;

typedef vector < int > VI;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)

#define PB push_back

#define MP make_pair

#define ST first

#define ND second


const int MAX_N = 2000000, ZAKRES = 1420;


VI prime, exp;

PII d[MAX_N+1];

int czy[MAX_N+1], r = 0;


void sito()
{
	czy[0] = czy[1] = 0;
	
	d[0] = d[1] = MP( 1, 1 );
	
	REP(i,2,MAX_N,1)
	{
		czy[i] = 1;
		
		d[i] = MP( i, 1 );
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( czy[i] == 1 )
		{
			REP(j,i*i,MAX_N,i)
			{
				if( czy[j] == 1 )
				{
					czy[j] = 0;
					
					d[j].ST = i;
					
					d[j].ND = ( d[ j / i ].ST == i ) ? d[ j / i ].ND + 1 : 1 ;
				}
			}
		}
	}
	
	czy[0] = -1;
	
	REP(i,1,MAX_N,1)
	{
		if( czy[i] == 1 )
		{
			prime.PB( i );
			
			exp.PB( 0 );
			
			++r;
		}
		
		czy[i] += czy[ i - 1 ];
	}
}


int fun(int n, int p)
{
	int wyn = 0, temp = p;
	
	while( temp <= n )
	{
		wyn += ( n / temp );
		
		if( temp <= n / p )
		{
			temp *= p;
		}
		else
		{
			break;
		}
	}
	
	return wyn;
}


void rozloz(int n, int zm)
{
	REP(i,0,r-1,1)
	{
		exp[i] += fun( n, prime[i] ) * zm;
	}
}


int poteguj(int a, int b)
{
	int wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn *= a;
		}
		
		b >>= 1;
		
		if( b )
		{
			a *= a;
		}
	}
	
	return wyn;
}


void zmien(int x, int zm)
{
	int p, a;
	
	while( x > 1 )
	{
		p = d[x].ST;
		
		a = d[x].ND;
		
		exp[ czy[p] ] += a * zm;
		
		x /= poteguj( p, a );
	}
}


int mnoz_modulo(int a, int b, int p)
{
	int wyn = 0;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = ( wyn + a ) % p;
		}
		
		b >>= 1;
		
		a = ( 2 * a ) % p;
	}
	
	return wyn;
}


int fpm(int a, int b, int p)
{
	int wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = mnoz_modulo( wyn, a, p );
		}
		
		b >>= 1;
		
		a = mnoz_modulo( a, a, p );
	}
	
	return wyn;
}


int C(int n, int p)
{
	sito();
	
	rozloz( 2 * n, 1 );
	
	rozloz( n, -1 );
	
	rozloz( n, -1 );
	
	zmien( n + 1, -1 );
	
	int wyn = 1, temp;
	
	REP(i,0,r-1,1)
	{
		temp = fpm( prime[i], exp[i], p );
		
		wyn = mnoz_modulo( wyn, temp, p );
	}
	
	return wyn;
}


int main()
{
	int n, m;
	
	scanf( "%d %d", &n, &m );
	
	printf( "%d\n", C( n - 2, m ) );
	
	return 0;
}
