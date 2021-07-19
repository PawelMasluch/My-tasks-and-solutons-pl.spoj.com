#include<iostream> // do sprawdzenia
#include<new> // najkrótsza scie¿ka za pomoc¹ algorytmu BFS
#include<queue>

#define INF 1000000009

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	
	pair <int,int> pocz, kon, u;
	
	bool **odw;
	
	char **T;
	
	int n, m, i, j, **path, x[4] = {0, 0, 1, -1}, y[4] = {1, -1, 0, 0}, l, Z;
	
	cin >> Z;
	
	while( Z > 0 )
	{
		
			cin >> n >> m;
			
			path = new int *[n];
			
			T = new char *[n];
			
			odw = new bool *[n];
			
			for(i=0; i<=n-1; ++i)
			{
				path[i] = new int [m];
				
				T[i] = new char [m];
				
				odw[i] = new bool [m];
			}
			
			for(i=0; i<=n-1; ++i)
			{
				for(j=0; j<=m-1; ++j)
				{
					cin >> T[i][j];
					
					path[i][j] = INF;
					
					if( T[i][j] == '@' )
					{
						pocz = make_pair(i,j);
						
						path[i][j] = 0;
					}
					
					if( T[i][j] == '>' )
					{
						kon = make_pair(i,j);
					}
					
					odw[i][j] = false;
				}
			}
			
			queue < pair<int,int> > Q;
			
			Q.push(pocz);
			
			odw[ pocz.first ][ pocz.second ] = true;
			
			while( !Q.empty() )
			{
				u = Q.front();
				
				Q.pop();
				
				for(l=0; l<=3; ++l)
				{
					if( u.first - x[l] >= 0  &&  u.first - x[l] <= n - 1  &&  u.second - y[l] >= 0  &&  u.second - y[l] <= m - 1 ) // jesli pole istnieje
					{
						if( T[ u.first - x[l] ][ u.second - y[l] ] != '#' ) // jesli pole mnie obchodzi
						{
							if( odw[ u.first - x[l] ][ u.second - y[l] ] == false )
							{
								Q.push( make_pair( u.first - x[l], u.second - y[l] ) );
								
								odw[ u.first - x[l] ][ u.second - y[l] ] = true;
							}
							
							path[ u.first - x[l] ][ u.second - y[l] ] = min( path[ u.first - x[l] ][ u.second - y[l] ], 1 + path[ u.first ][ u.second ] );
						}
					}
				}
			}
			
			if( path[ kon.first ][ kon.second ] == 1000000009 )
			{
				cout << "NIE\n";
			}
			else
			{
				cout << path[ kon.first ][ kon.second ] << endl;
			}
			
			
			for(i=0; i<=n-1; ++i)
			{
				delete [] path[i];
				delete [] odw[i];
				delete [] T[i];
			}
			
			delete [] path;
			delete [] odw;
			delete [] T;
			
			
			--Z;
	}
	
	return 0;	
}
