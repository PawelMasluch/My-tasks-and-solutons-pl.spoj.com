#include<iostream> // AC
 
 
using namespace std;
 
 
int max(int a, int b)
{
	return (a>b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int a, b, c, wyn = 0;
	
	cin >> a >> b >> c;
	
	wyn = max( wyn, a + ( b + c ) );
	
	wyn = max( wyn, a + ( b * c ) );
	
	wyn = max( wyn, a * ( b + c ) );
	
	wyn = max( wyn, a * ( b * c ) );
	
	wyn = max( wyn, ( a + b ) * c );
	
	wyn = max( wyn, ( a * b ) + c );
	
	cout << wyn << endl;
	
	return 0;
}
