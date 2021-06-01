#include<cstdio> // AC
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)

#define PB push_back


const int MAX_N = 1e7 + 1e5, ZAKRES = 3200;


VI v;

bool czy[MAX_N+1];

int q, n, r = 0;


void sito()
{
	czy[0] = czy[1] = false;
	
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
			v.PB( i );
			
			++r;
		}
	}
}


int bin1()
{
	int pocz = 0, kon = r - 1, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( v[ sr ] <= n )
		{
			wyn = v[ sr ];
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}


int bin2()
{
	int pocz = 0, kon = r - 1, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( v[ sr ] > n )
		{
			wyn = v[ sr ];
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return wyn;
}


int f()
{
	int tmp1 = bin1(), tmp2 = bin2();
	
	if( n - tmp1 <= tmp2 - n )
	{
		return tmp1;
	}
	else
	{
		return tmp2;
	}
}


int main()
{
	sito();
	
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d", &n );
		
		if( n == 1 )
		{
			printf( "2\n" );
		}
		else
		{
			printf( "%d\n", f() );	
		}
		
		--q;
	}
	
	return 0;
}
