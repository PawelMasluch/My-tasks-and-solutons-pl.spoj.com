#include<cstdio> // 100 pkt
#include<queue>


using namespace std;


typedef long long LL;

typedef pair < LL, LL > PLL;

typedef priority_queue < PLL > PQ_PLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define MP make_pair

#define ST first

#define ND second

#define P push

#define p pop

#define T top

#define E empty


const LL MAX_X = 500, MAX_Y = 500, MAX_R = MAX_X * MAX_Y, INF = (LL)1000000199 * 1000000099;


bool odw[MAX_R];

LL X, Y, H, R, T[MAX_R], d[MAX_R];


void wczytaj()
{
	scanf( "%lld %lld %lld", &X, &Y, &H );
	
	R = X * Y;
	
	REP(i,0,R-1)
	{
		scanf( "%lld", &T[i] );
	}
}


void init()
{
	REP(i,0,R-1)
	{
		d[i] = INF;
	}
	
	d[0] = 0;
}


LL id(LL row, LL col)
{
	return row*Y + col;
}


LL row(LL id)
{
	return id / Y;
}


LL col(LL id)
{
	return id % Y;
}


bool ins(LL row, LL col)
{
	return ( 0 <= row  &&  row <= X - 1  &&  0 <= col  &&  col <= Y - 1 );
}


LL max(LL a, LL b)
{
	return ( a > b ) ? a : b ; 
}


LL abs(LL x)
{
	return ( x >= 0 ) ? x : -x ;
}


LL w(LL u, LL v)
{
	return 1 + max( 0, abs( T[u] - T[v] ) - H );
}


void oblicz()
{
	init();
	
	PQ_PLL PQ;
	
	PQ.P(   MP( -d[0], 0 )   );
	
	LL u, v, w_uv, row_u, col_u, row_v, col_v;
	
	while( !PQ.E() )
	{
		u = PQ.T().ND;
		
		PQ.p();
		
		if( !odw[ u ] )
		{
			row_u = row( u );    col_u = col( u );
			
			REP(x,-2,2)
			{
				REP(y,-2,2)
				{
					row_v = row_u + x;
					
					col_v = col_u + y;
					
					if( ins( row_v, col_v ) == true )
					{
						v = id( row_v, col_v );
						
						w_uv = w( u, v );
						
						if( d[u] + w_uv < d[v] )
						{
							d[v] = d[u] + w_uv;
							
							PQ.P(   MP( -d[v], v )   );
						}
					}
				}
			}
			
			odw[ u ] = true;
		}
	}
}


void wypisz()
{
	printf( "%lld\n", d[ R - 1 ] ); // id( X - 1, Y - 1 ) = R - 1
}


void solve()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
}


int main()
{
	solve();
	
	return 0;
}
