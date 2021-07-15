#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int MAX, MIN, n, a, wyn = 0;
	
	cin >> n >> a;
	
	MIN = MAX = a;
	
	--n;
	
	while( n )
	{
		cin >> a;
		
		if( a > MAX )
		{
			++wyn;
			
			MAX = a;
		}
		else
		{
			if( a < MIN )
			{
				++wyn;
			
				MIN = a;	
			}
		}
		
		--n;
	}
	
	cout << wyn << endl;
	
	return 0;
}
