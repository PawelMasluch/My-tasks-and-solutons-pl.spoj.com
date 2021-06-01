#include<cstdio> // AC


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define FORD(i,b,a) for(LL i=b; i>=a; --i)


LL t[11] = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1 };


LL f(LL a)
{
	LL S = 0;
	
	FORD(i,10,0)
	{
		S += t[i] * ( a % 10 );
		
		a /= 10;
	}
	
	if( S <= 0 ) // liczba "a" niepoprawna
	{
		return 0;
	}
	
	if( S % 10 == 0 ) // liczba "a" poprawna
	{
		return 1;
	}
	
	return 0; // liczba "a" niepoprawna
}


void g(LL a)
{
	if( f( a ) == 1 ) // liczba "a" jest poprawna
	{
		printf( "D\n" );
	}
	else
	{
		printf( "N\n" );
	}
}


int main()
{
	LL q, a;
	
	scanf( "%lld", &q );
	
	REP(i,1,q)
	{
		scanf( "%lld", &a );
		
		g( a );
	}
	
	return 0;
}
