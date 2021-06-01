#include<cstdio> // 72 pkt / 100 pkt ; TLE
#include<map>


using namespace std;


typedef map < int, int > MII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define LB lower_bound

#define UB upper_bound

#define ST first

#define ND second


MII M;

int n, q;


void wczytaj()
{
	scanf( "%d %d", &n, &q );
	
	int x;
	
	REP(i,1,n)
	{
		scanf( "%d", &x );
		
		++M[x];
	}
}


void query()
{
	int l, r, d, S_lr = 0, ile_d = 0, key, val;
	
	scanf( "%d %d %d", &l, &r, &d );
	
	MII::iterator it_left = M.LB( l ), it_right = M.UB( r ), akt = it_left, next = ++akt;    --akt;
	
	while( akt != it_right )
	{
		key = akt -> ST;
		
		val = akt -> ND;
		
		if( key == d )
		{
			ile_d = val;
		}
		
		S_lr += val;
		
		M.erase( akt );
		
		akt = next;
		
		++next;
	}
	
	printf( "%d\n", S_lr - ile_d );
	
	M[d] = S_lr;
}


void obsluz_zapytania()
{
	while( q ) 
	{
		query();
		
		--q;
	}
}


void solve()
{
	wczytaj();
	
	obsluz_zapytania();
}


int main()
{
	solve();
	
	return 0;
}
