#include<iostream> // 100 pkt
#include<new>
#include<queue>


#define REP(i,n) for(i=0; i<n; ++i)


using namespace std;


int min(int a, int b)
{
	return (a<b) ? a : b ;
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	queue < int > Q;
	
	char **T;
	
	bool **odw;
	
	int N, M, **DP, i, j, INF = 1000001, s, k, x[8] = { -2, -1, 1, 2, 2, 1, -1, -2 }, y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }, u, v, row, col, ROW, COL, wyn;
	
	cin >> N >> M;
	
	T = new char *[N];
	
	odw = new bool *[N];
	
	DP = new int *[N];
	
	REP(i,N)
	{
		odw[i] = new bool [M];
		
		T[i] = new char [M];
		
		DP[i] = new int [M];
		
		REP(j,M)
		{
			cin >> T[i][j];
			
			if( T[i][j] == 'S' )
			{
				s = i * M + j;
				
				DP[i][j] = 0;
				
				odw[i][j] = true;
				
				Q.push(s);
			}
			else
			{
				DP[i][j] = INF;
				
				odw[i][j] = false;
				
				if( T[i][j] == 'K' )
				{
					k = i * M + j;
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
		
		REP(i,8)
		{
			ROW = row + x[i];
			
			COL = col + y[i];
			
			v = ROW * M + COL;
			
			if( ROW >= 0  &&  ROW <= N - 1  &&  COL >= 0  &&  COL <= M - 1 )
			{
				if( T[ROW][COL] != '#' )
				{
					if( !odw[ROW][COL] )
					{
						odw[ROW][COL] = true;
						
						Q.push(v);
					}
					
					DP[ROW][COL] = min( DP[ROW][COL], 1 + DP[row][col] );
				}
			}
		}
	}
	
	wyn = DP[ k / M ][ k % M ];
	
	if( wyn == INF )
	{
		cout << "NIE\n";
	}
	else
	{
		cout << wyn << endl;
	}
	
	return 0;
}
