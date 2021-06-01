#include<iostream> // AC
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	
	string *T;
	
	int Z, n, i, wyn = 1, temp = 1;
	
	cin >> Z;
	
	while( Z )
	{
		cin >> n;
		
		T = new string [n];
		
		for(i=0; i<=n-1; ++i)
		{
			cin >> T[i];
			
			sort( T[i].begin(), T[i].end() );
		}
		
		sort(T,T+n);
		
		for(i=1; i<=n-1; ++i)
		{
			if( T[i] == T[i-1] )
			{
				++temp;
				wyn = max( wyn, temp );
			}
			else
			{
				temp = 1;
			}
		}
		
		cout << wyn << endl;
		
		wyn = temp = 1;
		
		--Z;
	}
	
	return 0;
}
