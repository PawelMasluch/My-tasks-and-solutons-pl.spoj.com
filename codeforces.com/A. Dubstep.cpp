#include<iostream> // AC
#include<string>
#include<vector>
 
 
using namespace std;
 
 
typedef pair < int, int > PII;
 
typedef vector < PII > VPII;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define PB push_back
 
#define MP make_pair
 
#define ST first
 
#define ND second
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s, wyn = "";
	
	cin >> s;
	
	s = "WUB" + s + "WUB";
	
	VPII v;
	
	int n = s.size(), r = 0, pocz, kon;
	
	REP(i,0,n-3)
	{
		if( s.substr( i, 3 ) == "WUB" )
		{
			v.PB( MP( i, i + 2 ) );
			
			++r;
		}
	}
	
	REP(i,1,r-1)
	{
		pocz = v[ i - 1 ].ND + 1;
		
		kon = v[i].ST - 1;
		
		if( pocz <= kon )
		{
			REP(j,pocz,kon)
			{
				wyn = wyn + s[j];
			}
			
			wyn = wyn + ' ';
		}
	}
	
	cout << wyn << endl;
}
