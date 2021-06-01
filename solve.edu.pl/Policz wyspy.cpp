#include<cstdio> // 100 pkt
#include<queue>


using namespace std;


typedef queue < int > QI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define F front

#define p pop

#define P push

#define E empty


const int MAX_N = 100;


int nr_wyspy = 0, n, wyspa[MAX_N][MAX_N], T[MAX_N][MAX_N], x[4] = { 0, 0, -1, 1 }, y[4] = { -1, 1, 0, 0 };


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		REP(j,0,n-1)
		{
			scanf( "%d", &T[i][j] );
		}
	}
}


int id(int i, int j)
{
	return i*n + j;
}


int wiersz(int id)
{
	return id / n;
}


int kolumna(int id)
{
	return id % n;
}


bool ins(int i, int j)
{
	return ( 0 <= i  &&  i <= n - 1  &&  0 <= j  &&  j <= n - 1 );
}


void oblicz()
{
	QI Q;
	
	int tmp, row, col, w, k;
	
	REP(i,0,n-1)
	{
		REP(j,0,n-1)
		{
			if( T[i][j] == 1  &&  wyspa[i][j] == 0 )
			{
				Q.P( id(i,j) );
				
				wyspa[i][j] = ++nr_wyspy;
				
				while( !Q.E() )
				{
					tmp = Q.F();
					
					Q.p();
					
					row = wiersz( tmp );
					
					col = kolumna( tmp );
					
					REP(l,0,3)
					{
						w = row + x[l];
						
						k = col + y[l];
						
						if( ins( w, k ) == true )
						{
							if( T[w][k] == 1  &&  wyspa[w][k] == 0 )
							{
								wyspa[w][k] = nr_wyspy;
								
								Q.P( id(w,k) );
							}
						}
					}
				}
			}
		}
	}
}


void wypisz()
{
	printf( "%d\n", nr_wyspy );
}


int main()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
	
	return 0;
}
