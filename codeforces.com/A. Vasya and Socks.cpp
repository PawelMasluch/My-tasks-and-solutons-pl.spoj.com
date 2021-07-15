#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, m, wyn = 0;
	
	cin >> n >> m;
	
	while( n > 0 )
	{
		if( n >= m )
		{
			wyn += m;
			
			n -= m;
			
			++n;
		}
		else
		{
			wyn += n;
			
			n = 0;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
