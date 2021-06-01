#include<cstdio> // 100 pkt
#include<vector>
#include<new>


#define REP(i,a,b,skok) for(i=a; i<=b; i+=skok)


using namespace std;


typedef long long LL;


LL bin(LL N)
{
	LL pocz = 1, kon = 54, sr, wyn;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( sr * sr <= N )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}


int main()
{
	vector < LL > v;
	
	LL N, K, i, j, r = 0, k, pom;
	
	scanf("%lld%lld", &N, &K);
	
	pom = bin( N );
	
	bool *czy_pierwsza = new bool [N+1];
	
	czy_pierwsza[0] = czy_pierwsza[1] = false;
	
	REP(i,2,N,1)
	{
		czy_pierwsza[i] = true;
	}
	
	REP(i,2,pom,1)
	{
		if( czy_pierwsza[i] )
		{
			REP(j,i*i,N,i)
			{
				czy_pierwsza[j] = false;
			}
		}
	}
	
	REP(i,0,N,1)
	{
		if( czy_pierwsza[i] )
		{
			v.push_back(i);
			
			++r;
		}
	}
	
	LL ***DP = new LL **[2];
	
	REP(j,0,1,1)
	{
		DP[j] = new LL *[N+1];
	}
	
	REP(j,0,1,1)
	{
		REP(i,0,N,1)
		{
			DP[j][i] = new LL [r+1];
			
			REP(k,0,r,1)
			{
				DP[j][i][k] = 0;
			}
		}
	}
	
	REP(k,0,r,1)
	{
		DP[0][0][k] = 1;
	}
	
	REP(j,1,K,1)
	{
		REP(i,0,N,1)
		{
			REP(k,0,r-1,1)
			{
				DP[ j & 1 ][i][ k + 1 ] = DP[ j & 1 ][i][k];
				
				if( v[k] <= i )
				{
					DP[ j & 1 ][i][ k + 1 ] += DP[ ( j - 1 ) & 1 ][ i - v[k] ][k];
				}
			}
		}
		
		REP(i,0,N,1)
		{
			REP(k,0,r,1)
			{
				DP[ ( j - 1 ) & 1 ][i][k] = 0;
			}
		}
	}
	
	printf("%lld\n", DP[ K & 1 ][N][r]);
	
	return 0;
}
