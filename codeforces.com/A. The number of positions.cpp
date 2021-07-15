#include<iostream>
 
 
using namespace std;
 
 
int max(int a, int b)
{
	return (a>b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, a, b, d;
	
	cin >> n >> a >> b;
	
	d = max( a + 1, n - b );
	
	cout << n - d + 1 << endl;
	
	return 0;
}
