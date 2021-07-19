#include<iostream> // do sprawdzenia

using namespace std;

typedef long long LL;

int main()
{
	LL n;
	cin>>n;
	while(n%2==0)
	{
		n/=2;
	}
	if(n==1)
	{
		cout << "TAK\n";
	}
	else
	{
		cout << "NIE\n";
	}
	return 0;
}