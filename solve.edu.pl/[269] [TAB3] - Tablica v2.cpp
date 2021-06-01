#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef long long LL;

typedef vector < LL > VLL;


#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)

#define PB push_back


const LL MAX_N = 2e5, ZAKRES = 450, p = 1e9 + 7;


VLL prime, exp;

bool czy[MAX_N+1];

LL r = 0, N, M;


void sito()
{
	czy[0] = czy[1] = false; // 0 oraz 1 nie są pierwsze
	
	REP(i,2,MAX_N,1)
	{
		czy[i] = true;
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( czy[i] == true )
		{
			REP(j,i*i,MAX_N,i)
			{
				czy[j] = false;
			}
		}
	}
	
	REP(i,2,MAX_N,1)
	{
		if( czy[i] == true )
		{
			prime.PB( i );
			
			exp.PB( 0 );
			
			++r;
		}
	}
}


LL pom(LL n, LL x, LL zm)
{
	LL wyn = 0, tmp = x;
	
	while( tmp <= n )
	{
		wyn += ( n / tmp );
		
		tmp *= x;
	}
	
	return wyn * zm;
}


LL fpm(LL a, LL b)
{
	LL wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = ( wyn * a ) % p;
		}
		
		b >>= 1;
		
		a = ( a * a ) % p;
	}
	
	return wyn;
}


LL f(LL n, LL k)
{
	LL wyn = 1;
	
	REP(i,0,r-1,1)
	{
		exp[i] += pom( n, prime[i], 1 );
		
		exp[i] += pom( k, prime[i], -1 );
		
		exp[i] += pom( n - k, prime[i], -1 );
		
		wyn = ( wyn * fpm( prime[i], exp[i] ) ) % p;
	}
	
	return wyn;
}


int main()
{
	sito();
	
	scanf( "%lld %lld", &N, &M );
	
	printf( "%lld\n", f( M + N - 2, N - 1 ) );
	
	return 0;
}
