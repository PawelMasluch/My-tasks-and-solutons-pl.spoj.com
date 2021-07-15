#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define FORD(i,b,a) for(int i=b; i>=a; --i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, *t, *ile = new int [2], *ind = new int [2];
	
	cin >> n;
	
	t = new int [n];
	
	ile[0] = ile[1] = 0;
	
	REP(i,0,n-1)
	{
		cin >> t[i];
		
		++ile[ t[i] % 2 ];
	}
	
	FORD(i,n-1,0)
	{
		ind[ t[i] % 2 ] = i + 1;
	}
	
	if( ile[0] == 1 )
	{
		cout << ind[0] << endl;
	}
	else
	{
		cout << ind[1] << endl;
	}
	
	return 0;
}
