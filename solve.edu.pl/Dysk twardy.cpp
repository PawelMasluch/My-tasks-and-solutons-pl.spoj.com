#include<cstdio> // 100 pkt
#include<new>


#define REP(i,n) for(i=0; i<n; ++i)


using namespace std;


int main()
{
	int N, *prev, *next, a, i;
	
	scanf("%d", &N);
	
	prev = new int [N];  next = new int [N];
	
	REP(i,N)
	{
		prev[i] = i - 1;
		
		next[i] = i + 1;
	}
	
	REP(i,N)
	{
		scanf("%d", &a);
		
		--a;
		
		if( next[a] == N )
		{
			printf("NIE\n");
		}
		else
		{
			printf("%d\n", next[a]+1);
		}
		
		if( prev[a] != -1 )
		{
			next[ prev[a] ] = next[a];
		}
		
		if( next[a] != N )
		{
			prev[ next[a] ] = prev[a];
		}
	}
	
	return 0;
}
