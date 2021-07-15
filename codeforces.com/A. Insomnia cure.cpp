#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok) 
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int *t = new int [4], d, *czy;
	
	REP(i,0,3,1)
	{
		cin >> t[i];
	}
	
	cin >> d;
	
	czy = new int [d+1];
	
	REP(i,0,d,1)
	{
		czy[i] = 0;
	}
	
	REP(i,0,3,1)
	{
		REP(j,t[i],d,t[i])
		{
			czy[j] = 1;
		}
	}
	
	REP(i,1,d,1)
	{
		czy[i] += czy[ i - 1 ];
	}
	
	cout << czy[d] << endl;
	
	return 0;
}
