#include<iostream> // 100 pkt
#include<string>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


string s;

int ile[26], r, ind = 0;


int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> s;
	
	r = s.size();
	
	REP(i,0,r-1)
	{
		++ile[ s[i] - 'a' ];
	}
	
	while( ind < 26  &&  !( ile[ ind ] & 1 ) )
	{
		++ind;
	}
	
	REP(i,ind+1,25)
	{
		if( ile[i] & 1 )
		{
			--ile[i];
		}
	}
	
	REP(i,0,25)
	{
		REP(j,1,ile[i]/2)
		{
			cout << (char)( i + 97 );
		}
	}
	
	if( ind < 26 )
	{
		cout << (char)( ind + 97 );
    }
    
    FORD(i,25,0)
	{
		REP(j,1,ile[i]/2)
		{
			cout << (char)( i + 97 );
		}
	}
	
	cout << endl;
	
	return 0;
}
