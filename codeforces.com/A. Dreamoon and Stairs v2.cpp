#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, m, MIN, MAX, kmin, kmax;
	
	cin >> n >> m;
	
	MIN = ( n + 1 ) / 2;
	
	MAX = n; // MAX >= MIN >= 1
	
	kmin = ( MIN + m - 1 ) / m; // kmin >= 1
	
	kmax = MAX / m; // kmax >= 0
	
	if( kmin <= kmax )
	{
		cout << kmin * m << endl;
	}
	else
	{
		cout << "-1\n";
	}
	
	return 0;
}
