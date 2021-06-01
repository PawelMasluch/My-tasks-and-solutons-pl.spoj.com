#include<cstdio> // 100 pkt
#include<map>


using namespace std;


typedef long long LL;

typedef map < LL, LL > MLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


const LL MAX = 1e6;


MLL M;

LL DP[MAX+1], dz[6] = { 2, 3, 4, 5, 6, 7 }, N;


void preprocessing()
{
	DP[0] = 1;
	
	REP(i,1,MAX)
	{
		REP(j,0,5)
		{
			DP[i] += DP[ i / dz[j] ];
		}
	}
}


LL f(LL x)
{
	if( x <= MAX )
	{
		return DP[x];
	}
	
	if( !M.count( x ) )
	{
		M[x] = f( x / 2 ) + f( x / 3 ) + f( x / 4 ) + f( x / 5 ) + f( x / 6 ) + f( x / 7 );
	}
	
	return M[x];
}


int main()
{
	preprocessing();
	
	scanf( "%lld", &N );
	
	printf( "%lld\n", f( N ) );
	
	return 0;
}
