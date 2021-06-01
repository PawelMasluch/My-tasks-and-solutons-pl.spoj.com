#include<iostream>
#include<string>
#include<vector>
#include<queue>


using namespace std;


typedef long long LL;

typedef string str;

typedef pair < LL, LL > PLL; 

typedef vector < LL > VLL;

typedef vector < VLL > V_VLL;

typedef queue < PLL > Q_PLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define FORD(i,b,a) for(LL i=b; i>=a; --i)

#define MP make_pair

#define ST first

#define ND second

#define PB push_back

#define S size

#define C clear

#define F front

#define P push

#define p pop

#define E empty

#define L length 


const LL MAX_N = 100, MAX_R = 100000, PROBY = 3;


str W;

V_VLL G[MAX_N+1];

bool odw[MAX_N+1][MAX_R+1][PROBY];

LL n, m, R, F[MAX_R+1][PROBY], x[PROBY] = { 191, 211, 379 }, x_rev[PROBY], pow_x[MAX_R][PROBY], pow_x_rev[MAX_R][PROBY], p[PROBY] = { 1000000000 + 7, 1000000000 + 9, 1000000000 + 33 };


LL H(str &s, LL nr_testu)
{
	LL r = s.L(), wyn = s[ r - 1 ] % p[nr_testu];
	
	FORD(i,r-2,0)
	{
		wyn = ( wyn * x[nr_testu] + s[i] ) % p[nr_testu];
	}
	
	return wyn;
}


void wczytaj()
{
	cin >> n >> m;
	
	VLL V;
	
	str s;
	
	LL u, v;
	
	REP(i,1,m)
	{
		cin >> u >> v >> s;
		
		V.PB( v );
		
		V.PB( s.L() );
		
		cout << v << " " << s.L() << " ";
		
		REP(k,0,PROBY-1)
		{
			cout << H( s, k ) << " ";
			
			V.PB( H( s, k ) );
		}
		
		G[u].PB( V );
		
		V.C();
		
		cout << endl;
	}
	
	REP(v,1,n)
	{
		V.PB( v );
		
		V.PB( 0 );
		
		REP(k,0,PROBY-1)
		{
			V.PB( 0 );
		}
		
		G[0].PB( V );
		
		V.C();
	}
	
	cin >> W;
	
	R = W.L();
	
	W = "#" + W;
	
	cout << "\nR = " << R << endl;
}


LL fpm(LL a, LL b, LL MOD)
{
	LL wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = ( wyn * a ) % MOD;
		}
		
		a = ( a * a ) % MOD;
		
		b /= 2;
	}
	
	return wyn;
}


void odwrocone_x()
{
	cout << "tablica x_rev:\n";
	
	REP(nr_testu,0,PROBY-1)
	{
		x_rev[nr_testu] = fpm( x[nr_testu], p[nr_testu] - 2, p[nr_testu] );
		
		cout << x_rev[nr_testu] << endl;
	}
}


void potegi_x()
{
	REP(nr_testu,0,PROBY-1)
	{
		pow_x[0][nr_testu] = 1 % p[nr_testu];
		
		REP(i,1,R-1)
		{
			pow_x[i][nr_testu] = ( pow_x[i-1][nr_testu] * x[nr_testu] ) % p[nr_testu];
		}
	}
}


void odwrocone_potegi_x()
{
	REP(nr_testu,0,PROBY-1)
	{
		pow_x_rev[0][nr_testu] = 1 % p[nr_testu];
		
		REP(i,1,R-1)
		{
			pow_x_rev[i][nr_testu] = ( pow_x[i-1][nr_testu] * x_rev[nr_testu] ) % p[nr_testu];
		}
	}
}


void hasze_dla_wzorca()
{
	REP(nr_testu,0,PROBY-1)
	{
		F[0][nr_testu] = 0 % p[nr_testu];
	
		REP(i,1,R)
		{
			F[i][nr_testu] = ( F[ i - 1 ][nr_testu] + W[i] * pow_x[ i - 1 ][nr_testu] ) % p[nr_testu];
		}	
	}
}


void init()
{
	odwrocone_x();
	
	potegi_x();
	
	odwrocone_potegi_x();
	
	hasze_dla_wzorca();
}


/*void czysc()
{
	REP(nr_testu,0,PROBY-1)
	{
		REP(u,0,n)
		{
			odw[u][nr_testu] = false;
		}
	}
}*/


LL hash(int i, int j, int nr_testu)
{
	if( i > j )
	{
		return 0;
	}
	
	return ( ( F[j][nr_testu] - F[i-1][nr_testu] ) * pow_x_rev[j-i][nr_testu] ) % p[nr_testu];
}


bool BFS(int x, int nr_testu)
{
	//czysc();
	
	Q_PLL Q;
	
	Q.P( MP( x, 0 ) );
	
	odw[x][0][nr_testu] = true; // w ramach testu, wszystko inne na 'false'
	
	LL u, dl, r, v, d, h;
	
	while(!Q.E() )
	{
		u = Q.F().ST;    dl = Q.F().ND;
		
		Q.p();
		
		r = G[u].S();
		
		cout << "u = " << u << ", dl = " << dl << ", r = " << r << ":\n";
		
		REP(i,0,r-1)
		{
			v = G[u][i][0];    d = G[u][i][1];    h = G[u][i][nr_testu+2];
			
			cout << "v = " << v << ", d = " << d << ", h = " << h; 
			
			if( dl + d <= R )
			{
				cout << ", hash = " << hash( dl + 1, dl + d, nr_testu );
				
				if( h == hash( dl + 1, dl + d, nr_testu ) )
				{
					cout << ", SUKCES";
					
					if( dl + d == R )
					{
						return true;
					}
					
					if( !odw[v][ dl + d ][nr_testu] )
					{
						Q.P( MP( v, dl + d ) );
						
						odw[v][ dl + d ][nr_testu] = true;
					}
				}
			}
			
			cout << endl;
		}
		
		cout << endl << endl;
	}
	
	/*REP(u,0,n-1)
	{
		if( odw[u][D] == true )
		{
			return true;
		}
	}*/
	
	return false;
}


void oblicz()
{
	bool wyn = false; 
	
	REP(k,0,PROBY-1)
	{
		wyn |= BFS( 0, k );
	}
	
	if( wyn == true )
	{
		printf( "TAK\n" );
	}
	else
	{
		printf( "NIE\n" );	
	}
}


void solve()
{
	wczytaj();
	
	init();
	
	oblicz();
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	solve();
	
	return 0;
}
