#include<iostream> // AC
#include<vector>
 
 
using namespace std;
 
 
typedef vector < int > VI;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define PB push_back
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	VI wyn;
	
	int n, v, k, s, czy = 0, r = 0;
	
	cin >> n >> v;
	
	REP(i,1,n)
	{
		cin >> k;
		
		REP(j,1,k)
		{
			cin >> s;
			
			if( s < v )
			{
				czy = 1;
			}
		}
		
		if( czy == 1 )
		{
			wyn.PB( i );
			
			++r;
			
			czy = 0;
		}
	}
	
	cout << r << endl;
	
	REP(i,0,r-1)
	{
		cout << wyn[i] << " ";
	}
	
	cout << endl;
	
	return 0;
}
