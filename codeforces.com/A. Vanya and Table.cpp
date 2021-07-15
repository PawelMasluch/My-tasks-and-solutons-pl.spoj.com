#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, x1, y1, x2, y2, wyn = 0;
	
	cin >> n;
	
	while( n )
	{
		cin >> x1 >> y1 >> x2 >> y2;
		
		wyn += ( x2 - x1 + 1 ) * ( y2 - y1 + 1 );
		
		--n;
	}
	
	cout << wyn << endl;
	
	return 0;
}
