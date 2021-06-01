#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 100000;


int N, M, zbior[MAX_N+1], r[MAX_N+1], ile_zbiorow;


void init()
{
	REP(i,1,N)
	{
		zbior[i] = i;
		
		r[i] = 1;
	}
	
	ile_zbiorow = N;
}


int Find(int u)
{
	int wyn = u;
	
	while( zbior[ wyn ] != wyn )
	{
		wyn = zbior[ wyn ];
	}
	
	zbior[ u ] = wyn;
	
	return wyn;
}


void Union(int u, int v)
{
	int repr_u = Find( u ), repr_v = Find( v );
	
	if( repr_u != repr_v )
	{
		if( r[ repr_u ] >= r[ repr_v ] )
		{
			zbior[ repr_v ] = repr_u;
			
			r[ repr_u ] += r[ repr_v ];
		}
		else
		{
			zbior[ repr_u ] = repr_v;
			
			r[ repr_v ] += r[ repr_u ];
		}
		
		--ile_zbiorow;
	}
}


int main()
{
	scanf( "%d %d", &N, &M );
	
	init();
	
	int u, v;
	
	REP(i,1,M)
	{
		scanf( "%d %d", &u, &v );
		
		Union( u, v );
		
		printf( "%d\n", ile_zbiorow );
	}
	
	return 0;
}
