#include<cstdio> // 100 pkt
#include<iostream>
#include<new>


#define REP(i,a,b) for(i=a; i<=b; ++i)

#define D delete


using namespace std;


void wypelnij(int *pref, int n)
{
	int i, a;
	
	pref[0] = 0;
	
	REP(i,1,n-1)
	{
		scanf("%d", &a);
		
		pref[i] = pref[i-1] + a;
	}
}


int bin(int *pref, int n, int ktory)
{
	int pocz = 0, kon = n - 2, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( pref[sr] < ktory )
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


void solve(int *prefA, int m, int d, int *prefB, int M)
{
	int ktory = prefA[ m - 1 ] + d;
	
	int ind = bin( prefB, M+1, ktory );
			
	printf("%d %d\n", ktory - prefB[ ind ], ind + 1);
}


int main()
{
	char zn;
	
	int N, M, *prefA, *prefB, a, i, Q, d, m, ind, ktory;
	
	scanf("%d%d", &N, &M);
	
	prefA = new int [N+1];
	
	prefB = new int [M+1];
	
	wypelnij(prefA,N+1);
	
	wypelnij(prefB,M+1);
	
	scanf("%d", &Q);
	
	while( Q )
	{
		scanf("%d%d", &d, &m);
		
		cin >> zn;
		
		if( zn == 'A' )
		{
			solve( prefA, m, d, prefB, M );
		}
		else // zn == 'B'
		{
			solve( prefB, m, d, prefA, N );
		}
		
		--Q;
	}
	
	D [] prefA;
	
	D [] prefB;
	
	return 0;
}
