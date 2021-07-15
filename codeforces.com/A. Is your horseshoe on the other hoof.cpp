#include<iostream> // AC
#include<new>
#include<algorithm>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int t[4], ile = 1;
	
	REP(i,0,3)
	{
		cin >> t[i];
	}
	
	sort( t, t + 4 );
	
	REP(i,1,3)
	{
		if( t[i] != t[ i - 1 ] )
		{
			++ile;
		}
	}
	
	cout << 4 - ile << endl;
	
	return 0;
}
