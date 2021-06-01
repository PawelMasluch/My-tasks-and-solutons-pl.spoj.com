#include<cstdio> // AC
#include<new>


using namespace std;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)


const int ZAKRES = 1000000;


int main()
{
	int *A = new int [ZAKRES+1], *T = new int [ZAKRES+1], n, a, b, q;
	
	REP(i,0,ZAKRES,1)
	{
		A[i] = 0; // liczba "i" jeszcze nie wyst¹pi³a w multizbiorze
		
		T[i] = 1; // liczba "i" jeszcze aktualna
	}
	
	scanf( "%d", &n );
	
	REP(i,1,n,1)
	{
		scanf( "%d", &a );
		
		A[a] = 1;
	}
	
	REP(i,0,ZAKRES,1)
	{
		if( A[i] == 1 ) // z za³o¿eñ zadania wynika, ¿e A[0] bêdzie zawsze równe zero
		{
			REP(j,0,ZAKRES,i)
			{
				T[j] = 0;
			}
		}
	}
	
	REP(i,1,ZAKRES,1)
	{
		T[i] += T[ i - 1 ]; 
	}
	
	scanf( "%d", &q );
	
	REP(i,1,q,1)
	{
		scanf( "%d%d", &a, &b );
		
		printf( "%d\n", T[b] - T[ a - 1 ] );
	}
	
	return 0;
}
