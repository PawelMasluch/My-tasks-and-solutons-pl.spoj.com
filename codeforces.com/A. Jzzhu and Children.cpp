#include<iostream> // AC
#include<new>
#include<queue>
 
 
using namespace std;
 
 
typedef pair < int, int > PII;
 
typedef queue < PII > QPII;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define MP make_pair
 
#define ST first
 
#define ND second
 
#define P push
 
#define F front
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	QPII Q;
	
	int n, m, *a, r = 0, ile, ind;
	
	cin >> n >> m;
	
	a = new int [n];
	
	REP(i,0,n-1)
	{
		cin >> a[i];
		
		Q.P( MP( 0, i ) );
		
		++r;
	}
	
	while( r >= 2 ) // dop?ki co najmniej 2 osoby w kolejce
	{
		ile = Q.F().ST;
		
		ind = Q.F().ND;
		
		Q.pop();
		
		if( ile + m >= a[ ind ] ) // je?li zadowoli?em pierwsz? osob? w kolejce
		{
			--r; // kolejka si? zmniejszy?a
		}
		else
		{
			Q.P( MP( ile + m, ind ) ); // ta osoba idzie na koniec z wi?ksz? liczb? cukierk?w
		}
	}
	
	cout << Q.F().ND + 1 << endl;
	
	return 0;
}
