#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n, b, MIN, MAX, ileMIN = 1, ileMAX = 1;
	
	cin >> n >> b;
	
	MIN = MAX = b;
	
	REP(i,2,n)
	{
		cin >> b;
		
		if( b > MAX )
		{
			MAX = b;
			
			ileMAX = 1;
		}
		else
		{
			if( b == MAX )
			{
				++ileMAX;
			}
		}
		
		if( b < MIN )
		{
			MIN = b;
			
			ileMIN = 1;
		}
		else
		{
			if( b == MIN )
			{
				++ileMIN;
			}
		}
	}
	
	cout << MAX - MIN << " ";
	
	if( MIN == MAX )
	{
		cout << ileMIN * ( ileMIN - 1 ) / 2 << endl;
	}
	else
	{
		cout << ileMIN * ileMAX << endl;
	}
	
	return 0;
}
