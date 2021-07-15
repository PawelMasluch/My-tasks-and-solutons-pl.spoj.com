#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
bool trojkatna(LL x)
{
	LL pocz = 1, kon = 50000, sr, pom;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		pom = sr * ( sr + 1 ) / 2;
		
		if( pom >= x )
		{
			if( pom == x )
			{
				return true;
			}
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return false;
}
 
 
bool czy(LL n)
{
	LL k = 1, pom;
	
	while( 1 )
	{
		pom = k * ( k + 1 ) / 2;
		
		if( pom < n )
		{
			if( trojkatna( n - pom ) == true )
			{
				return true;
			}
			
			++k;
		}
		else
		{
			return false;
		}
	}
}
 
 
void f(LL n)
{
	if( czy( n ) == true )
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n;
	
	cin >> n;
	
	f( n );
	
	return 0;
}
