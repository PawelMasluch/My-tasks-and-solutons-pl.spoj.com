#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n, m, a, wyn;
	
	cin >> n >> m >> a;
	
	wyn = ( ( n + a - 1 ) / a ) * ( ( m + a - 1 ) / a );
	
	cout << wyn << endl;
	
	return 0;
}
