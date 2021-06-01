#include<cstdio> // 100 pkt
#include<new>
#include<algorithm>


#define REP(i,n) for(i=0; i<n; ++i)

#define ST first

#define ND second

#define D delete


using namespace std;


typedef pair < int, int > PII; 


int bin(PII *t, int n, int a)
{
	int pocz = 0, kon = n - 1, sr, wyn = -1;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( t[sr].ST >= a )
		{
			wyn = t[sr].ND;
			
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
	int n, m, i, a;
	
	scanf("%d%d", &n, &m);
	
	PII *t = new PII [n];
	
	REP(i,n)
	{
		scanf("%d", &t[i].ST);
		
		t[i].ND = i + 1;
	}
	
	sort(t,t+n);
	
	REP(i,m)
	{
		scanf("%d", &a);
		
		printf( "%d ", bin(t,n,a) );
	}
	
	printf("\n");
	
	D [] t;
	
	return 0;
}
