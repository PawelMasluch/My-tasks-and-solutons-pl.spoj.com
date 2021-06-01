#include<iostream> // 100 pkt
#include<string>


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)


int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	cin >> s;
	
	int n = s.size(), tmp;
	
	REP(i,n)
	{
		tmp = (int)( s[i] );
		
		if( tmp >= 97  &&  tmp <= 122 ) // ma³a litera
		{
			if( tmp <= 109 )
			{
				cout << (char)( tmp + 13 );
			}
			else
			{
				cout << (char)( tmp - 13 );
			}
		}
		else
		{
			if( tmp >= 65  &&  tmp <= 90 ) // du¿a litera
			{
				if( tmp <= 77 )
				{
					cout << (char)( tmp + 13 );
				}
				else
				{
					cout << (char)( tmp - 13 );
				}
			}
			else // cyfra
			{
				cout << s[i];
			}
		}
	}
	
	return 0;
}
