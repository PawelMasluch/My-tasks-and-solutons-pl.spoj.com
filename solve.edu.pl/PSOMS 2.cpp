#include<iostream> // 93/100 pkt; rozwiazanie przeszlo wszystkie testy
#include<new>
#include<vector>


using namespace std;


typedef long long LL;


struct elem
{
	LL wyn;
	LL pref;
	LL suf;
	LL S;
};


vector <LL> V;

LL rozm = 0;


LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}


LL f(LL N)
{
	LL wyn = 1;
	
	while( wyn < N )
	{
		wyn <<= 1;
	}
	
	return wyn;
}


void inicjuj(elem &v, LL a) // inicjacja liscia drzewa
{
	v.wyn = max(0,a);
		
	v.pref = max(0,a);
		
	v.suf = max(0,a);
		
	v.S = a;
}


void aktualizuj(elem &w, elem u, elem v)
{
	w.S = u.S + v.S;
		
	w.wyn = max( max( u.wyn, v.wyn ), u.suf + v.pref );
		
	w.pref = max( u.pref, u.S + v.pref );
		
	w.suf = max( v.suf, v.S + u.suf );
}


void bazowe(LL v, LL lewy, LL prawy, LL a, LL b) //'v' jest numerem węzła w drzewie
{
	if ( lewy == a  &&  prawy == b )
	{
		V.push_back(v);
		++rozm;
		return;
	}

	LL sr = ( a + b ) / 2;
	
	if ( prawy <= sr )
	{
		bazowe( 2*v, lewy, prawy, a, sr );
	}
	else
	{
		if ( lewy > sr )
		{
			bazowe( (2*v)+1, lewy, prawy, sr+1, b );
		}
		else
		{
			bazowe( 2*v, lewy, sr, a, sr );
			bazowe( (2*v)+1, sr+1, prawy, sr+1, b );
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	char zn;
	
	elem *DP, pom;
	
	LL N, Q, i, r, A, B, a, temp;
	
	
	/*** Wczytanie danych i inicjacja drzewa ***/
	
	cin >> N;
	
	r = f(N);
	
	DP = new elem [2*r];
	
	for(i=0; i<=N-1; ++i)
	{
		cin >> a;	
		inicjuj( DP[r+i], a );
	}
	
	for(i=N; i<=r-1; ++i)
	{
		inicjuj( DP[r+i], 0 );
	}
	
	for(i=r-1; i>=1; --i)
	{
		aktualizuj( DP[i], DP[2*i], DP[2*i+1] );
	}
	
	
	/*** Obsługa operacji ***/
	
	cin >> Q;
	
	while( Q > 0 )
	{
		cin >> zn >> A >> B;
		
		if(zn == 'C')
		{
			--A;
			
			temp = r + A;
			
			inicjuj( DP[temp], B );
			
			temp >>= 1;
			
			while( temp > 0 )
			{
				aktualizuj( DP[temp], DP[2*temp], DP[2*temp+1] );
				temp >>= 1;
			}
		}
		else // zn == 'Q'
		{
			--A;
			--B;
			
			bazowe(1,A,B,0,r-1);
			
			pom = DP[ V[ 0 ] ];
			
			for(i=1; i<=rozm-1; ++i)
			{
				aktualizuj( pom, pom, DP[ V[ i ] ] );
			}
			
			cout << pom.wyn << endl;
			
			V.clear();
			
			rozm = 0;
		}
		
		--Q;
	}
	
	delete [] DP;
	
	return 0;
}
