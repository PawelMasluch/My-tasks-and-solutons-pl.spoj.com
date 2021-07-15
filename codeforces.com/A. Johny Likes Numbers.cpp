#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, k;
	
	cin >> n >> k;
	
	cout << ( ( n / k ) + 1 ) * k << endl;
	
	return 0;
}
