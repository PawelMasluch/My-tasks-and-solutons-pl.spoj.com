#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX = 20000, INF = 1000099;


int n, k, ile[MAX+1]; // ile[i] - minimalna liczba nominalow potrzebna do wydania kwoty "i" 


void inicjuj()
{
	ile[0] = 0; // do wydania kwoty zerowej nie potrzeba zadnych nominalow
	
	REP(i,1,MAX)
	{
		ile[i] = INF; // czyli sie nie da (przynajmniej teraz) tej kwoty wydac
	}
}


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


void oblicz()
{
	scanf( "%d", &n );
	
	int a;
	
	REP(i,1,n)
	{
		scanf( "%d", &a );
		
		FORD(j,MAX,a)
		{
			ile[j] = min( ile[j], 1 + ile[ j - a ] ); // bez wzgledu na to, czy stara wartosc ile[j], czy wartosc ile[j-a] jest rowna INF, po wykonaniu tej instrukcji dostaniemy poprawna, nowa wartosc ile[j]
		}
	}
	
	scanf( "%d", &k );
	
	if( ile[k] != INF )
	{
		printf( "%d\n", ile[k] );
	}
	else
	{
		printf( "-1\n" );
	}
}


int main()
{
	inicjuj();
	
	oblicz();
	
	return 0;
}
