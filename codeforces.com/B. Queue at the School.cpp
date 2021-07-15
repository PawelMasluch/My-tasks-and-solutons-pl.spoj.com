#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	int n, q, j = 1;
	
	cin >> n >> q >> s;
	
	REP(i,1,q,1)
	{
		while( j <= n - 1 )
		{
			if( s[ j - 1 ] == 'B'  &&  s[j] == 'G' )
			{
				s[ j - 1 ] = 'G';
				
				s[j] = 'B';
				
				j += 2;
			}
			else
			{
				++j;
			}
		}
		
		j = 1;
	}
	
	cout << s << endl;
	
	return 0;
}
