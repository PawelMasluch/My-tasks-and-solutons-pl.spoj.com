#include<cstdio> // 100 pkt
#include<vector>
#include<algorithm>


using namespace std;


typedef long long LL;

typedef vector < LL > VLL;


struct elem
{
	LL a, b, cost;
};


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define PB push_back

#define C clear


const LL INF = (LL)1000090709 * 1000000000, MAX_N = 1000000, MAX_M = 1000000, MAX_R = 1048576;


elem t[MAX_M];

VLL V;

LL DP[2*MAX_R], n, m, r, rozm = 0;


bool fun(const elem &p1, const elem &p2)
{
	return ( p1.b < p2.b );
}


LL f(LL n)
{
	LL wyn = 1;
	
	while( wyn < n )
	{
		wyn *= 2;
	}
	
	return wyn;
}


void aktualizuj(LL v)
{
	while( v > 0 )
	{
		DP[v] = min( DP[ 2 * v ], DP[ 2 * v + 1 ] );
		
		v /= 2;
	}
}


void bazowe(LL v, LL a, LL b, LL pocz, LL kon)
{
	if( a == pocz  &&  b == kon )
	{
		V.PB( v );
		
		++rozm;
		
		return;
	}
	
	LL sr = ( pocz + kon ) / 2;
	
	if( b <= sr )
	{
		bazowe( 2 * v, a, b, pocz, sr );
	}
	else
	{
		if( a > sr )
		{
			bazowe( 2 * v + 1, a, b, sr + 1, kon );
		}
		else
		{
			bazowe( 2 * v, a, sr, pocz, sr );
			
			bazowe( 2 * v + 1, sr + 1, b, sr + 1, kon );
		}
	}
}


LL query(LL a, LL b)
{
	bazowe( 1, a, b, 0, r - 1 );
	
	LL wyn = INF;
	
	REP(i,0,rozm-1)
	{
		wyn = min( wyn, DP[ V[i] ] );
	}
	
	V.C();
	
	rozm = 0;
	
	return wyn;
}


int main()
{
	scanf( "%lld %lld", &n, &m );
	
	
	// Zainicjowanie drzewa
	
	r = f( n + 1 );
	
	REP(i,1,2*r-1)
	{
		DP[i] = INF;
	}
	
	DP[r] = 0;
	
	aktualizuj( r / 2 );
	
	
	// Przedzia?y i ich koszty
	
	REP(i,0,m-1)
	{
		scanf( "%lld %lld %lld", &t[i].a, &t[i].b, &t[i].cost );
	}
	
	
	// Posortowanie po ko?cach przedzia??w
	
	sort( t, t + m, fun );
	
	
	// Wyznaczenie wyniku
	
	REP(i,0,m-1)
	{
		DP[ r + t[i].b ] = min( DP[ r + t[i].b ], query( t[i].a, t[i].b - 1 ) + t[i].cost );
		
		aktualizuj( ( r + t[i].b ) / 2 );
	}
	
	printf( "%lld\n", DP[ r + n ] );
	
	return 0;
}
