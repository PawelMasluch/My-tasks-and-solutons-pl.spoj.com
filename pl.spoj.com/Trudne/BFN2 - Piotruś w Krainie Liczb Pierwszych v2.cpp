#include<cstdio> // 100 pkt
#include<new>
#include<vector>


using namespace std;


typedef long long LL;

typedef vector < LL > VLL;


#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)

#define PB push_back

#define D delete


VLL v;

LL r = 0;


LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}


LL bin1(LL n)
{
	LL pocz = 1, kon = n, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( sr * sr <= n )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}


void sito(LL n)
{
	LL *czy = new LL [n+1], zakres = bin1( n );
	
	czy[0] = czy[1] = 0;
	
	REP(i,2,n,1)
	{
		czy[i] = 1;
	}
	
	REP(i,2,zakres,1)
	{
		if( czy[i] == 1 )
		{
			REP(j,i*i,n,i)
			{
				czy[j] = 0;
			}
		}
	}
	
	REP(i,2,n,1)
	{
		if( czy[i] == 1 )
		{
			v.PB( i );
			
			++r;
		}
	}
	
	D [] czy;
}


LL bin2(LL n)
{
	LL pocz = 0, kon = r - 1, wyn = -1, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( v[ sr ] * v[ sr ] <= n )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}


int main()
{
	sito( 47000 );
	
	LL q, pocz, kon, *czy, ind;
	
	scanf( "%lld", &q );
	
	REP(l,1,q,1)
	{
		scanf( "%lld%lld", &pocz, &kon );
		
		ind = bin2( kon );
		
		czy = new LL [kon-pocz+1];
		
		REP(i,0,kon-pocz,1)
		{
			czy[i] = 1;
		}
		
		REP(i,0,ind,1)
		{
			REP(j,max( ( ( pocz + v[i] - 1 ) / v[i] ) * v[i], v[i] * v[i] ),kon,v[i])
			{
				czy[ j - pocz ] = 0;
			}
		}
		
		REP(i,0,kon-pocz,1)
		{
			if( czy[i] == 1 )
			{
				printf( "%lld\n", i + pocz );
			}
		}
		
		D [] czy;
	}
	
	return 0;
}
