#include<cstdio> // 100 pkt
#include<new>


#define REP(i,n) for(i=0; i<n; ++i)


using namespace std;


typedef long long LL;


void mnoz(LL *a, LL *b, LL N, LL *pom)
{
	LL i;
	
	REP(i,N)
	{
		pom[i] = a[ b[i] ];
	}
			
	REP(i,N)
	{
		a[i] = pom[i];
	}
}


void poteguj(LL *t, LL N, LL K, LL *wyn)
{
	LL *pom = new LL [N];
	
	while( K )
	{
		if( K & 1 )
		{
			mnoz( wyn, t, N, pom );
		}
		
		mnoz( t, t, N, pom );
		
		K >>= 1;
	}
	
	delete [] pom;
}


int main()
{
	LL N, K, *t, i, *wyn;
	
	scanf("%lld%lld", &N, &K);
	
	t = new LL [N];
	
	wyn = new LL [N];
	
	REP(i,N)
	{
		scanf("%lld", &t[i]);
		
		--t[i];
		
		wyn[i] = i;
	}
	
	poteguj( t, N, K, wyn );
	
	REP(i,N)
	{
		printf("%lld ", wyn[i] + 1);
	}
	
	printf("\n");
	
	return 0;
}
