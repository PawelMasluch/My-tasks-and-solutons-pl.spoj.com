#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,n) for(int i=0; i<n; ++i)
 
 
int f(int x)
{
	return (x>=0) ? x : -x ;
}
 
 
int min(int a, int b)
{
	return (a<b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string a, b;
	
	int n, wyn = 0, pom1, pom2, temp;
	
	cin >> n >> a >> b;
	
	REP(i,n)
	{
		pom1 = (int)( a[i] ) - 48;
		
		pom2 = (int)( b[i] ) - 48;
		
		temp = f( pom1 - pom2 );
		
		wyn += min( temp, 10 - temp );
	}
	
	cout << wyn << endl;
	
	return 0;
}
