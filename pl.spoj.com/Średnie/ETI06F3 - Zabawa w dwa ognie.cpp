#include<cstdio> // 40 pkt; nie jestem pewien, czy zaliczylem wszystkie testy
#include<new>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main()
{
	vector < vector < int > > skladowe;
	
	vector < int > pom, rozm;
	
	stack < int > S;
	
	bool *odw;
	
	int n, i, j, **G, lss = 0, u, ile = 0, l;
	
	scanf("%d", &n);
	
	odw = new bool [n];
	
	G = new int *[n];
	
	for(i=0; i<=n-1; ++i)
	{
		odw[i] = false;
		
		G[i] = new int [n];
	}
	
	for(i=0; i<=n-1; ++i)
	{
		for(j=0; j<=n-1; ++j)
		{
			scanf( "%d", &G[i][j] );
		}
	}
	
	for(i=0; i<=n-1; ++i)
	{
		if( !odw[ i ] )
		{
			++lss;
			
			++ile;
			
			pom.push_back( i );
			
			S.push( i );
			
			odw[ i ] = true;
			
			while( !S.empty() )
			{
				u = S.top();
				
				S.pop();
				
				for(j=0; j<=n-1; ++j)
				{
					if( G[ u ][ j ] == 1 )
					{
						if( !odw[ j ] )
						{
							++ile;
							
							pom.push_back( j );
							
							odw[ j ] = true;
							
							S.push( j );
						}
					}
				}
			}
			
			skladowe.push_back( pom );
				
			pom.clear();
				
			rozm.push_back( ile );
			
			ile = 0;
		}
	}
	
	if( lss != 3 )
	{
		printf("NIE\n");
		return 0;
	}
	
	for(l=0; l<=lss-1; ++l)
	{
		for(i=0; i<=rozm[l]-1; ++i)
		{
			for(j=0; j<=rozm[l]-1; ++j)
			{
				if( G[ skladowe[ l ][ i ] ][ skladowe[ l ][ j ] ] == 0 )
				{	
					printf("NIE\n");
					return 0;
				}
			}
		}
	}
	
	printf("TAK ");
	
	sort( rozm.begin(), rozm.begin() + lss );
	
	for(i=0; i<=lss-1; ++i)
	{
		printf( "%d ", rozm[i] );
	}
	
	printf("\n");
	
	return 0;
}

