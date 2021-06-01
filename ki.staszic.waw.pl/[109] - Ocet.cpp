#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


struct elem
{
	LL S, ile, MIN, MAX;
};


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


const LL r = 16384, INF = 10001;


elem DP[2*r];


LL min(LL a, LL b)
{
	return (a<b) ? a : b ;
}


LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}


LL NWD(LL a, LL b)
{
	LL temp;
	
	while( b )
	{
		temp = a % b;
		
		a = b;
		
		b = temp;
	}
	
	return a;
}


void init()
{
	REP(i,1,2*r-1)
	{
		DP[i].ile = DP[i].S = 0;
		
		DP[i].MIN = INF;
		
		DP[i].MAX = -INF;
	}
}


void srednia()
{
	LL a = DP[1].S, b = DP[1].ile, pom = NWD( a, b );
	
	a /= pom;
	
	b /= pom;
	
	printf( "%lld/%lld\n", a, b );
}


void dodaj(LL x)
{
	LL temp = r + x;
	
	while( temp > 0 )
	{
		++DP[ temp ].ile;
		
		DP[ temp ].S += x;
		
		DP[ temp ].MIN = min( DP[ temp ].MIN, x );
		
		DP[ temp ].MAX = max( DP[ temp ].MAX, x );
		
		temp /= 2;
	}
}


void f(LL p)
{
	LL wyn = ( ( p == 0 ) ? DP[1].MIN : DP[1].MAX ), temp = wyn + r;
	
	printf( "%lld\n", wyn );
	
	--DP[ temp ].ile;
		
	DP[ temp ].S -= wyn;
	
	if( DP[ temp ].ile == 0 )
	{
		DP[ temp ].MIN = INF;
		
		DP[ temp ].MAX = -INF;
	}
	
	temp /= 2;
	
	while( temp > 0 )
	{
		--DP[ temp ].ile;
		
		DP[ temp ].S -= wyn;
		
		DP[ temp ].MIN = min( DP[ 2 * temp ].MIN, DP[ 2 * temp + 1 ].MIN );
		
		DP[ temp ].MAX = max( DP[ 2 * temp ].MAX, DP[ 2 * temp + 1 ].MAX );
		
		temp /= 2;
	}
}


int main()
{
	init();
	
	LL q, oper, a;
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &oper );
		
		switch( oper )
		{
			case 0:
				
				srednia();
				
				break;
				
				
			case 1:
				
				scanf( "%lld", &a );
				
				dodaj( a );
				
				break;
				
				
			case 2:
				
				f( 0 );
				
				break;
				
				
			case 3:
				
				f( 1 );
				
				break;
		}
		
		--q;
	}
	
	return 0;
}
