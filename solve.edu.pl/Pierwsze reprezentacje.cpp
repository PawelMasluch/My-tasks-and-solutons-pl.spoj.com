#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef long long LL;


int main()
{
	vector < LL > v;
	
	LL N, K, i, j, r = 0, k;
	
	scanf("%lld%lld", &N, &K);
	
	bool czy_pierwsza[N+1];
	
	czy_pierwsza[0] = czy_pierwsza[1] = false;
	
	for(i=2; i<=N; ++i)
	{
		czy_pierwsza[i] = true;
	}
	
	for(i=2; i*i<=N; ++i)
	{
		if( czy_pierwsza[i] )
		{
			for(j=i*i; j<=N; j+=i)
			{
				czy_pierwsza[j] = false;
			}
		}
	}
	
	for(i=0; i<=N; ++i)
	{
		if( czy_pierwsza[i] )
		{
			v.push_back(i);
			
			++r;
		}
	}
	
	LL DP[2][N+1][r+1];
	
	for(i=0; i<=N; ++i)
	{
		for(j=0; j<=1; ++j)
		{
			for(k=0; k<=r; ++k)
			{
				DP[j][i][k] = 0;
			}
		}
	}
	
	for(k=0; k<=r; ++k)
	{
		DP[0][0][k] = 1;
	}
	
	for(j=1; j<=K; ++j)
	{
		for(i=0; i<=N; ++i)
		{
			for(k=0; k<=r-1; ++k)
			{
				if( v[k] <= i )
				{
					DP[ j % 2 ][i][ k + 1 ] = DP[ j % 2 ][i][k] + DP[ ( j - 1 ) % 2 ][ i - v[k] ][k];
				}
				else
				{
					DP[ j % 2 ][i][ k + 1 ] = DP[ j % 2 ][i][k];
				}
			}
		}
		
		for(i=0; i<=N; ++i)
		{
			for(k=0; k<=r; ++k)
			{
				DP[ ( j - 1 ) % 2 ][i][k] = 0;
			}
		}
	}
	
	printf("%lld\n", DP[ K % 2 ][N][r]);
	
	return 0;
}
