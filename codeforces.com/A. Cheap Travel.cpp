#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, m, a, b, wyn;
	
	cin >> n >> m >> a >> b;
	
	if( b < m * a ) // je?li bardziej op?aca si? kupowa? jeden bilet na m kurs?w ni? m bilet?w na jeden kurs
	{
		wyn = ( n / m ) * b;
		
		if( b < ( n % m ) * a ) // je?li op?aca si? kupi? dodatkowy bilet na m kurs?w ni? (n % m) bilet?w na jeden kurs
		{
			wyn += b;
		}
		else
		{
			wyn += ( n % m ) * a;
		}
	}
	else
	{
		wyn = n * a;
	}
	
	cout << wyn << endl;
	
	return 0;
}
