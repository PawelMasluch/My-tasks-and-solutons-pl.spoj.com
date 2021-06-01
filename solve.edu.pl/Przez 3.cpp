#include<iostream> // 100 pkt
#include<string>


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)


int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	int n, ile = 0;
	
	cin >> s;
	
	n = s.size();
	
	REP(i,n)
	{
		ile += ( s[i] - '0' );
	}
	
	if( ile % 3 )
	{
		cout << "NIE\n";
	}
	else
	{
		cout << "TAK\n";
	}
	
	return 0;
}
