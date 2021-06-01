#include<cstdio>
#include<vector> // AC


using namespace std;


typedef long long LL;

typedef vector < LL > VLL;


#define REP(i,n) for(LL i=0; i<n; ++i)

#define PB push_back

#define C clear


VLL v, exp;

LL r = 0, t[2] = { 2, 3 }, temp;


LL fpm(LL a, LL b)
{
	LL wyn = 1;
	
	while( b )
	{
		if( b % 2 == 1 )
		{
			wyn *= a;
		}
		
		a *= a;
		
		b /= 2;
	}
	
	return wyn;
}


void operacja(LL *pom)
{
		REP(i,2)
		{
			if( temp % pom[i] == 0 )
			{
				v.PB( pom[i] );
				
				exp.PB( 0 );
				
				++r;
				
				while( temp % pom[i] == 0 )
				{
					temp /= pom[i];
					
					++exp[ r - 1 ];
				}
			}
		}
}


void czysc()
{
	v.C();
	
	exp.C();
	
	r = 0;
}


LL sigma(int n)
{
	LL pom[2] = { 5, 7 }, wyn = 1;
	
	temp = n;
	
	operacja( t );
	
	while( pom[0] * pom[0] <= n  &&  temp > 1 )
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
		
		exp.PB( 1 );
		
		++r;
	}
	
	REP(i,r)
	{
		wyn *= ( fpm( v[i], exp[i] + 1 ) - 1 );
		
		wyn /= ( v[i] - 1 );
	}
	
	czysc();
	
	return wyn;
}


int main()
{
	LL q, n;
	
	scanf( "%lld", &q );
	
	REP(i,q)
	{
		scanf( "%lld", &n );
		
		printf( "%lld\n", sigma( n ) );
	}
	
	return 0;
}
