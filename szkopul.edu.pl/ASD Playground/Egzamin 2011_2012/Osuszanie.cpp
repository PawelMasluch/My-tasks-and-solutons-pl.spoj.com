#include<iostream> // 100 pkt
#include<queue>


using namespace std;


typedef pair < int, int > PII;

typedef priority_queue < PII > PQ_PII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define MP make_pair

#define ST first

#define ND second

#define T top

#define P push

#define p pop

#define E empty


const int MAX_N = 1000, MAX_M = 1000, MX = MAX_N * MAX_M, INF = 1000000000 + 199;


char T[MX];

bool odw[MX];

int n, m, A, B, d[MX], R, x[4] = { -1, 0, 0, 1 }, y[4] = { 0, -1, 1, 0 };


int id(int row, int col)
{
	return   row * m   +   col ;
}


int row(int id)
{
	return id / m ;
}


int col(int id)
{
	return id % m ;
}


bool ins(int row, int col)
{
	return ( 0 <= row  &&  row <= n - 1  &&  0 <= col  &&  col <= m - 1 ) ;
}


void wczytaj()
{
	cin >> n >> m;
	
	R = n * m;
	
	REP(i,0,R-1)
	{
		cin >> T[i];
			
		if( T[i] == 'A' )
		{
			A = i;
		}
		else
		{
			if( T[i] == 'B' )
			{
				B = i;
			}
		}
	}
}


void init()
{
	REP(i,0,R-1)
	{
		d[i] = INF;
	}
	
	d[A] = 0;
}


void oblicz()
{
	init();
	
	PQ_PII PQ;
	
	PQ.P( MP( -d[A], A ) );
	
	int u, v, w_uv, row_u, col_u, row_v, col_v;
	
	while( !PQ.E() )
	{
		u = PQ.T().ND;
		
		PQ.p();
		
		if( !odw[u] )
		{
			row_u = row( u );
			
			col_u = col( u );
			
			REP(i,0,3)
			{
				row_v = row_u + x[i];
				
				col_v = col_u + y[i];
				
				if( ins( row_v, col_v ) == true )
				{
					v = id( row_v, col_v );
				
					w_uv = ( T[v] == '#' ) ? 1 : 0 ;
					
					if( d[u] + w_uv < d[v] )
					{
						d[v] = d[u] + w_uv;
						
						PQ.P( MP( -d[v], v ) );
					}	
				}
			}
			
			odw[u] = true;
		}
	}
}


void wypisz()
{
	cout << d[B] << endl;
}


void solve()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	solve();
	
	return 0;	
}
