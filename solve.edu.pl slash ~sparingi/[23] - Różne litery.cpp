#include<iostream> // 100 pkt
#include<string>
#include<algorithm>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int A = 26;


string s;

int n, ile[A], rozne = 0;


void oblicz()
{
	cin >> s;
	
	n = s.size();
	
	REP(i,0,n-1)
	{
		--ile[ s[i] - 'a' ];
		
		if( ile[ s[i] - 'a' ] == -1 )
		{
			++rozne;
		}
	}
	
	sort( ile, ile + A );
	
	REP(i,0,rozne-1)
	{
		ile[i] *= (-1);
	}
	
	REP(i,1,rozne-1)
	{
		ile[i] += ile[ i - 1 ];
	}
	
	REP(i,0,rozne-1)
	{
		cout << n - ile[i] << " ";
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	oblicz();
	
	return 0;
}
