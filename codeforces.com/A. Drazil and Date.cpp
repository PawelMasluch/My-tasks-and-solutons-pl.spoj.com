#include<iostream> // AC
 
 
using namespace std;
 
 
int f(int x)
{
	return (x>=0) ? x : -x ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int a, b, s, pom;
	
	cin >> a >> b >> s;
	
	pom = f( a ) + f( b );
	
	if( s >= pom  &&  s % 2 == pom % 2 )
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
	
	return 0;
}
