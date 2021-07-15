#include<iostream> // AC
#include<new>
#include<algorithm>
 
 
using namespace std;
 
 
typedef pair < int, int > PII;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define ST first
 
#define ND second
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	PII *t;
	
	int s, n;
	
	cin >> s >> n;
	
	t = new PII [n];
	
	REP(i,0,n-1)
	{
		cin >> t[i].ST >> t[i].ND;
	}
	
	sort( t, t + n );
	
	REP(i,0,n-1)
	{
		if( s <= t[i].ST )
		{
			cout << "NO\n";
			
			return 0;
		}
		else
		{
			s += t[i].ND;
		}
	}
	
	cout << "YES\n";
	
	return 0;
}
