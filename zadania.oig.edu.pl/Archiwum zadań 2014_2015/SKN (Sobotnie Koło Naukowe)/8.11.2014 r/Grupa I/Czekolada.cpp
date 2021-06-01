#include<iostream> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 100000;


int n, k, PREF[MAX_N+1], nr[MAX_N+1], wyn = 0;


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> n >> k;
	
	PREF[0] = 0;
	
	nr[0] = 0;
	
	char zn;
	
	int rodzynki = 0;
	
	REP(i,1,n)
	{
		cin >> zn;
		
		if( zn == '#' )
		{
			++rodzynki;
			
			nr[ rodzynki ] = i;
		}
		
		PREF[i] = rodzynki;
	}
	
	int dl;
	
	REP(i,1,n)
	{
		wyn = max( wyn, i - nr[ max(0, PREF[i] - k ) ] );
	}
	
	cout << wyn << endl;
	
	return 0;
}
