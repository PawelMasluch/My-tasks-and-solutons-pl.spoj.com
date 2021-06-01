#include<cstdio> // 100 pkt
#include<map>


using namespace std;


typedef map < int, int > MII;


MII M;

int n, d, ile = 0;


void solve()
{
	scanf( "%d %d", &n, &d );
	
	int id, x;
	
	while( n )
	{
		scanf( "%d %d", &id, &x );
		
		if( id == -1 ) // usuwanie 'x' ze zbioru
		{
			if( M.count( x - d ) > 0 )
			{
				--ile;
			}
			
			if( M.count( x + d ) > 0 )
			{
				--ile;
			}
			
			M.erase( x );
		}
		else // id == 1, czyli dodawanie 'x' do zbioru
		{
			if( M.count( x - d ) > 0 )
			{
				++ile;
			}
			
			if( M.count( x + d ) > 0 )
			{
				++ile;
			}
			
			M[x] = 1;
		}
		
		
		// wypisanie wyniku
		
		if( ile > 0 )
		{
			printf( "TAK\n" );
		}
		else
		{
			printf( "NIE\n" );
		}
		
		--n;
	}
}


int main()
{
	solve();
	
	return 0;
}
