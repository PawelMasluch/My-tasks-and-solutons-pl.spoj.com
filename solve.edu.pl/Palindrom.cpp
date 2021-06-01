#include<iostream> // 100 pkt
#include<string>

using namespace std;

bool f(string &s)
{
	int r = s.size(), i;
	
	for(i=0; 2*i < r-1; ++i)
	{
		if( s[i] != s[r-1-i] )
		{
			return false;
		}
	}
	
	return true;
}

void g(string &s)
{
	if( f(s) == true )
	{
		cout << "TAK\n";
	}
	else
	{
		cout << "NIE\n";
	}
}

int main()
{
	string s;
	
	int Q;
	
	cin >> Q;
	
	while( Q )
	{
		cin >> s;
		
		g(s);
		
		--Q;
	}
		
	return 0;
}
