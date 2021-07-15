#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define FORD(i,b,a) for(int i=b; i>=a; --i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, *ile = new int [1000001], *a, *pocz = new int [1000001], *kon = new int [1000001], wyn = 1, dl = 1000009, ind;
	
	REP(i,0,1000000)
	{
		ile[i] = pocz[i] = kon[i] = 0;
	}
	
	cin >> n;
	
	a = new int [n];
	
	REP(i,0,n-1)
	{
		cin >> a[i];
		
		++ile[ a[i] ];
		
		kon[ a[i] ] = i + 1;
	}
	
	FORD(i,n-1,0)
	{
		pocz[ a[i] ] = i + 1;
	}
	
	REP(i,0,1000000)
	{
		if( ile[i] > wyn )
		{
			wyn = ile[i];
			
			dl = kon[i] - pocz[i] + 1;
			
			ind = i;
		}
		else
		{
			if( ile[i] == wyn )
			{
				if( kon[i] - pocz[i] + 1 < dl )
				{
					dl = kon[i] - pocz[i] + 1;
					
					ind = i;
				}
			}
		}
	}
	
	cout << pocz[ ind ] << " " << kon[ ind ] << endl;
	
	return 0;
}
