#include<cstdio> // AC
#include<new>


using namespace std;


typedef long long LL;


#define REP(i,n) for(LL i=0; i<n; ++i)


LL wczytaj_i_oblicz(LL n, LL a)
{
	LL wyn = 0, pom;
	
	REP(i,n)
	{
		scanf( "%lld", &pom );
		
		if( pom == a )
		{
			++wyn;
		}
	}
	
	return wyn;
}


int main()
{
	LL n, a;
	
	while( scanf( "%lld", &a ) != EOF )
	{
		scanf( "%lld", &n );
		
		printf( "%lld\n", wczytaj_i_oblicz( n, a ) );
	}
	
	return 0;
}
