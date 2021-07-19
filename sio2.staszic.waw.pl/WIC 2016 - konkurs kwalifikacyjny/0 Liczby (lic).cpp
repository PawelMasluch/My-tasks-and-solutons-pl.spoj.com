#include<cstdio> // 100 pkt
#include<vector>
#include<algorithm>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back


VI v;

int n, k;


int main()
{
	scanf( "%d %d", &n, &k );
	
	VI :: iterator it;
	
	int a;
	
	REP(i,0,n-1)
	{
		scanf( "%d", &a );
		
		v.PB( a );
	}
	
	sort( v.begin(), v.end() );
	
	v.erase( v.begin() + k, v.end() );
	
	it = unique( v.begin(), v.end() );
	
	v.erase( it, v.end() );
	
	it = v.begin();
	
	while( it != v.end() )
	{
		printf( "%d\n", *it );
		
		++it;
	}
	
	return 0;
}
