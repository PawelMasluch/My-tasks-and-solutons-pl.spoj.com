#include<iostream> // AC
#include<string>
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	int *a = new int [4], r, wyn = 0;
	
	REP(i,0,3)
	{
		cin >> a[i];
	}
	
	cin >> s;
	
	r = s.size();
	
	REP(i,0,r-1)
	{
		wyn += a[ (int)( s[i] ) - 49 ];
	}
	
	cout << wyn << endl;
	
	return 0;
}
