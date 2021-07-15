#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
typedef long long LL;
 
 
bool f(LL n)
{
	LL ile = 0, pom;
	
	while( n )
	{
		pom = n % 10;
		
		if( pom == 4  ||  pom == 7 )
		{
			++ile;
		}
		
		n /= 10;
	}
	
	if( ile == 4  ||  ile == 7 )
	{
		return true;
	}
	
	return false;
}
 
 
void g(LL n)
{
	if( f( n ) == true )
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
	
	g( n );
	
	return 0;
}
