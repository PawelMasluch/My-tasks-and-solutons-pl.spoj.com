#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
 
const LL MAX_N = 100000, MAX_WYN = 2000000000;
 
 
LL n, k, a[MAX_N], b[MAX_N];
 
 
void wczytaj()
{
	cin >> n >> k;
	
	REP(i,0,n-1)
	{
		cin >> a[i];
	}
	
	REP(i,0,n-1)
	{
		cin >> b[i];
	}
}
 
 
LL max(LL a, LL b)
{
	return ( a > b ) ? a : b ;
}
 
 
bool czy(LL x)
{
	LL ile = 0;
	
	REP(i,0,n-1)
	{
		ile += max( 0, a[i] * x - b[i] );
		
		if( ile > k )
		{
			return false;
		}
	}
	
	return true;
}
 
 
LL oblicz()
{
	LL pocz = 0, kon = MAX_WYN, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( czy( sr ) == true )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	wczytaj();
	
	cout << oblicz() << endl;
	
	return 0;
}
