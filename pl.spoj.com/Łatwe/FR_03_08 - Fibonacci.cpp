#include<iostream> // AC
#include<new>
#include<string>


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


void inicjuj(LL *t, LL n, LL val)
{
	REP(i,0,n-1)
	{
		t[i] = val;
	}
}


void wyznacz(string &s, LL r, LL *t)
{
	REP(i,0,r-1)
	{
		++t[ (LL)( s[i] ) - 97 ];
	}
}


void oblicz(LL *wyn, LL *a, LL *b, LL n)
{
	REP(i,0,n-1)
	{
		wyn[i] = a[i] + b[i];
	}
}


void nadpisz(LL *a, LL *b, LL n)
{
	REP(i,0,n-1)
	{
		a[i] = b[i];
	}
}


void znajdz_wynik(LL *wyn, LL *a, LL *b, LL n, LL k)
{
	REP(i,3,k)
	{
		oblicz( wyn, a, b, n );
			
		nadpisz( a, b, n );
					
		nadpisz( b, wyn, n );
	}	
}


void wypisz(LL *t, LL n)
{
	REP(i,0,n-1)
	{
		cout << t[i] << " ";
	}
		
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	string s1, s2;
	
	LL q, r1, r2, *f1 = new LL [26], *f2 = new LL [26], *f = new LL [26], k;
	
	cin >> q;
	
	while( q )
	{
		inicjuj( f1, 26, 0 );
		
		inicjuj( f2, 26, 0 );
		
		cin >> s1 >> s2 >> k;
		
		r1 = s1.size();
		
		r2 = s2.size();
		
		wyznacz( s1, r1, f1 );
		
		wyznacz( s2, r2, f2 );
		
		znajdz_wynik( f, f1, f2, 26, k );
		
		if( k == 1 )
		{
			wypisz( f1, 26 );
		}
		else
		{
			if( k == 2 )
			{
				wypisz( f2, 26 );
			}
			else
			{
				wypisz( f, 26 );
			}
		}
		
		--q;
	}
	
	return 0;
}
