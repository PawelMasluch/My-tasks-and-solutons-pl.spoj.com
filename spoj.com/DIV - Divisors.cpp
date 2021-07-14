#include<cstdio> // AC
#include<vector>
 
 
using namespace std;
 
 
typedef pair < int, int > PII;
 
 
#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
 
#define MP make_pair
 
#define ST first
 
#define ND second
 
 
const int MAX_N = 1e6, ZAKRES = 1e3;
 
 
PII d[MAX_N+1];
 
int ile[MAX_N+1], licznik = 0;
 
 
int pow(int a, int b)
{
	int wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn *= a;
		}
		
		b >>= 1;
		
		if( b )
		{
			a *= a;
		}
	}
	
	return wyn;
}
 
 
void preprocessing()
{
	// Maksymalne dzielniki pierwsze + ich wykA?adniki
	
	REP(i,1,MAX_N,1)
	{
		d[i] = MP( i, 1 );
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( d[i].ST == i )
		{
			REP(j,2*i,MAX_N,i)
			{
				d[j].ST = i;
				
				d[j].ND = ( d[ j / i ].ST == i ) ? d[ j / i ].ND + 1 : 1 ;
			}
		}
	}
	
	
	// Liczba dzielnikA3w
	
	ile[1] = 1;
	
	REP(i,2,MAX_N,1)
	{
		ile[i] = ( d[i].ND + 1 ) * ile[ i / pow( d[i].ST, d[i].ND ) ];
	}
}
 
 
void print_answers()
{
	REP(i,1,MAX_N,1)
	{
		if( ile[ ile[i] ] == 4  &&  d[ ile[i] ].ND < 3 )
		{
			++licznik;
			
			if( licznik % 9 == 0 )
			{
				printf( "%d\n", i );
			}
		}
	}
}
 
 
int main()
{
	preprocessing();
	
	print_answers();
	
	return 0;
} 
