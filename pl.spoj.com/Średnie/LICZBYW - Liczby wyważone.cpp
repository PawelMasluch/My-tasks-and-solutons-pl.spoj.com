#include<iostream> // AC
#include<string>


using namespace std;


#define FORD(i,b,a) for(int i=b; i>=a; --i)


int r(string &s)
{
	int n = s.size(), temp = 0;
	
	temp += (int)( s[ n - 1 ] ) - 48;
	
	if( n >= 2 )
	{
		temp += 10 * ( (int)( s[ n - 2 ] ) - 48 );
	}
	
	return temp % 4;
}


string suma(string &a, char &b) // b - liczba 1-cyfrowa
{
	string wyn = "";
	
	int n = a.size(), p = 0, temp = (int)( a[ n - 1 ] ) + (int)( b ) - 96 + p;
	
	p = temp / 10;
	
	wyn = (char)( 48 + ( temp % 10 ) ) + wyn;
	
	FORD(i,n-2,0)
	{
		temp = (int)( a[i] ) - 48 + p;
		
		p = temp / 10;
		
		wyn = (char)( 48 + ( temp % 10 ) ) + wyn;
	}
	
	if( p == 1 )
	{
		wyn = '1' + wyn;
	}
	
	return wyn;
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	string a;
	
	char b;
	
	int q, pom;
	
	cin >> q;
	
	while( q )
	{
		cin >> a;
		
		pom = r( a );
		
		if( pom >= 2 )
		{
			b = (char)( 54 - pom );
		}
		else
		{
			b = (char)( 50 - pom );
		}
		
		cout << suma( a, b ) << endl;
		
		--q;
	}
	
	return 0;
}
