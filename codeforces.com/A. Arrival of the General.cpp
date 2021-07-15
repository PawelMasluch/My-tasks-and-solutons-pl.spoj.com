#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define FORD(i,b,a) for(int i=b; i>=a; --i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, *t, MAX_IND, MIN_IND, MAX = 0, MIN = 101;
	
	cin >> n;
	
	t = new int [n];
	
	REP(i,0,n-1)
	{
		cin >> t[i];
		
		if( t[i] <= MIN )
		{
			MIN = t[i];
			
			MIN_IND = i;
		}
	}
	
	FORD(i,n-1,0)
	{
		if( t[i] >= MAX )
		{
			MAX = t[i];
			
			MAX_IND = i;
		}	
	}
	
	if( MAX_IND == 0  &&  MIN_IND == n - 1 )
	{
		cout << "0\n";
	}
	else
	{
		if( MAX_IND < MIN_IND )
		{
			cout << MAX_IND + n - 1 - MIN_IND << endl;
		}
		else
		{
			cout << MAX_IND + n - 1 - MIN_IND - 1 << endl;
		}
	}
	
	return 0;
}
