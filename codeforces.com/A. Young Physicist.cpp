#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, x, y, z, Sx = 0, Sy = 0, Sz = 0;
	
	cin >> n;
	
	while( n )
	{
		cin >> x >> y >> z;
		
		Sx += x;
		
		Sy += y;
		
		Sz += z;
		
		--n;
	}
	
	if( Sx == 0  &&  Sy == 0  &&  Sz == 0 )
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	
	return 0;
}
