#include<iostream> // 100 pkt
#include<string>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	cin >> s;
	
	int n = s.size(), ind = n - 2, S = 0;
	
	while( ind >= 0 )
	{
		if( s[ ind ] != 'c' )
		{
			break;
		}
		else
		{
			--ind;
		}
	}
	
	if( ind == -1 )
	{
		cout << "NIE\n";
	}
	else
	{
		REP(i,ind+1,n-1)
		{
			S += s[i] - 'a' + 1;
		}
		
		--S;
		
		REP(i,0,ind-1)
		{
			cout << s[i];
		}
		
		cout << (char)( s[ ind ] + 1 );
		
		REP(i,1,S)
		{
			cout << 'a';
		}
		
		cout << endl;
	}
	
	return 0;
}
