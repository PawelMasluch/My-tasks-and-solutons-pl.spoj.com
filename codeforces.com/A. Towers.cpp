#include<iostream> // AC
#include<new>
#include<algorithm>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int max(int a, int b)
{
	return (a>b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, *t, wyn = 1, ile = 1, temp = 1;
	
	/*
	
	wyn - najwi?ksza ilo?? tych samych element?w
	
	temp - aktualna liczba tych samych element?w
	
	ile - liczba r?nych liczb w ci?gu
	
	*/
	
	cin >> n;
	
	t = new int [n];
	
	REP(i,0,n-1)
	{
		cin >> t[i];
	}
	
	sort( t, t + n );
	
	REP(i,1,n-1)
	{
		if( t[i] == t[ i - 1 ] )
		{
			++temp;
		}
		else
		{
			temp = 1;
			
			++ile;
		}
		
		wyn = max( wyn, temp );
	}
	
	cout << wyn << " " << ile << endl;
	
	return 0;
}
