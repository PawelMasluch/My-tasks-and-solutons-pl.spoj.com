#include<cstdio> // 100 pkt

#define REP(i,a,b) for(i=a; i<=b; ++i)

using namespace std;

int main()
{
	int N, i, j; 
	
	long double wyn = 1.;
	
	scanf("%d", &N);
	
	REP(i,1,N)
	{
		REP(j,1,i)
		{
			wyn *= i;
		}
	}
	
	REP(i,1,N*(N+1)/2)
	{
		wyn /= ( N + 1 );
		
		wyn *= 2;
	}
	
	printf("%.6Lf\n", wyn);
	
	return 0;
}
