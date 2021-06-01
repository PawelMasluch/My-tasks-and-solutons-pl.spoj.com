#include<cstdio> // 100 pkt


using namespace std;


int f(int n)
{
	int wyn = n, tmp = n, ile = 0;
	
	for(int i=2; i*i<=n && tmp>1; ++i)
	{
		while( !( tmp % i ) )
		{
			tmp /= i;
			
			++ile;
		}
		
		if( ile )
		{
			wyn /= i;
			
			wyn *= ( i - 1 );
			
			ile = 0;
		}
	}
	
	if( tmp > 1 )
	{
		wyn /= tmp;
		
		wyn *= ( tmp - 1 );
	}
	
	return wyn;
}


int main()
{
	int n;
	
	scanf( "%d", &n );
	
	printf( "%d\n", f( n ) );
	
	return 0;
}
