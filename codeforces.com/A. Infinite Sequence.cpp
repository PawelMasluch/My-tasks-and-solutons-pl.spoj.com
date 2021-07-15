#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
LL f(LL x)
{
	return ( x >= 0 ) ? x : -x ;
}
 
 
LL g(LL a, LL b, LL c)
{
	if( c == 0 )
	{
		if( a == b )
		{
			return true;
		}
		
		return false;
	}
	
	if( ( b - a ) * c >= 0  &&  f( b - a ) % f( c ) == 0 )
	{
		return true;
	}
	
	return false;
}
 
 
void fun(LL a, LL b, LL c)
{
	if( g( a, b, c ) == true )
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
	
	LL a, b, c;
	
	cin >> a >> b >> c;
	
	fun( a, b, c );
	
	return 0;
}
