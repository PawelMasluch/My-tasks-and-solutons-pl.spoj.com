#include<cstdio> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
 
 
const int MAX_N = 1e6, ZAKRES = 1e3;
 
 
bool czy[MAX_N+1];
 
int ile[MAX_N+1], licznik = 0;
 
 
void preprocessing()
{
	REP(i,2,MAX_N,1)
	{
		czy[i] = true;
		
		ile[i] = i;
	}
	
	REP(i,2,MAX_N,1)
	{
		if( czy[i] )
		{
			ile[i] /= i;
			
			REP(j,2*i,MAX_N,i)
			{
				czy[j] = false;
				
				ile[j] /= i;
			}
		}
	}
}
 
 
void print_answers()
{
	REP(i,2,MAX_N,1)
	{
		if( ile[i] == 1  &&  czy[i] == false )
		{
			++licznik;
			
			if( licznik % 108 == 0 )
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
