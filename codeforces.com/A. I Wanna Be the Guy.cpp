#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	bool *czy;
	
	int n, p, q, a;
	
	cin >> n;
	
	czy = new bool [n];
	
	REP(i,0,n-1)
	{
		czy[i] = false;
	}
	
	cin >> p;
	
	REP(i,1,p)
	{
		cin >> a;
		
		--a;
		
		czy[a] = true;
	}
	
	cin >> q;
	
	REP(i,1,q)
	{
		cin >> a;
		
		--a;
		
		czy[a] = true;
	}
	
	REP(i,0,n-1)
	{
		if( czy[i] == false )
		{
			cout << "Oh, my keyboard!\n";
			
			return 0;
		}
	}
	
	cout << "I become the guy.\n";
			
	return 0;
}
