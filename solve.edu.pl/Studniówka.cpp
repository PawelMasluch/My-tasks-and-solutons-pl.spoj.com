#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


typedef long long LL; 


#define REP(i,N) for(LL i=0; i<N; ++i)


const LL MAX_N = 250000, MAX_M = 250000, INF = 2e9 + 99;


LL A[MAX_N], B[MAX_M+1], n, m, k, wyn = 0, ind1 = 0, ind2 = 0;


int main()
{
	scanf( "%lld %lld %lld", &n, &m, &k );
	
	REP(i,n)
	{
		scanf( "%lld", &A[i] );
	}
	
	REP(i,m)
	{
		scanf( "%lld", &B[i] );
	}
	
	B[m] = INF; // wartownik
	
	sort( A, A + n );
	
	sort( B, B + m );
	
	REP(i,n) // dla każdego elementu ciagu A szukam odpowiedniego przedzialu <ind1,ind2) ciagu B
	{
		while( B[ ind1 ] < A[i] - k ) // szukam takiego ind1, że B[ind1] >= A[i] - k
		{
			++ind1;
		}
		
		while( B[ ind2 ] <= A[i] + k ) // szukam takiego ind2, że B[ind1] > A[i] + k
		{
			++ind2;
		}
		
		wyn += ( ind2 - ind1 );
	}
	
	printf( "%lld\n", wyn );
	
	return 0;
}
