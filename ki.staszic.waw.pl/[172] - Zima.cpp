#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 1000000;


int n, t[MAX_N], DP[MAX_N+1];


/*

DP[i] - najlepszy wynik dla rozpocz?cia pracy w dniu o numerze 'i' b?d? wi?kszym

*/


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
	}
}


void oblicz()
{
	DP[n] = 0;
	
	FORD(i,n-1,0)
	{
		DP[i] = 1 + DP[   min( n, i + t[i] + 1 )   ]; // tu licz? najlepszy wynik, gdy rozpoczynam prac? dok?adnie w dniu o numerze 'i'
		
		DP[i] = max( DP[i], DP[ i + 1 ] ); // tu licz? w?a?ciw? warto?? DP[i], czyli najlepszy wynik dla rozpocz?cia pracy w dniu o numerze 'i' b?d? wi?kszym
	}
	
	printf( "%d\n", DP[0] );
}


int main()
{
	wczytaj();
	
	oblicz();
	
	return 0;
}
