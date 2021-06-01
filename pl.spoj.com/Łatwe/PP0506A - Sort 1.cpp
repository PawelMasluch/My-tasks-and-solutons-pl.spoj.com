#include<iostream> // AC
#include<new>
#include<algorithm>
#include<string>


using namespace std;


struct elem
{
	string s;
	
	int a, b;
}; 


#define REP(i,n) for(int i=0; i<n; ++i)

#define D delete


void wczytaj(elem*t, int n)
{
	REP(i,n)
	{
		cin >> t[i].s >> t[i].a >> t[i].b;
	}
}


void wypisz(elem *t, int n)
{
	REP(i,n)
	{
		cout << t[i].s << " " << t[i].a << " " << t[i].b << endl;
	}
	
	cout << endl;
}


int d(const elem &A)
{
	return ( ( A.a * A.a ) + ( A.b * A.b ) );
}


bool f(const elem &A, const elem &B)
{
	return ( d( A ) < d( B ) );
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	elem *t;
	
	int q, n;
	
	cin >> q;
	
	REP(l,q)
	{
		cin >> n;
		
		t = new elem [n];
		
		wczytaj( t, n );
		
		sort( t, t + n, f );
		
		wypisz( t, n );
		
		D [] t;
	}
	
	return 0;
}
