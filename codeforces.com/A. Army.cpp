#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,n) for(int i=0; i<n; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, *pref, a, b;
	
	cin >> n;
	
	pref = new int [n+1];
	
	pref[0] = pref[1] = 0;
	
	REP(i,n-1)
	{
		cin >> a;
		
		pref[ i + 2 ] = pref[ i + 1 ] + a;
	}
	
	cin >> a >> b;
	
	cout << pref[b] - pref[ a ] << endl;
	
	return 0;
}
