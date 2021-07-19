#include<iostream> // do sprawdzenia
#include<new>
#include<vector>


using namespace std;


typedef int LL;


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
			bazowe( 2*v+1, lewy, prawy, sr+1, b );
		}
		else
		{
			bazowe( 2*v, lewy, sr, a, sr );
			bazowe( 2*v+1, sr+1, prawy, sr+1, b );
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	LL n, i, r, a, b, *DP, m, pom;
	
	
	/*** Wczytanie danych i inicjacja drzewa ***/
	
	cin >> n >> m;
	
	r = f(n);
	
	DP = new LL [2*r];
	
	for(i=0; i<=n-1; ++i)
	{
		cin >> a;	
		DP[r+i] = a;
	}
	
	for(i=n; i<=r-1; ++i)
	{
		DP[r+i] = -1000001;
	}
	
	for(i=r-1; i>=1; --i)
	{
		DP[i] = max( DP[2*i], DP[2*i+1] );
	}
	
	
	/*** Obsługa operacji ***/
	
	while( m )
	{
		cin >> s >> a >> b;
		
		if( s == "UPDATE" )
		{
			--a;
			
			pom = r + a;
			
			DP[pom] =  b;
			
			pom >>= 1;
			
			while( pom > 0 )
			{
				DP[pom] = max( DP[2*pom], DP[2*pom+1] );
				pom >>= 1;
			}
		}
		else // s == "MAX"
		{
			--a;
			--b;
			
			bazowe(1,a,b,0,r-1);
			
			pom = DP[ V[ 0 ] ];
			
			for(i=1; i<=rozm-1; ++i)
			{
				pom = max( pom, DP[ V[ i ] ] );
			}
			
			cout << pom << endl;
			
			V.clear();
			
			rozm = 0;
		}
		
		--m;
	}
	
	delete [] DP;
	
	return 0;
}