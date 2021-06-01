#include<cstdio> // 100 pkt
#include<new>
#include<algorithm>


#define REP(i,n) for(i=0; i<n; ++i)


using namespace std;


typedef long long LL;


void wczytaj(int *t, int n)
{
	int i;
	
	REP(i,n)
	{
		scanf( "%d", &t[i] );
	}
}


bool czy_istnieje(int *t, int n, int S)
{
	int i = 0, j = n - 1;
	
	while( i <= n - 1 )
	{
		while( j >= i )
		{
			if( t[i] + t[j] > S )
			{
				--j;
			}
			else
			{
				if( t[i] + t[j] == S )
				{
					return true;
				}
				else
				{
					break;
				}
			}
		}
		
		++i;
	}
	
	return false;
}


LL ile_niewiekszych(int *t, int n, int S)
{
	int i = 0, j = n - 1;
	
	LL wyn = 0;
	
	while( i <= n - 1 )
	{
		if( 2 * t[i] <= S )
		{
			++wyn;
		}
		
		while( j > i )
		{
			if( t[i] + t[j] > S )
			{
				--j;
			}
			else
			{
				wyn += 2 * ( j - i );
				
				break;	
			}
		}
		
		++i;
	}
	
	return wyn;
}


int fun(int *t, int n, LL m)
{
	int pocz = 2, kon = 2000000000, wyn, sr;
	
	LL pom;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		pom = ile_niewiekszych(t,n,sr);
		
		if( pom >= m )
		{
			if( czy_istnieje(t,n,sr) )
			{
				wyn = sr;
			}
				
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return wyn;
}


int main()
{
	int N, i, *t;
	
	LL M;
	
	scanf("%d%lld", &N, &M);
	
	t = new int [N];
	
	wczytaj(t,N);
	
	sort(t,t+N);
	
	printf( "%d\n", fun( t, N, M ) );
	
	return 0;
}
