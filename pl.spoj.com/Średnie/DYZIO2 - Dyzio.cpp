#include<cstdio> // AC
#include<new>


using namespace std;


typedef long long LL;


#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)


const LL MAX_N = 1000000; // og?lnie MAX_N >= 1


LL *t = new LL [MAX_N+1];


LL bin(LL n) // n >= 1
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


void sito()
{
	t[0] = t[1] = 0;
	
	REP(i,2,MAX_N,1)
	{
		t[i] = 1;
	}
	
	LL zakres = bin( MAX_N );
	
	REP(i,2,zakres,1)
	{
		if( t[i] == 1 )
		{
			REP(j,i*i,MAX_N,i)
			{
				t[j] = 0;
			}
		}
	}
	
	REP(i,1,MAX_N,1)
	{
		t[i] += t[ i - 1 ];
	}
}


int main()
{
	sito();
	
	LL q, a, b;
	
	scanf( "%lld", &q );
	
	REP(i,1,q,1)
	{
		scanf( "%lld%lld", &a, &b );
		
		printf( "%lld\n", t[b] - t[ a - 1 ] );
	}
	
	return 0;
}

