#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i) 
 
 
int f(int x)
{
	return (x>=0) ? x : -x ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	char zn;
	
	int x, y;
	
	REP(i,1,5)
	{
		REP(j,1,5)
		{
			cin >> zn;
			
			if( zn == '1' )
			{
				x = i;
				
				y = j;
			}
		}
	}
	
	cout << f( x - 3 ) + f( y - 3 ) << endl;
	
	return 0;
}
