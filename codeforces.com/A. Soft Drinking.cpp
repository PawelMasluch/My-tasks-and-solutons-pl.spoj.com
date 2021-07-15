#include<iostream> // AC
 
 
using namespace std;
 
 
int min(int a, int b)
{
	return (a<b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, k, l, c, d, p, nl, np;
	
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	
	cout << min( min( ( k * l ) / ( n * nl ), ( c * d ) / n ), p / ( n * np ) ) << endl;
	
	return 0;
}
