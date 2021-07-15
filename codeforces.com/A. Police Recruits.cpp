#include<iostream> // AC
#include<new>
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, ile = 0, a, wyn = 0;
	
	cin >> n;
	
	REP(i,1,n)
	{
		cin >> a;
		
		if( a == -1 )
		{
			if( ile == 0 )
			{
				++wyn;
			}
			else
			{
				--ile;
			}
		}
		else
		{
			ile += a;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
