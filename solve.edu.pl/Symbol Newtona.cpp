#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef long long LL;

typedef vector < LL > VLL;


#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)

#define FORD(i,b,a,skok) for(LL i=b; i>=a; i-=skok)

#define PB push_back


const LL MAX_N = 100000, ZAKRES = 320, BASE = 1000000000;


bool czy[MAX_N+1];

VLL v, exp, wyn;

LL r = 0, R = 0;


void preprocessing()
{
	czy[0] = czy[1] = false;
	
	REP(i,2,MAX_N,1)
	{
		czy[i] = true;
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( czy[i] )
		{
			REP(j,i*i,MAX_N,i)
			{
				czy[j] = false;
			}
		}
	}
	
	REP(i,2,MAX_N,1)
	{
		if( czy[i] )
		{
			v.PB( i );
			
			exp.PB( 0 );
			
			++r;
		}
	}
}


LL f(LL x, LL p)
{
	LL wyn = 0, tmp = p;
	
	while( tmp <= x )
	{
		wyn += ( x / tmp );
		
		tmp *= p;
	}
	
	return wyn;
}


void rozloz(LL x, LL zm)
{
	REP(i,0,r-1,1)
	{
		exp[i] += f( x, v[i] ) * zm;
	}
}


LL fpm(LL a, LL b)
{
	LL wyn = 1;
	
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


void mnoz(LL czynnik)
{
	LL tmp, reszta = 0;
	
	REP(i,0,R-1,1)
	{
		tmp = wyn[i] * czynnik + reszta;
		
		wyn[i] = tmp % BASE;
		
		reszta = tmp / BASE;
	}
	
	if( reszta )
	{
		wyn.PB( reszta );
		
		++R;
	}
}


void oblicz()
{
	wyn.PB( 1 );
	
	++R;
	
	LL czynnik;
	
	REP(i,0,r-1,1)
	{
		if( exp[i] )
		{
			czynnik = fpm( v[i], exp[i] );
			
			mnoz( czynnik );
		}
	}
}


LL ile(LL x)
{
	if( !x )
	{
		return 1;
	}
	
	LL wyn = 0;
	
	while( x )
	{
		++wyn;
		
		x /= 10;
	}
	
	return wyn;
}


void wypisz()
{
	printf( "%lld", wyn[ R - 1 ] );
	
	LL tmp;
	
	FORD(i,R-2,0,1)
	{
		tmp = ile( wyn[i] );
		
		REP(j,1,9-tmp,1)
		{
			printf( "0" );
		}
		
		printf( "%lld", wyn[i] );
	}
	
	printf( "\n" );
}


void fun(LL N, LL K)
{
	rozloz( N, 1 );
	
	rozloz( K, -1 );
	
	rozloz( N - K, -1 );
	
	oblicz();
	
	wypisz();
}


int main()
{
	preprocessing();
	
	LL N, K;
	
	scanf( "%lld %lld", &N, &K );
	
	fun( N, K );
	
	return 0;
}
