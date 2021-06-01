#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 100000, MIN_WYN = 1, MAX_WYN = 1000000000; 


int N, C, x[MAX_N];


void wczytaj_dane()
{
	scanf( "%d %d", &N, &C );
	
	REP(i,0,N-1)
	{
		scanf( "%d", &x[i] );
	}
}


bool CzyDaSie(int d)
{
	int i = 1, wsp = x[ i - 1 ], ile = 1;
	
	while( i < N )
	{
		if( x[i] - wsp >= d )
		{
			++ile;
			
			if( ile >= C )
			{
				return true;
			}
			
			wsp = x[i];
		}
		
		++i;
	}
	
	return false;
}


int oblicz_wynik()
{
	sort( x, x + N );
	
	int pocz = MIN_WYN, kon = MAX_WYN, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( CzyDaSie( sr ) )
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


void zapytanie()
{
	wczytaj_dane();
	
	printf( "%d\n", oblicz_wynik() );
}


void obsluz_zapytania()
{
	int q;
	
	scanf( "%d", &q );
	
	while( q )
	{
		zapytanie();
		
		--q;
	}
}


int main()
{
	obsluz_zapytania();
	
	return 0;
}
