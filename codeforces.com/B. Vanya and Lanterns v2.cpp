#include<iostream> // AC
#include<vector>
#include<algorithm>
 
 
using namespace std;
 
 
typedef long long LL;
 
typedef pair < LL, LL > PLL;
 
typedef vector < LL > VLL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
#define PB push_back
 
#define B begin
 
#define E end
 
#define S size
 
#define e erase
 
#define MP make_pair
 
#define ST first
 
#define ND second
 
 
const LL MAX_N = 1000;
 
 
PLL T[MAX_N+2];
 
VLL v;
 
LL r, n, l;
 
 
void wczytaj()
{
	cin >> n >> l;
	
	LL a;
	
	REP(i,1,n)
	{
		cin >> a;
		
		v.PB( a );
	}
}
 
 
void obliczenia_wstepne()
{
	sort( v.B(), v.E() );
	
	VLL :: iterator it = unique( v.B(), v.E() );
	
	v.e( it, v.E() );
	
	r = v.S();
	
	REP(i,0,r-1)
	{
		v[i] *= 2;
	}
	
	l *= 2;
}
 
 
bool czy(LL x)
{
	T[0] = MP( 0, 0 );
	
	REP(i,0,r-1)
	{
		T[ i + 1 ] = MP( v[i] - x, v[i] + x );
	}
	
	T[ r + 1 ] = MP( l, l );
	
	LL kon = T[0].ND;
	
	REP(i,1,r+1)
	{
		if( T[i].ST > kon )
		{
			return false;
		}
		
		kon = T[i].ND;
	}
	
	return true;
}
 
 
void oblicz()
{
	LL pocz = 1, kon = 2000000000, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( czy( sr ) == true )
		{
			wyn = sr;
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	cout << wyn / 2;
	
	if( wyn % 2 == 1 )
	{
		cout << ".5000000000";
	}
	else
	{
		cout << ".0000000000";
	}
	
	cout << "\n";
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	wczytaj();
	
	obliczenia_wstepne();
	
	oblicz();
	
	return 0;
}
