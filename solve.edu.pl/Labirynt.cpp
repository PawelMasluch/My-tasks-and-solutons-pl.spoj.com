#include<iostream> // 100 pkt
#include<new>
#include<queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	
	char **T;
	
	bool **odw;
	
	queue < int > Q;
	
	int N, M, i, j, **DP, s, m, x[4] = { 0, 0, 1, -1 }, y[4] = { 1, -1, 0, 0 }, u, v, row, col, ROW, COL;
	
	cin >> N >> M;
	
	DP = new int *[N];
	
	T = new char *[N];
	
	odw = new bool *[N];
	
	for(i=0; i<=N-1; ++i)
	{
		T[i] = new char [M];
		
		DP[i] = new int [M];
		
		odw[i] = new bool [M];
		
		for(j=0; j<=M-1; ++j)
		{	
			cin >> T[i][j];
			
			if( T[i][j] == 'S' )
			{
				DP[i][j] = 0;
				
				s = i * M + j;
				
				Q.push(s);
				
				odw[i][j] = true;
			}
			else
			{
				DP[i][j] = 1000001;
					
				odw[i][j] = false;
				
				if( T[i][j] == 'M' )
				{
					m = i * M + j;
				}
			}
		}
	}
	
	while( !Q.empty() )
	{
		u = Q.front();
		
		Q.pop();
		
		row = u / M;
		
		col = u % M;
		
		for(i=0; i<=4-1; ++i)
		{
			ROW = row + x[i];
			
			COL = col + y[i];
			
			if( ROW <= N - 1  &&  ROW >= 0  &&  COL <= M - 1  &&  COL >= 0 )
			{
				if( T[ ROW ][ COL ] != '#' )
				{
					if( !odw[ ROW ][ COL ] )
					{
						odw[ ROW ][ COL ] = true;
						
						Q.push( ROW * M + COL );
					}
					
					DP[ ROW ][ COL ] = min( DP[ ROW ][ COL ], 1 + DP[ row ][ col ] );
				}
			}
		}
	}
	
	if( DP[ m / M ][ m % M ] == 1000001 )
	{
		cout << "NIE\n";
	}
	else
	{
		cout << DP[ m / M ][ m % M ] << endl;
	}
	
	return 0;
}

/*

test : 


wejœcie :

3 3

S#M
.#.
...


wyjœcie :

6

*/
