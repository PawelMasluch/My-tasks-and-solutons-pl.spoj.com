#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, k, *ile = new int [6], a;
	
	REP(i,0,5)
	{
		ile[i] = 0;
	}
	
	cin >> n >> k;
	
	REP(i,1,n)
	{
		cin >> a;
		
		++ile[a];
	}
	
	REP(i,1,5)
	{
		ile[i] += ile[ i - 1 ];
	}
	
	cout << ile[ 5 - k ] / 3 << endl;
	
	return 0;
}
