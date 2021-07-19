#include<cstdio> // do sprawdzenia
#include<new>

using namespace std;

bool czy_bitoniczny(int *t, int n)
{
	int i;
	
	for(i=1; i<=n-1; ++i)
	{
		if( t[ i ]  <=  t[ i - 1 ] )
		{
			break;
		}
	}
	
	while( i <= n - 1 )
	{
		if( t[ i ] >= t[ i - 1 ] )
		{
			return false;
		}
			
		++i;
	}
	
	return true;
}

void g(int *t, int n)
{
	if( czy_bitoniczny(t,n) == true )
	{
		printf("TAK\n");
	}
	else
	{
		printf("NIE\n");
	}
}

int main()
{
	int n, i, *t;
	
	scanf("%d", &n);
	
	t = new int [n];
	
	for(i=0; i<=n-1; ++i)
	{
		scanf("%d", &t[i]);
	}
	
	g(t,n);
	
	return 0;
}
