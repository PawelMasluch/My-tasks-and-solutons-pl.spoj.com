#include<iostream> // 100 pkt


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)

#define FORD(i,n) for(int i=n-1; i>=0; --i)


const int MAX_N = 1000, MAX_M = 1000;


char T[MAX_N][MAX_M];

int N, M;


int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> N >> M;
	
	REP(i,N)
	{
		REP(j,M)
		{
			cin >> T[i][j];
		}
	}
	
	FORD(j,M)
	{
		REP(i,N)
		{
			cout << T[i][j];
		}
		
		cout << endl;
	}
	
	return 0;
}
