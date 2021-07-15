#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	char zn;
	
	int n, m, *row, *col, wyn = 0, **DP;
	
	cin >> n >> m;
	
	row = new int [n];
	
	col = new int [m];
	
	REP(i,0,n-1)
	{
		row[i] = 1; // na razie dobry wiersz
	}
	
	REP(j,0,m-1)
	{
		col[j] = 1; // na razie dobra kolumna
	}
	
	REP(i,0,n-1)
	{
		REP(j,0,m-1)
		{
			cin >> zn;
			
			if( zn == 'S' )
			{
				row[i] = 0; // z?y wiersz
				
				col[j] = 0; // z?a kolumna
			}
		}
	}
	
	DP = new int *[n];
	
	REP(i,0,n-1)
	{
		DP[i] = new int [m];
		
		REP(j,0,m-1)
		{
			DP[i][j] = 0; // pole (i,j) jest z?e
		}
	}
	
	REP(i,0,n-1)
	{
		if( row[i] == 1 )
		{
			REP(j,0,m-1)
			{
				DP[i][j] = 1; // pole (i,j) jest dobre
			}
		}
	}
	
	REP(j,0,m-1)
	{
		if( col[j] == 1 )
		{
			REP(i,0,n-1)
			{
				DP[i][j] = 1; // pole (i,j) jest dobre
			}
		}
	}
	
	REP(i,0,n-1)
	{
		REP(j,0,m-1)
		{
			wyn += DP[i][j];
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
