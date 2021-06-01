#include<cstdio> // 100 pkt
#include<new>

using namespace std;

int main()
{
	int N, X, i, j, S = 0, wyn = 1000001, pocz;
	
	scanf("%d%d", &N, &X);
	
	int *A = new int [N];
	
	for(i=0; i<=N-1; ++i)
	{
		scanf("%d", &A[i]);
	}
	
	i = j = 0;
	
	while( i <= N - 1 )
	{
		while( j <= N - 1 )
		{
			if( S < X )
			{
				S += A[j];
				
				++j;
			}
			else
			{
				break;
			}
		}
		
		if( S >= X )
		{
			if( wyn > j - i )
			{
				wyn = j - i;
				
				pocz = i + 1;
			}
		}
		
		S -= A[i];
		
		++i;
	}
	
	delete [] A;
	
	printf("%d %d\n", wyn, pocz);
	
	return 0;
}
