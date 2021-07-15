#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n;
	
	bool *czy = new bool [1000001];
	
	czy[0] = czy[1] = false;
	
	REP(i,2,1000000,1)
	{
		czy[i] = true;
	}
	
	REP(i,2,1000,1)
	{
		if( czy[i] == true )
		{
			REP(j,i*i,1000000,i)
			{
				czy[j] = false;
			}
		}
	}
	
	cin >> n;
	
	REP(i,2,n/2,1)
	{
		if( czy[i] == false  &&  czy[ n - i ] == false )
		{
			cout << i << " " << n - i << endl;
			
			return 0;
		}
	}
	
	return 0;
}
