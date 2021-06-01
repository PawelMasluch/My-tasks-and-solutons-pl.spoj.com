#include<cstdio> // AC
#include<vector>

using namespace std;

typedef vector < int > VI;

#define REP(i,n) for(int i=0; i<n; ++i)

#define PB push_back

#define C clear

VI v;

int r = 0, t[2] = { 2, 3 };

int phi(int n)
{
	int temp = n, pom[2] = { 5, 7 }, wyn = n;
	
	REP(i,2)
	{
		if( temp % t[i] == 0 )
		{
			v.PB( t[i] );
			
			++r;
				
			while( temp % t[i] == 0 )
			{
				temp /= t[i];
			}
		}
	}
	
	while( pom[0] * pom[0] <= n )
	{
		REP(i,2)
		{
			if( temp % pom[i] == 0 )
			{
				v.PB( pom[i] );
				
				++r;
				
				while( temp % pom[i] == 0 )
				{
					temp /= pom[i];
				}
			}
			
			pom[i] += 6;
		}
	}
	
	if( temp > 1 )
	{
		v.PB( temp );
		
		++r;
	}
	
	REP(i,r)
	{
		wyn /= v[i];
		
		wyn *= ( v[i] - 1 );
	}
	
	v.C();
	
	r = 0;
	
	return wyn;
}

int main()
{
	int q, n;
	
	scanf( "%d", &q );
	
	REP(i,q)
	{
		scanf( "%d", &n );
		
		printf( "%d\n", phi( n ) );
	}
	
	return 0;
}
