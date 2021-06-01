#include<cstdio> // AC
#include<vector>

using namespace std;

typedef vector < int > VI;

#define REP(i,n) for(int i=0; i<n; ++i)

#define PB push_back

#define C clear

VI v;

int r = 0, t[2] = { 2, 3 }, temp;

void operacja(int *pom)
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
		}
}

int phi(int n)
{
	int pom[2] = { 5, 7 }, wyn = n;
	
	temp = n;
	
	operacja( t );
	
	while( pom[0] * pom[0] <= n )
	{
		operacja( pom );
		
		REP(i,2)
		{
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
