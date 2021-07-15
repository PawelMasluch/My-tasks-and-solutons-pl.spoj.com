#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
LL poteguj(LL a, LL b)
{
	LL wyn = 1;
	
	while( b > 0 )
	{
		if( b % 2 == 1 )
		{
			wyn *= a;
		}
		
		b /= 2;
		
		if( b > 0 )
		{
			a *= a;
		}
	}
	
	return wyn;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n;
	
	cin >> n;
	
	cout << poteguj( 2, n + 1 ) - 2 << endl;
	
	return 0;
}
