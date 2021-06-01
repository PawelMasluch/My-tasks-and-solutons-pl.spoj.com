#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 100000;


VI roznica[MAX_N];

int n, k, m, poz[MAX_N], repr[MAX_N], pocz[MAX_N], kon[MAX_N];


int Find(int x)
{
	if( repr[x] == x )
	{
		return x;
	}
	
	int wyn = Find( repr[x] );
	
	repr[x] = wyn;
	
	return wyn;
}


int ile(int x)
{
	return kon[ x ] - pocz[ x ] + 1;
}


int dl(int x)
{
	return poz[ kon[x] ] - poz[ pocz[x] ] + 1;
}


void Union(int x, int y)
{
	int rx = Find( x ), ry = Find( y );
	
	if( ile( rx ) >= ile( ry ) )
	{
		repr[ ry ] = rx;
		
		kon[ rx ] = kon[ ry ];	
	}
	else
	{
		repr[ rx ] = ry;
		
		pocz[ ry ] = pocz[ rx ];
	}
}


void wczytaj()
{
	scanf( "%d %d %d", &n, &k, &m );
	
	REP(i,0,m-1)
	{
		repr[i] = pocz[i] = kon[i] = i;
		
		scanf( "%d", &poz[i] );
	}
	
	REP(i,0,m-2)
	{
		roznica[  poz[ i + 1 ] - poz[i]  ].PB( i );
	}
}


void oblicz()
{
	int ile = m, r, x, wyn = 0;
	
	REP(i,1,n-1)
	{
		r = roznica[i].S();
		
		REP(j,0,r-1)
		{
			x = roznica[i][j];
			
			if( ile > k )
			{	
				Union( x, x + 1 );
				
				--ile;
			}
		}
	}
	
	REP(i,0,m-1)
	{
		if( Find( i ) == i )
		{
			wyn += dl( i );
		}
	}
	
	printf( "%d\n", wyn );
}


int main()
{
	wczytaj();
	
	oblicz();
	
	return 0;
}
