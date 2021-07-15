#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
string WYN[101][11];
 
int n, t;
 
 
void preprocessing()
{
	REP(i,1,100)
	{
		REP(j,2,10)
		{
			WYN[i][j] = "";
		}
	}
	
	REP(j,2,9)
	{
		WYN[1][j] = (char)( 48 + j );
	}
	
	WYN[1][10] = "1";
	
	REP(i,2,100)
	{
		REP(j,2,10)
		{
			WYN[i][j] = WYN[ i - 1 ][j] + "0";
		}
	}
	
	WYN[1][10] = "";
}
 
 
void wczytaj()
{
	cin >> n >> t;
}
 
 
void wypisz()
{
	if( WYN[n][t] == "" )
	{
		cout << "-1\n";
	}
	else
	{
		cout << WYN[n][t] << endl;
	}
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	preprocessing();
	
	wczytaj();
	
	wypisz();
	
	return 0;
}
