#include<cstdio> // 100 pkt
#include<new>
#include<vector>
#include<algorithm>

using namespace std;

int min(int a, int b)
{
	return (a<b) ? a : b ;
}

int main()
{
	vector < int > v;
	
	int N, i, *t, r = 0, wyn = 0;
	
	scanf("%d", &N);
	
	t = new int [N+2];
	
	t[0] = t[N+1] = 1000000001;
	
	for(i=1; i<=N; ++i)
	{
		scanf("%d", &t[i]);
	}
	
	for(i=1; i<=N; ++i)
	{
		if( t[i] < min( t[i-1], t[i+1] ) )
		{
			v.push_back( t[i] );
			
			++r;
		}
	}
	
	if( r > 0 )
	{
		++wyn;
		
		sort( v.begin(), v.end() );
		
		for(i=1; i<=r-1; ++i)
		{
			if( v[i] != v[i-1] )
			{
				++wyn;
			}
		}
	}
	
	printf("%d\n", wyn);
	
	return 0;
}
