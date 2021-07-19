#include<iostream> // do sprawdzenia
#include<new>

using namespace std;

struct elem
{
	int wyn, pref, suf, dl;
};

int max(int a, int b)
{
	return (a>b) ? a : b ;
}

int f(int &n)
{
	int wyn = 1;
	
	while( wyn < n )
	{
		wyn <<= 1;
	}
	
	return wyn;
}

void inicjuj(elem &v, int a)
{
	v.wyn = 1 - a;
	
	v.pref = 1 - a;
	
	v.suf = 1 - a;
	
	v.dl = 1;
}

void aktualizuj(elem &w, elem &u, elem &v)
{
	w.wyn = max( max( u.wyn, v.wyn ), u.suf + v.pref );
	
	w.pref = u.pref;
	if( u.pref == u.dl )
	{
		w.pref += v.pref;
	}
	
	w.suf = v.suf;
	if( v.suf == v.dl )
	{
		w.suf += u.suf;
	}
	
	w.dl = u.dl + v.dl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	elem *DP;
	
	char zn;
	
	int n, k, r, i, a;
	
	cin >> n >> k;
	
	r = f(n);
	
	DP = new elem [2*r];
	
	for(i=0; i<=n-1; ++i)
	{
		cin >> zn;
		
		inicjuj( DP[ r + i ], (int)(zn) - 48 );
	}
	
	for(i=n; i<=r-1; ++i)
	{
		inicjuj( DP[r+i], 1 );
	}
	
	for(i=r-1; i>=1; --i)
	{
		aktualizuj( DP[i], DP[2*i], DP[2*i+1] );
	}
	
	while( k )
	{
		cin >> a;
		
		--a;
		
		i = r + a;
		
		inicjuj( DP[i], DP[i].wyn );
		
		i >>= 1;
		
		while( i )
		{
			aktualizuj( DP[i], DP[2*i], DP[2*i+1] );
			
			i >>= 1;
		}
		
		cout << DP[1].wyn << endl;
		
		--k;
	}
	
	delete [] DP;
	
	return 0;
}