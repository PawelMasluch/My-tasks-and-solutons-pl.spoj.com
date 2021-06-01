#include<cstdio> // AC


using namespace std;


typedef long long LL;


#define REP(i,n) for(LL i=0; i<n; ++i)


LL f(LL x) // modu� liczby ca�kowitej
{
	return (x>=0) ? x : -x ;
}


LL r (LL a, LL p) // reszta z dzielenia dowolnej liczby ca�kowitej "a" przez niezerow� liczb� ca�kowit� "p"
{
	return ( a >= 0 )  ?  ( a - ( ( a / f(p) ) * f(p) ) )  :  ( a + ( ( ( f(a) + f(p) - 1 ) / f(p) ) * f(p) ) )  ;
}


int main()
{
	LL q, a, p;
	
	scanf( "%lld", &q );
	
	REP(i,q)
	{
		scanf( "%lld%lld", &a, &p );
		
		printf( "%lld\n", r( a, p ) );
	}
	
	return 0;
}
