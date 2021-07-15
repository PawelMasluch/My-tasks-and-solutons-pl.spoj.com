#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int min(int a, int b)
{
	return (a<b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int *pref, n, d, s, t, temp, odl1, odl2;
	
	cin >> n;
	
	pref = new int [n+1];
	
	pref[0] = 0;
	
	REP(i,1,n)
	{
		cin >> d;
		
		pref[i] = pref[ i - 1 ] + d;
	}
	
	cin >> s >> t;
	
	if( s > t )
	{
		temp = s;
		
		s = t;
		
		t = temp;
	}
	
	odl1 = pref[ t - 1 ] - pref[ s - 1 ];
	
	odl2 = pref[n] - odl1;
	
	cout << min( odl1, odl2 ) << endl;
	
	return 0;
}
