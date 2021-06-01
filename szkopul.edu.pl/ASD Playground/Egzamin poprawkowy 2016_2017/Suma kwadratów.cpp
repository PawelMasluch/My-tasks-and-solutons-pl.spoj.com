#include<cstdio> // 100 pkt
#include<map>


using namespace std;


typedef long long LL;

typedef map < int, int > MII;


#define ST first


const int INF = 1000000 + 199;


MII M;

LL S = 0;

int n;


void solve()
{
	scanf( "%d", &n );
	
	
	M[ -INF ] = 1;    M[ INF ] = 1;
	
	
	MII::iterator it_left, it_right;
	
	int x, val_left, val_right;
	
	while( n )
	{
		scanf( "%d", &x );
		
		
		it_right = M.upper_bound( x );
		
		it_left = --it_right;    ++it_right;
		
		
		val_left = it_left -> ST ;    //printf( "%d, ", val );
		
		if(  val_left != -INF )
		{
			S += (LL)( x - val_left ) * ( x - val_left );
		}
		
		
		val_right = it_right -> ST ;    //printf( "%d\n", val );
		
		if(  val_right != INF )
		{
			S += (LL)( val_right - x ) * ( val_right - x );
		}
		
		
		if( val_left != -INF  &&  val_right != INF )
		{
			S -= (LL)( val_right - val_left ) * ( val_right - val_left );	
		}
		
		
		if( S > 0 )
		{
			printf( "%lld\n", S );	
		}
		
		
		M[x] = 1;
		
		
		--n;
	}
}


int main()
{
	solve();
	
	return 0;
}
