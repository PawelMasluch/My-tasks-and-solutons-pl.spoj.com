#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


struct elem
{
	int a, b;
};


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 1000000, MAX_M = 1000000;


elem A[MAX_M], B[MAX_M];

int t[MAX_N], n, m;


bool f1(const elem &p, const elem &q)
{
	return ( p.a < q.a );
}


bool f2(const elem &p, const elem &q)
{
	return ( p.b < q.b );
}


int bin1(int x) // liczba przedzia??w o ko?cach mniejszych ni? x
{
	int pocz = 0, kon = m - 1, wyn = -1, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( A[ sr ].b < x )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn + 1;
}


int bin2(int x) // liczba przedzia??w o ko?cach wi?kszych ni? x
{
	int pocz = 0, kon = m - 1, wyn = m, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( B[ sr ].a > x )
		{
			wyn = sr;
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return m - wyn;
}


int main()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
	}
	
	scanf( "%d", &m );
	
	REP(i,0,m-1)
	{
		scanf( "%d %d", &A[i].a, &A[i].b );
		
		B[i].a = A[i].a;
		
		B[i].b = A[i].b;
	}
	
	sort( A, A + m, f2 ); // sortuj? przedzia?y po ko?cach
	
	sort( B, B + m, f1 ); // sortuj? przedzia?y po pocz?tkach
	
	REP(i,0,n-1)
	{
		printf( "%d\n", m - bin1( t[i] ) - bin2( t[i] ) );
	}
	
	return 0;
}
