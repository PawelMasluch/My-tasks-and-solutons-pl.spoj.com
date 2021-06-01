#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)


const LL MAX_N = 1000, MAX_WYN = 1000000, ZAKRES = 1000;


bool czy[MAX_WYN+1];

LL S = 0, n, a;


void sito()
{
	REP(i,2,MAX_WYN,1)
	{
		czy[i] = true;
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( czy[i] == true )
		{
			REP(j,i*i,MAX_WYN,i)
			{
				czy[j] = false;
			}
		}
	}
}


LL bin(LL x)
{
	LL pocz = 1, kon = MAX_WYN, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( sr * sr * sr >= x )
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


int main()
{
	sito();
	
	scanf( "%lld", &n );
	
	REP(i,1,n,1)
	{
		scanf( "%lld", &a );
		
		S += a * a * a;
	}
	
	a = bin( S );
	
	printf( "%lld\n", a );
	
	if( czy[a] == true )
	{
		printf( "TAK\n" );
	}
	else
	{
		printf( "NIE\n" );
	}
	
	return 0;
}
