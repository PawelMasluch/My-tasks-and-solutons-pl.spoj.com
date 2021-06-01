#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef pair < int, int > PII;

typedef vector < int > VI;

typedef vector < PII > VPII;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)

#define PB push_back

#define MP make_pair

#define ST first

#define ND second


const int ILE = 1229, MAX = 10006, ZAKRES = 100, MAX_EXP = 50000;


VI prime;

VPII WYN;

PII d[MAX+1];

int n, m, czy[MAX+1], silnia[MAX+1][ILE], Q[ILE], r = 0, a, p;


void sito() // tablica "d", "prime" oraz "czy"
{
	czy[0] = czy[1] = 0;
	
	d[0] = d[1] = MP( 1, 1 );
	
	REP(i,2,MAX,1)
	{
		czy[i] = 1;
		
		d[i] = MP( i, 1 );
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( czy[i] == 1 )
		{
			REP(j,i*i,MAX,i)
			{
				if( czy[j] == 1 )
				{
					czy[j] = 0;
					
					d[j].ST = i;
					
					d[j].ND = ( d[ j / i ].ST == i ) ? d[ j / i ].ND + 1 : 1 ;
				}
			}
		}
	}
	
	czy[0] = -1;
	
	REP(i,1,MAX,1)
	{
		if( czy[i] == 1 )
		{
			prime.PB( i );
		}
		
		czy[i] += czy[ i - 1 ];
	}
}


int fast_power(int x, int y)
{
	int wyn = 1;
	
	while( y )
	{
		if( y & 1 )
		{
			wyn *= x;
		}
		
		y /= 2;
		
		if( y )
		{
			x *= x;
		}
	}
	
	return wyn;
}


void wypelnij() // tablica "silnia"
{
	int temp, a, b;
	
	REP(i,2,MAX,1)
	{
		REP(j,0,ILE-1,1)
		{
			silnia[i][j] = silnia[ i - 1 ][j];
		}
		
		temp = i;
		
		while( temp > 1 )
		{
			a = d[ temp ].ST;
			
			b = d[ temp ].ND;
			
			silnia[i][ czy[a] ] += b;
			
			temp /= fast_power( a, b );
		}
	}
}


void wstaw(int x, int zm)
{
	REP(j,0,ILE-1,1)
	{
		Q[j] += silnia[x][j] * zm;
	}
}


int niecalkowita()
{
	REP(i,0,ILE-1,1)
	{
		if( Q[i] < 0 )
		{
			return 1;
		}
	}
	
	return 0;
}


int fun(int x, int y) // czy ( (x!)^y ) | Q
{
	REP(i,0,ILE-1,1)
	{
		if( Q[i] < silnia[x][i] * y )
		{
			return 0;
		}
	}
	
	return 1;
}


int f1()
{
	int pocz = 2, kon = MAX, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( fun( sr, 1 ) == 1 )
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


int f2()
{
	int pocz = 1, kon = MAX_EXP, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( fun( p, sr ) == 1 )
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
	sito();
	
	wypelnij();
	
	scanf( "%d %d", &n, &m );
	
	REP(i,1,n,1)
	{
		scanf( "%d", &a );
		
		wstaw( a, 1 );
	}
	
	REP(i,1,m,1)
	{
		scanf( "%d", &a );
		
		wstaw( a, -1 );
	}
	
	if( niecalkowita() == 1 )
	{
		printf( "-1\n" );
		
		return 0;
	}
	
	while( Q[ czy[2] ] > 0 ) // dop?ki liczba Q dzieli si? przez (k!) dla k > 1
	{
		p = f1(); // max p : (p!) | Q
		
		a = f2(); // max a : ( (p!)^a ) | Q, przy ustalonym p
		
		WYN.PB( MP( p, a ) );
		
		++r;
		
		wstaw( p, -a );
	}
	
	printf( "%d\n", r );
	
	REP(i,0,r-1,1)
	{
		printf( "%d %d\n", WYN[i].ST, WYN[i].ND );
	}
	
	return 0;
}
