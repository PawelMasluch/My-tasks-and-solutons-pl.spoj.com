#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string jednosc[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" }, dziesiatka[9] = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" }, nascie[9] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	
	int n;
	
	cin >> n;
	
	if( n <= 9 )
	{
		cout << jednosc[n] << endl;
	}
	else
	{
		if( n % 10 == 0 )
		{
			cout << dziesiatka[ ( n / 10 ) - 1 ] << endl;
		}
		else
		{
			if( n <= 19 )
			{
				cout << nascie[ n - 11 ] << endl;
			}
			else
			{
				cout << dziesiatka[ ( n / 10 ) - 1 ] << "-" << jednosc[ n % 10 ] << endl;
			}
		}
	}
	
	return 0;
}
