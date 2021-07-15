#include<iostream> // AC
#include<new>
#include<algorithm>
 
 
using namespace std;
 
 
typedef pair < int, int > PII;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define MP make_pair
 
#define ST first
 
#define ND second
 
 
int max(int a, int b)
{
	return (a>b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	PII *t;
	
	int n, *pref;
	
	cin >> n;
	
	pref = new int [n];
	
	t = new PII [n];
	
	REP(i,0,n-1)
	{
		cin >> t[i].ST >> t[i].ND;	
	}
	
	sort( t, t + n );
	
	pref[0] = t[0].ND;
	
	REP(i,1,n-1)
	{
		pref[i] = max( t[i].ND, pref[ i - 1 ] );
	}
	
	REP(i,1,n-1)
	{
		if( t[i].ND < pref[ i - 1 ] )
		{
			cout << "Happy Alex\n";
			
			return 0;
		}
	}
	
	cout << "Poor Alex\n";
	
	return 0;
}
