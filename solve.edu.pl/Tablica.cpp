#include<iostream> // 100 pkt
#include<new>


#define REP(i,a,b) for(i=a; i<=b; ++i)

#define FORD(i,b,a) for(i=b; i>=a; --i)


using namespace std;


void inicjuj(int *t, int n)
{
	int i;
	
	t[0] = 0;
	
	REP(i,1,n-1)
	{
		t[i] = -1;
	}
}


void wypelnij1(int n, char *t, int *pom)
{
	int num = 1, i;
	
	REP(i,1,n-1)
	{
		cin >> t[i];
		
		if( t[i] == '0' )
		{
			pom[ num ] = i;
			
			++num;
		}
	}
}


void wypelnij2(int n, char *t, int *pom)
{
	int i;
	
	pom[ n - 1 ] = 0;
	
	FORD(i,n-2,1)
	{
		pom[i] = pom[ i + 1 ];
		
		if( t[i] == '1' )
		{
			++pom[i];
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	char *a, *b;
	
	int n, m, i, *a_poz0, *b_poz0, *a_ile1, *b_ile1, wyn = 0;
	
	cin >> n >> m;
	
	a_poz0 = new int [n+1];  b_poz0 = new int [m+1];
	
	inicjuj( a_poz0, n + 1 );
	
	inicjuj( b_poz0, m + 1 );
	
	a = new char [n+1];  b = new char [m+1];
	
	wypelnij1( n + 1, a, a_poz0 );
	
	wypelnij1( m + 1, b, b_poz0 );
	
	a_ile1 = new int [n+2];  b_ile1 = new int [m+2]; // zwisa mi indeks 0
	
	wypelnij2( n + 2, a, a_ile1 );
	
	wypelnij2( m + 2, b, b_ile1 );
	
	REP(i,0,min(n,m)) // tyle zer
	{
		if( a_poz0[i] != -1  &&  b_poz0[i] != -1 )
		{
			wyn = max( wyn, i + min( a_ile1[ a_poz0[i] + 1 ], b_ile1[ b_poz0[i] + 1 ] ) ); 
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
