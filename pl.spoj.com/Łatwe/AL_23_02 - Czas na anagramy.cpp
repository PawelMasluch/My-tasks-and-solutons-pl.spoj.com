#include<iostream> // AC
#include<string>
#include<new>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define D delete


int ile(string &a, string &b)
{
	int *t1 = new int [26], *t2 = new int [26], ra = a.size(), rb = b.size(), pom;
	
	REP(i,0,25)
	{
		t1[i] = t2[i] = 0;
	}
	
	REP(i,0,ra-1)
	{
		++t1[ (int)( a[i] ) - 97 ];
	}
	
	REP(i,0,rb-1)
	{
		++t2[ (int)( b[i] ) - 97 ];	
	}
	
	REP(i,0,25)
	{
		pom = min( t1[i], t2[i] );
		
		t1[i] -= pom;
		
		t2[i] -= pom;
		
		ra -= pom;
		
		rb -= pom;
	}
	
	D [] t1;
	
	D [] t2;
	
	return max( ra, rb );
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	string a, b;
	
	int q;
	
	cin >> q;
	
	while( q )
	{
		cin >> a >> b;
		
		cout << ile( a, b ) << endl;
		
		--q;
	}
	
	return 0;
}

