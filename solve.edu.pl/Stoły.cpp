#include<cstdio> // 100 pkt
#include<new>


#define REP(i,n) for(i=0; i<n; ++i)


using namespace std;


bool czy_permutacja(int *t, int n)
{
	int i;

	bool *odw = new bool [n];

	REP(i,n)
	{
		odw[i] = false;
	}

	REP(i,n)
	{
		if( odw[ t[i] ] == true )
		{
			delete [] odw;
			
			return false;
		}
		
		odw[ t[i] ] = true;
	}
	
	delete [] odw;
	
	return true;
}


int liczba_cykli(int *t, int n)
{
	int i, j, wyn = 0;
	
	bool *odw = new bool [n];
	
	REP(i,n)
	{
		odw[i] = false;
	}
	
	REP(i,n)
	{
		if( !odw[i] )
		{
			j = i;
			
			while( !odw[j] )
			{
				odw[j] = true;
				
				j = t[j];
			}
			
			++wyn;
		}
	}
	
	delete [] odw;
	
	return wyn;
}


int main()
{
	int n, i, *t;
	
	scanf("%d", &n);
	
	t = new int [n];
	
	REP(i,n)
	{
		scanf("%d", &t[i]);
		
		--t[i];
	}
	
	if( czy_permutacja(t,n) == false )
	{
		printf( "NIE\n" );
	}
	else
	{
		printf( "%d\n", liczba_cykli(t,n) );
	}
	
	return 0;
}
