#include<iostream> // AC
 
 
using namespace std;
 
 
int max(int a, int b)
{
	return (a>b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int k, n, w, A;
	
	cin >> k >> n >> w;
	
	A = k * w * ( w + 1 ) / 2;
	
	cout << max( 0, A - n ) << endl;
	
	return 0;
}
