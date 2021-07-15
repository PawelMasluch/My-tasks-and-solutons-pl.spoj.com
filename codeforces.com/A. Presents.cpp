#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,n) for(int i=0; i<n; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, *t, *wyn;
	
	cin >> n;
	
	t = new int [n];
	
	wyn = new int [n];
	
	REP(i,n)
	{
		cin >> t[i];
		
		--t[i];
	}
	
	REP(i,n)
	{
		wyn[ t[i] ] = i;
	}
	
	REP(i,n)
	{
		cout << wyn[i] + 1 << " ";
	}
	
	cout << endl;
	
	return 0;
}
