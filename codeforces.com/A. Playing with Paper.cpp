#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL a, b, wyn = 0, temp;
	
	cin >> a >> b;
	
	while( b )
	{
		if( a > b )
		{
			temp = a;
			
			a = b;
			
			b = temp;
		}
		
		wyn += ( b / a );
		
		b %= a;
	}
	
	cout << wyn << endl;
	
	return 0;
}
