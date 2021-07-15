#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	char a, b, last;
	
	int n, wyn = 1;
	
	cin >> n >> a >> b;
	
	last = b;
	
	REP(i,2,n)
	{
		cin >> a >> b;
		
		if( a == last )
		{
			++wyn;
			
			last = b;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
