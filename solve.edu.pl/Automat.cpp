#include<cstdio> // 100 pkt
#include<new>

using namespace std;

int main()
{
	int N, K, i, j, *A, *last, *DP, INF = 1000000009, UNDEF = -1;
	
	scanf("%d%d", &N, &K);
	
	DP = new int [K+1];
	
	last = new int [K+1];
	
	for(i=0; i<=K; ++i)
	{
		DP[i] = INF;
		last[i] = UNDEF;
	}
	
	DP[0] = 0;
	
	A = new int [N];
	
	for(i=0; i<=N-1; ++i)
	{
		scanf("%d", &A[i]);
		
		for(j=0; j<=K-A[i]; ++j)
		{
			if( DP[ j ] + 1  <  DP[ j + A[ i ] ] )
			{
				DP[ j + A[ i ] ] = DP[ j ] + 1;
				last[ j + A[ i ] ] = i;
			}
		}
	}
	
	if( DP[ K ] == INF )
	{
		printf("NIE\n");
	}
	else
	{
		printf("%d\n", DP[K]);
		
		while( last[K] != UNDEF )
		{
			printf("%d ", A[ last[ K ] ]);
			
			K -= A[ last[ K ] ];
		}
	}
	
	delete [] A;
	delete [] DP;
	delete [] last;
	
	return 0;
}
