#include<iostream> // AC
#include<string>


using namespace std;


#define FORD(i,b,a) for(int i=b; i>=a; --i)


int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	int q, t[4] = { 6, 2, 4, 8 }, r, wyn = 0;
	
	cin >> q;
	
	while( q )
	{
		cin >> s;
		
		r = s.size();
		
		wyn += (int)( s[ r - 1 ] ) - 48;
		
		FORD(i,r-2,0)
		{
			wyn = ( wyn + ( ( (int)( s[i] ) - 48 ) * t[ ( r - 1 - i ) % 4 ] ) ) % 10;
		}
		
		if( wyn == 0 )
		{
			cout << "Tak\n";
		}
		else
		{
			cout << "Nie\n";
		}
		
		wyn = 0;
		
		--q;
	}
	
	return 0;
}
