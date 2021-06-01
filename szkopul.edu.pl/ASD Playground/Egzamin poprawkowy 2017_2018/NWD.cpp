#include<iostream> // 100 pkt
#include<map>


using namespace std;


typedef map < int, int > MII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_R = 131072, UNDEF = -1;


MII M;

int n, DP[2*MAX_R], R, ostatni = UNDEF;


int f(int x)
{
	int wyn = 1;
	
	while( wyn < x )
	{
		wyn *= 2;
	}
	
	return wyn;
}


int NWD(int a, int b)
{
	int tmp;
	
	while( b )
	{
		tmp = a % b;
		
		a = b;
		
		b = tmp;
	}
	
	return a;
}


void wstaw(int x, int i)
{
	int v = R + i;
	
	DP[v] = x;
	
	v /= 2;
	
	while( v > 0 )
	{
		DP[v] = NWD( DP[2*v], DP[2*v+1] );
		
		v /= 2;
	}
}


void query()
{
	if( DP[1] == 0 )
	{
		cout << "1\n";
	}
	else
	{
		cout << DP[1] << endl;
	}
}


int val(int x)
{
	return DP[ R + x ];
}


void zdarzenie()
{
	char znak;
	
	int x, poz, value;
	
	cin >> znak >> x;
	
	if( znak == '+' )
	{
		wstaw( x, ++ostatni );
		
		M[x] = ostatni;
	}
	else // znak == '-'
	{
		poz = M[x];
		
		value = val( ostatni );
		
		wstaw( value, poz );
		
		M[ value ] = poz;
		
		wstaw( 0, ostatni );
		
		--ostatni;
	}
	
	query();
}


void obsluz_zdarzenia()
{
	cin >> n; // liczba zdarzen
	
	R = f( n );
	
	REP(i,0,n-1)
	{
		zdarzenie();
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	obsluz_zdarzenia();
	
	return 0;
}
