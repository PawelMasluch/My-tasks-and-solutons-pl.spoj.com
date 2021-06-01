#include<cstdio> // 100 pkt
#include<new>


#define REP(i,n) for(i=0; i<n; ++i)


using namespace std;


typedef long long LL;


LL min(LL a, LL b)
{
	return (a<b) ? a : b ;
}


LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}


int main()
{
	LL n, i, j, **DP, a, r, x, y, l, x1, y1, x2, y2, temp;
	
	scanf("%lld%lld", &n, &r);
	
	DP = new LL *[2*n];
	
	REP(i,2*n)
	{
		DP[i] = new LL [2*n];
		
		REP(j,2*n)
		{
			DP[i][j] = 0;
		}
	}
	
	REP(i,n)
	{
		REP(j,n)
		{
			scanf("%lld", &a);
			
			DP[ i + j + 1 ][ j - i + n ] += a;
		}
	}
	
	REP(i,2*n-1)
	{
		REP(j,2*n-1)
		{
			DP[ i + 1 ][ j + 1 ] += DP[i][ j + 1 ] + DP[ i + 1 ][j] - DP[i][j]; 
		}
	}
	
	while( r )
	{
		scanf("%lld%lld%lld", &x, &y, &l);
		
		
		/*** Ustalenie pola na obróconej planszy dla pola (x,y) ***/
		
		temp = x + y - 1;
		
		y = y - x + n;
		
		x = temp;
		
		
		/*** Ustalenie rogów prostok¹ta, którego suma elementów to wynik ***/
		
		x1 = max( 1, x - l );
		
		y1 = max( 1, y - l );
		
		x2 = min( 2 * n - 1, x + l );
		
		y2 = min( 2 * n - 1, y + l );
		
		
		/*** Obliczenie wyniku ze wzoru ***/
		
		printf( "%lld\n",  DP[x2][y2] - DP[ x1 - 1 ][y2] - DP[x2][ y1 - 1 ] + DP[ x1 - 1 ][ y1 - 1 ] );
		
		--r;
	}
	
	return 0;
}
