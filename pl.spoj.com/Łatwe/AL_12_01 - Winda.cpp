#include<iostream> // AC
#include<string>


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)


int min(int a, int b)
{
	return (a<b) ? a : b ;
}


int max(int a, int b)
{
	return (a>b) ? a : b ;
}


void znajdz(string &s, int &MIN, int &MAX)
{
	int r = s.size(), temp = 0;
	
	REP(i,r)
	{
		if( s[i] == 'U' )
		{
			++temp;
			
			MAX = max( MAX, temp );
		}
		else // s[i] == 'D'
		{
			--temp;
			
			MIN = min( MIN, temp );
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	int q, n, MIN = 0, MAX = 0;
	
	cin >> q;
	
	while( q )
	{
		cin >> n >> s;
		
		znajdz( s, MIN, MAX );
		
		if( MAX - MIN + 1 <= n )
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
		
		MIN = MAX = 0;
		
		--q;
	}
	
	return 0;
}
