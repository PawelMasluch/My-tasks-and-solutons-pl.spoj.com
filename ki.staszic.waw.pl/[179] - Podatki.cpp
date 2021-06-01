#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 500, MAX_M = 500;


int T[MAX_N][MAX_M], pom[MAX_N], n, m;


int max(int a, int b)
{
	return (a>b) ? a : b ;
}


int PSOMS()
{
	int wyn = 0, temp = 0;
	
	REP(i,0,n-1)
	{
		if( temp > 0 )
		{
			temp += pom[i];
		}
		else
		{
			temp = pom[i];
		}
		
		wyn = max( wyn, temp );
	}
	
	return wyn;
}


int main()
{
	int temp, wyn = 0;
	
	scanf( "%d %d", &n, &m );
	
	REP(i,0,n-1)
	{
		REP(j,0,m-1)
		{
			scanf( "%d", &T[i][j] );
		}
	}
	
	REP(i,0,m-1)
	{
		REP(j,i,m-1) // ka?da para kolumn (i,j), gdzie i <= j
		{
			REP(k,0,n-1) // "dodaj?" j-t? kolumn?
			{
				pom[k] += T[k][j];
			}
			
			temp = PSOMS(); // znajduj? PSOMS tablicy "pom"
			
			wyn = max( wyn, temp );
		}
		
		REP(j,0,n-1) // zerowanie tablicy "pom"
		{
			pom[j] = 0;
		}
	}
	
	printf( "%d\n", wyn );
	
	return 0;
}
