#include<iostream> // 100 pkt

using namespace std;

int f(int x)
{
	return (x>=0) ? x : -x;
}

int main()
{
	int Q, a, b, c;
	
	cin >> Q;
	
	while( Q > 0 )
	{
		cin >> a >> b >> c;
		
		if( a < b + c  &&  a > f(b-c) )
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
		
		--Q;
	}
	
	return 0;
}
