#include<iostream> // 100 pkt

using namespace std;

typedef long long LL;

int main()
{
	LL N, wyn = 1;
	
	cin >> N;
	
	while( N != 1 )
	{
		if( N & 1 )
		{
			N = ( 3 * N ) + 1;
		}
		else
		{
			N >>= 1;
		}
		
		++wyn;
	}
	
	cout << wyn << endl;
	
	return 0;
}
