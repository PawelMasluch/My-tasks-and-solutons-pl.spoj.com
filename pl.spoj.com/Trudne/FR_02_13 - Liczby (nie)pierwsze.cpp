#include<cstdio> // AC
#include<new>
#include<vector>


using namespace std;


typedef pair < int, int > PII;

typedef vector < int > VI;

typedef vector < PII > VPII;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)

#define FORD(i,b,a,skok) for(int i=b; i>=a; i-=skok)

#define PB push_back

#define MP make_pair

#define ST first

#define ND second

#define C clear


VI V;

int rozm = 0; 


int max(int a, int b)
{
	return (a>b) ? a : b ;
}


int f(int n)
{
	int wyn = 1;
	
	while( wyn < n )
	{
		wyn *= 2;
	}
	
	return wyn;
}


void bazowe(int v, int lewy, int prawy, int a, int b) //'v' jest numerem wêz³a w drzewie
{
	if ( lewy == a  &&  prawy == b )
	{
		V.PB( v );
		
		++rozm;
		
		return;
	}

	int sr = ( a + b ) / 2;
	
	if ( prawy <= sr )
	{
		bazowe( 2 * v, lewy, prawy, a, sr );
	}
	else
	{
		if ( lewy > sr )
		{
			bazowe( 2 * v + 1, lewy, prawy, sr + 1, b );
		}
		else
		{
			bazowe( 2 * v, lewy, sr, a, sr );
			
			bazowe( 2 * v + 1, sr + 1, prawy, sr + 1, b );
		}
	}
}


int query(int *DP, int r, int a, int b)
{
	bazowe( 1, a, b, 0, r - 1 );
	
	int wyn = DP[ V[0] ];
	
	REP(i,1,rozm-1,1)
	{
		wyn = max( wyn, DP[ V[i] ] );
	}
	
	V.C();
	
	rozm = 0;
	
	return wyn;
}


int main()
{
	VPII luka;
	
	int pocz = 4, kon, *DP, r, *ktory = new int [4000001], q, a, b, dl1, dl2, dl3, rluka = 0;
	
	bool *czy = new bool [4000001];
	
	REP(i,0,4000000,1)
	{
		czy[i] = true;
		
		ktory[i] = -1;
	}
	
	czy[0] = czy[1] = false; // na potrzeby zadania liczby 0 oraz 1 traktujê jako z³o¿one
	
	REP(i,2,2000,1)
	{
		if( czy[i] == true )
		{
			REP(j,i*i,4000000,i)
			{
				czy[j] = false;
			}
		}
	}
	
	REP(i,0,1,1)
	{
		ktory[i] = rluka; // czyli 0
	}
	
	luka.PB( MP( 0, 1 ) ); // rêcznie dorzucam ten przedzia³, by unikn¹æ warunku brzegowego (w pêtli poni¿ej zak³adam, ¿e po liczbie pierwszej nastêpuje liczba z³o¿ona, co nie dzia³a tylko dla pary liczb 2, 3)
	
	++rluka;
	
	REP(i,4,4000000,1)
	{
		if( czy[i] == false )
		{
			kon = i;
			
			ktory[i] = rluka;
		}
		else
		{
			luka.PB( MP( pocz, kon ) );
			
			++rluka;
			
			pocz = kon = i + 1;
		}
	}
	
	luka.PB( MP( pocz, kon ) ); // liczba 4000000 nie jest pierwsza, wiêc trzeba rêcznie do³o¿yæ dodatkowy przedzia³
	
	++rluka;
	
	r = f( rluka );
	
	DP = new int [2*r];
	
	REP(i,0,rluka-1,1)
	{
		DP[ r + i ] = luka[i].ND - luka[i].ST + 1;
	}
	
	REP(i,rluka,r-1,1)
	{
		DP[ r + i ] = 0;
	}
	
	FORD(i,r-1,1,1)
	{
		DP[i] = max( DP[ 2 * i ], DP[ 2 * i + 1 ] );
	}
	
	scanf( "%d", &q );
	
	REP(l,1,q,1)
	{
		scanf( "%d%d", &a, &b );
		
		while( czy[a] == true )
		{
			++a;
		}
		
		while( czy[b] == true )
		{
			--b;
		}
		
		if( a > b )
		{
			printf( "0\n" );
		}
		else
		{
			if( ktory[a] == ktory[b] )
			{
				printf( "%d\n", b - a + 1 );
			}
			else
			{
				dl1 = luka[ ktory[a] ].ND - a + 1;
				
				dl2 = b - luka[ ktory[b] ].ST + 1;
				
				dl3 = ( ktory[b] - ktory[a] >= 2 ) ? query( DP, r, ktory[a] + 1, ktory[b] - 1 ) : 0 ;
				
				printf( "%d\n", max( dl1, max( dl2, dl3 ) ) );
			}
		}
	}
	
	return 0;
}
