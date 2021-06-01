#include<cstdio> // 100 pkt
#include<string>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


struct elem
{
	int REPR, IQ_MIN, IQ_MAX, MASA, ILE;
};


const int MAX_N = 1000000, MAX_L = 6;


elem t[MAX_N+1];

char q[MAX_L];

string s;

int n; 


int min(int a, int b)
{
	return (a<b) ? a : b ;
}


int max(int a, int b)
{
	return (a>b) ? a : b ;
}


int FIND(int a)
{
	int temp = a;
	
	while( t[ temp ].REPR != temp )
	{
		temp = t[ temp ].REPR;
	}
	
	t[a].REPR = temp;
	
	return temp;
}


int f(int R1, int R2)
{
	t[ R1 ].ILE += t[ R2 ].ILE;
			
	t[ R1 ].MASA += t[ R2 ].MASA;
			
	t[ R1 ].IQ_MIN = min( t[ R1 ].IQ_MIN, t[ R2 ].IQ_MIN );
			
	t[ R1 ].IQ_MAX = max( t[ R1 ].IQ_MAX, t[ R2 ].IQ_MAX );
			
	t[ R2 ].REPR = R1;
}


void UNION(int a, int b)
{
	int R1 = FIND( a ), R2 = FIND( b );
	
	if( R1 != R2 )
	{
		if( t[ R1 ].ILE >= t[ R2 ].ILE )
		{
			f( R1, R2 );
		}
		else
		{
			f( R2, R1 );
		}
	}
}


int main()
{
	int temp, a, b;
	
	scanf( "%d", &n );
	
	REP(i,1,n)
	{
		scanf( "%d %d", &t[i].MASA, &t[i].IQ_MIN );
		
		t[i].IQ_MAX = t[i].IQ_MIN;
		
		t[i].REPR = i;
		
		t[i].ILE = 1;
	}
	
	while( scanf( "%s", q ) != EOF )
	{
		s = q;
		
		if( s == "JOIN" )
		{
			scanf( "%d %d", &a, &b );
			
			UNION( a, b );
		}
		
		if( s == "IQ_MIN" )
		{
			scanf( "%d", &a );
			
			temp = FIND( a );
			
			printf( "%d\n", t[ temp ].IQ_MIN );
		}
		
		if( s == "IQ_MAX" )
		{
			scanf( "%d", &a );
			
			temp = FIND( a );
			
			printf( "%d\n", t[ temp ].IQ_MAX );
		}
		
		if( s == "MASA" )
		{
			scanf( "%d", &a );
			
			temp = FIND( a );
			
			printf( "%d\n", t[ temp ].MASA );
		}
	}
	
	return 0;
}
