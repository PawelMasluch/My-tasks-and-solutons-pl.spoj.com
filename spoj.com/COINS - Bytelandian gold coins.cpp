#include<cstdio> // AC
#include<map>
 
 
using namespace std;
 
 
typedef long long LL;
 
typedef map < LL, LL > MLL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
 
const LL MAX = 1e6;
 
 
MLL M;
 
LL DP[MAX+1], n;
 
 
LL max(LL a, LL b)
{
	return ( a > b ) ? a : b ;
}
 
 
void preprocessing()
{
	/* PoniewaA1 globalnie zadeklarowana tablica liczb caA?kowitych 
	jest wypeA?niana zerami, to nie muszÄ? pisaÄ?, A1e DP[0] = 0 (zapis "DP[0] = 0" to warunek brzegowy 
	do naszego programowania dynamicznego ; A?atwo widaÄ?, A1e gdy mamy kwotÄ? zero, 
	to nic wiÄ?cej ponad zero nie uzyskamy) */
	
	REP(i,1,MAX)
	{
		DP[i] = max( i, DP[ i / 2 ] + DP[ i / 3 ] + DP[ i / 4 ] );
	}
}
 
 
LL f(LL x) // 0 <= x <= 10^9
{
	if( x <= MAX ) // jeA?li wynik policzyA?em w fazie preprocessingu
	{
		return DP[x];
	}
	
	if( !M.count( x ) ) // jeA?li nic nie przypisaA?em
	{
		M[x] = max( x, f( x / 2 ) + f( x / 3 ) + f( x / 4 ) );
	}
	
	return M[x];
}
 
 
int main()
{
	preprocessing();
	
	while( scanf( "%lld", &n ) != EOF )
	{
		printf( "%lld\n", f( n ) );
	}
	
	return 0;
} 
