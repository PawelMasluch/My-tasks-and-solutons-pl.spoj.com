#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	int n, wyn = 0, p, q;
	
	cin >> n;
	
	while( n )
	{
		cin >> p >> q;
		
		if( q >= p + 2 )
		{
			++wyn;
		}
		
		--n;
	}
	
	cout << wyn << endl;
	
	return 0;
}
