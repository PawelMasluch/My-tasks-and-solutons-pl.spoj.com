#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, m;
	
	cin >> n >> m;
	
	REP(i,1,n)
	{
		if( i % 2 == 1 )
		{
			REP(j,1,m)
			{
				cout << '#';
			}
		}
		else
		{
			if( i % 4 == 2 )
			{
				REP(j,1,m-1)
				{
					cout << '.';
				}
				
				cout << '#';
			}
			else // i % 4 == 0
			{
				cout << '#';
				
				REP(j,2,m)
				{
					cout << '.';
				}	
			}
		}
		
		cout << "\n";
	}
			
	return 0;
}
