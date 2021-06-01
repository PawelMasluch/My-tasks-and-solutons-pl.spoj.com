#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef pair < int, int > PII;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)

#define MP make_pair

#define ST first

#define ND second


const int MAX_N = 1000000, p = 1000000009, MAX_ZAKRES = 1000;


PII d[MAX_N+1];

bool odw[MAX_N], czy[MAX_N+1];

int a[MAX_N], prime[MAX_N+1], n;


void odczyt()
{
	REP(i,0,n-1,1)
	{
		scanf( "%d", &a[i] );
		
		--a[i];
	}
}


int max(int a, int b)
{
	return (a>b) ? a : b ;
}


int bin()
{
	int pocz = 1, kon = MAX_ZAKRES, wyn, sr;
	
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
	REP(i,2,n,1)
	{
		czy[i] = true;
		
		d[i] = MP( i, 1 );
	}
	
	int zakres = bin();
	
	REP(i,2,zakres,1)
	{
		if( czy[i] == true )
		{
			REP(j,i*i,n,i)
			{
				if( czy[j] == true )
				{
					czy[j] = false;
					
					d[j].ST = i;
					
					d[j].ND = ( d[ j / i ].ST == i ) ? d[ j / i ].ND + 1 : 1 ;
				}
			}
		}
	}
}


int fast_power(int a, int b)
{
	int wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn *= a;
		}
		
		b /= 2;
		
		if( b )
		{
			a *= a;
		}
	}
	
	return wyn;
}


int mnoz_modulo(int a, int b)
{
	int wyn = 0;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = ( wyn + a ) % p;
		}
		
		b /= 2;
		
		a = ( 2 * a ) % p;
	}
	
	return wyn;
}


void rozloz(int x)
{
	int a, b;
	
	while( x > 1 )
	{
		a = d[x].ST;
		
		b = d[x].ND;
		
		prime[a] = max( prime[a], b );
		
		x /= fast_power( a, b );
	}
}


void f()
{
	scanf( "%d", &n );
	
	odczyt();
	
	sito();
	
	int wyn = 1, temp = 0, j;
	
	REP(i,0,n-1,1)
	{
		if( !odw[i] )
		{
			j = i;
			
			while( !odw[j] )
			{
				odw[j] = true;
				
				++temp;
				
				j = a[j];
			}
			
			rozloz( temp );
			
			temp = 0;
		}
	}
	
	REP(i,2,n,1)
	{
		if( czy[i] == true )
		{
			temp = fast_power( i, prime[i] );
			
			wyn = mnoz_modulo( wyn, temp );
		}
	}
	
	printf( "%d\n", wyn );
}


int main()
{
	f();
	
	return 0;
}
