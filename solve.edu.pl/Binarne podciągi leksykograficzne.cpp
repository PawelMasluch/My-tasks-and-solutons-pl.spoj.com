#include<iostream> // 100 pkt
#include<string>

using namespace std;

typedef unsigned long long ul;

int main()
{
		ios_base::sync_with_stdio(0);
	
		string s;
		
		ul N, K, i, F[91];
		
		F[0] = 0;  F[1] = 1;
		
		for(i=2; i<=90; ++i)
		{
			F[i] = F[i-1] + F[i-2];
		}
		
		cin >> N >> K;
		
		if( N <= 85 )
		{
			if( K > F[ N + 2 ] )
			{
				cout << "NIE\n";
				return 0;
			}
		}
		
		for(i=N; i>=1; --i)
		{
			if( i + 1 >= 88 )
			{
				s = s + '0';
			}
			else
			{
				if( K > F[i+1] )
				{
					s = s + '1';
					K -= F[i+1];
				}
				else
				{
					s = s + '0'; 
				}
			}
		}
		
		cout << s << endl;
		
		s.clear();
	
		return 0;
}
