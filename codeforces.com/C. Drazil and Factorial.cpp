#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define FORD(i,b,a) for(int i=b; i>=a; --i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s, wyn;
	
	int temp, n, prime[4] = { 2, 3, 5, 7 }, ile[4] = { 0, 0, 0, 0 }, t[10][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 1, 0, 0 }, { 3, 1, 0, 0 }, { 3, 1, 1, 0 }, { 4, 2, 1, 0 }, { 4, 2, 1, 1 }, { 7, 2, 1, 1 }, { 7, 4, 1, 1 } };
	
	cin >> n >> s;
	
	REP(i,0,n-1)
	{
		temp = (int)( s[i] ) - 48;
		
		REP(j,0,3)
		{
			ile[j] += t[ temp ][j];
		}
	}
	
	FORD(i,3,0)
	{
		temp = ile[i];
		
		REP(j,1,temp)
		{
			wyn = wyn + (char)( prime[i] + 48 );
			
			FORD(k,i,0)
			{
				ile[k] -= t[ prime[i] ][k];
			}
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
