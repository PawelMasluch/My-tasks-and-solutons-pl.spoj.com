#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int a, b, wyn = 0;
	
	cin >> a >> b;
	
	while( a > 0 )
	{
		if( a >= b )
		{
			wyn += b;
			
			a -= b;
			
			++a;
		}
		else
		{
			wyn += a;
			
			a = 0;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
