#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int max(int a, int b)
{
	return (a>b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, wyn = 1, ile = 1, a1, b1, a2, b2;
	
	cin >> n >> a1 >> b1;
	
	REP(i,2,n)
	{
		cin >> a2 >> b2;
		
		if( a2 == a1  &&  b2 == b1 )
		{
			++ile;
		}
		else
		{
			ile = 1;
		}
		
		wyn = max( wyn, ile );
		
		a1 = a2;
		
		b1 = b2;
	}
	
	cout << wyn << endl;
	
	return 0;
}
