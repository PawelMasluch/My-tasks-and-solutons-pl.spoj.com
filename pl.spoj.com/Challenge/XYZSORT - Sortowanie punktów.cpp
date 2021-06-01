#include<cstdio> // AC
#include<new>
#include<algorithm>


using namespace std;


typedef pair < int, int > PII;

typedef pair < PII, int > PIII;


#define REP(i,n) for(int i=0; i<n; ++i)

#define ST first

#define ND second


void wczytaj(PIII *t, int n)
{
	REP(i,n)
	{
		scanf( "%d%d%d", &t[i].ST.ST, &t[i].ST.ND, &t[i].ND );
	}
}


void wypisz(PIII *t, int n)
{
	REP(i,n)
	{
		printf( "%d %d %d\n", t[i].ST.ST, t[i].ST.ND, t[i].ND );
	}
}


int main()
{
	PIII *t;
	
	int n;
	
	scanf( "%d", &n );
	
	t = new PIII [n];
	
	wczytaj( t, n );
	
	sort( t, t + n );
	
	wypisz( t, n );
	
	return 0;
}
