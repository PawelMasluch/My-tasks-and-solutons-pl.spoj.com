#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n;
	
	cin >> n;
	
	REP(i,1,(n+1)/2)
	{
		REP(j,1,((n+1)/2)-i)
		{
			cout << "*";
		}
		
		REP(j,1,2*i-1)
		{
			cout << "D";
		}
		
		REP(j,1,((n+1)/2)-i)
		{
			cout << "*";
		}
		
		cout << endl;
	}
	
	REP(i,1,(n-1)/2)
	{
		REP(j,1,i)
		{
			cout << "*";
		}
		
		REP(j,1,n-2*i)
		{
			cout << "D";
		}
		
		REP(j,1,i)
		{
			cout << "*";
		}
		
		cout << endl;
	}
	
	return 0;
}
