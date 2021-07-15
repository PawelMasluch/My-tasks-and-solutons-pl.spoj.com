#include<iostream>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int bin(int n)
{
	int pocz = 1, kon = n, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( sr * sr <= n )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, m, pom, wyn = 0, temp;
	
	cin >> n >> m;
	
	pom = bin( n );
	
	REP(i,0,pom)
	{
		temp = n - ( i * i );
		
		if( i + ( temp * temp ) == m )
		{
			++wyn;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
