#include<iostream> // 95/100 pkt; zaliczylem wszystkie testy
#include<new>
#include<vector>


#define REP(i,a,b) for(i=a; i<=b; ++i)

#define FORD(i,b,a) for(i=b; i>=a; --i)


using namespace std;


typedef long long LL;


struct elem
{
	LL wyn, pref, suf, S;
};


vector < int > V;

int rozm = 0;


inline LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}


int f(int &N)
{
	int wyn = 1;
	
	while( wyn < N )
	{
		wyn <<= 1;
	}
	
	return wyn;
}


void inicjuj(elem &v, int a) // inicjacja liscia drzewa
{
	v.wyn = v.pref = v.suf = max( 0, a );
		
	v.S = a;
}


void aktualizuj(elem &w, elem u, elem &v)
{
	w.S = u.S + v.S;
		
	w.wyn = max( max( u.wyn, v.wyn ), u.suf + v.pref );
		
	w.pref = max( u.pref, u.S + v.pref );
		
	w.suf = max( v.suf, v.S + u.suf );
}


void bazowe(int v, int lewy, int prawy, int a, int b) //'v' jest numerem węzła w drzewie
{
	if ( lewy == a  &&  prawy == b )
	{
		V.push_back(v);
		
		++rozm;
		
		return;
	}

	int sr = ( a + b ) >> 1;
	
	if ( prawy <= sr )
	{
		bazowe( ( v << 1 ), lewy, prawy, a, sr );
	}
	else
	{
		if ( lewy > sr )
		{
			bazowe( ( v << 1 ) + 1, lewy, prawy, sr + 1, b );
		}
		else
		{
			bazowe( ( v << 1 ), lewy, sr, a, sr );
			
			bazowe( ( v << 1 ) + 1, sr + 1, prawy, sr + 1, b );
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	char zn;
	
	elem *DP, pom;
	
	int N, Q, i, r, A, B, a, temp;
	
	
	/*** Wczytanie danych i inicjacja drzewa ***/
	
	cin >> N;
	
	r = f(N);
	
	DP = new elem [2*r];
	
	REP(i,0,N-1)
	{
		cin >> a;	
		
		inicjuj( DP[ r + i ], a );
	}
	
	REP(i,N,r-1)
	{
		inicjuj( DP[ r + i ], 0 );
	}
	
	FORD(i,r-1,1)
	{
		aktualizuj( DP[ i ], DP[ ( i << 1 ) ], DP[ ( i << 1 ) + 1 ] );
	}
	
	
	/*** Obsługa operacji ***/
	
	cin >> Q;
	
	while( Q )
	{
		cin >> zn >> A >> B;
		
		if(zn == 'C')
		{
			temp = r + A - 1;
			
			inicjuj( DP[temp], B );
			
			temp >>= 1;
			
			while( temp )
			{
				aktualizuj( DP[ temp ], DP[ ( temp << 1 ) ], DP[ ( temp << 1 ) + 1 ] );
				
				temp >>= 1;
			}
		}
		else // zn == 'Q'
		{
			bazowe( 1, A - 1, B - 1, 0, r - 1 );
			
			pom = DP[ V[ 0 ] ];
			
			REP(i,1,rozm-1)
			{
				aktualizuj( pom, pom, DP[ V[ i ] ] );
			}
			
			cout << pom.wyn << endl;
			
			V.clear();
			
			rozm = 0;
		}
		
		--Q;
	}
	
	return 0;
}
