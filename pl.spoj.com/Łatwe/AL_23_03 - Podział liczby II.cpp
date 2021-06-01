#include<cstdio> // AC


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


LL start, meta;


LL bin(LL n)
{
	LL pocz = 1, kon = 45000, sr, wyn;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( sr * ( sr + 1 ) / 2 <= n )
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


LL f(LL n)
{
	LL max_dl = bin( n ), k, temp, wyn = 1;
	
	REP(i,2,max_dl)
	{
		if( i % 2 == 0 )
		{
			k = i / 2;
			
			if( n % k == 0 )
			{
				temp = n / k;
				
				if( temp % 2 == 1 )
				{
					temp = ( temp - 1 ) / 2;
					
					if( temp > k - 1 )
					{
						wyn = i;
						
						return wyn;
					}
				}
			}
		}
		else
		{
			if( n % i == 0 )
			{
				k = ( i - 1 ) / 2;
				
				temp = n / i;
				
				if( temp > k )
				{
					wyn = i;
					
					return wyn;
				}
			}
		}
	}
	
	return wyn;
}


void g(LL n)
{
	LL wyn = f( n ), k, temp;
	
	if( wyn % 2 == 0 )
	{
		k = wyn / 2;
		
		temp = n / k;
		
		temp = ( temp - 1 ) / 2;
		
		start = temp - k + 1;
		
		meta = temp + k;
	}
	else
	{
		temp = n / wyn;
		
		k = ( wyn - 1 ) / 2;
		
		start = temp - k;
		
		meta = temp + k;
	}
}

void h(LL n)
{
	g( n );
	
	printf( "%lld = ", n );
	
	if( meta - start + 1 == 1 )
	{
		printf( "BRAK\n" );
	}
	else
	{
		REP(i,start,meta-1)
		{
			printf( "%lld + ", i );
		}
		
		printf( "%lld\n", meta );
	}
}


int main()
{
	LL q, n;
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &n );
		
		h( n );
		
		--q;
	}
	
	return 0;
}

