#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


typedef pair < int, int > PII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define MP make_pair

#define ST first

#define ND second


const int MAX_R = 2000000, UNDEF = -1;


PII t[MAX_R];

int n, l, R = 0, dlugosc[MAX_R], last[MAX_R], T[MAX_R];


void wczytaj()
{
	scanf( "%d %d", &n, &l );
	
	int ind = 0;
	
	REP(i,0,n-1)
	{
		REP(j,0,l-1)
		{
			scanf( "%d", &T[ ind ] );
			
			++ind;
		}
	}
}


void przeskaluj()
{
	int m = 0;
	
	REP(i,0,n-1)
	{
		REP(j,0,l-1)
		{
			t[ m ] = MP( T[m], m );
			
			++m;
		}
	}
	
	sort( t, t + m );
	
	T[ t[0].ND ] = R;
	
	REP(i,1,m-1)
	{
		if( t[i].ST > t[ i - 1 ].ST )
		{
			++R;
		}
		
		T[ t[i].ND ] = R;
	}
	
	++R;
}


void init()
{
	REP(i,0,R-1)
	{
		last[i] = UNDEF;
		
		dlugosc[i] = 0;
	}
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void oblicz()
{
	przeskaluj();
	
	init();
	
	int wyn = 0, x;
	
	REP(j,0,l-1) // kazda kolumna
	{
		REP(i,0,n-1) // kazdy wiersz
		{
			x = i*l + j;
			
			if( last[ T[x] ] < j )
			{
				if( last[ T[x] ] < j - 1 )
				{
					dlugosc[ T[x] ] = 1;
				}
				else
				{
					++dlugosc[ T[x] ];
				}
				
				wyn = max( wyn, dlugosc[ T[x] ] );
				
				last[ T[x] ] = j;
			}
		}
	}
	
	printf( "%d\n", wyn );
}


void solve()
{
	wczytaj();
	
	oblicz();
}


int main()
{
	solve();
	
	return 0;
}
