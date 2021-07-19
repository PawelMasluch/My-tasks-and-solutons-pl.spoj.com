#include<iostream>

using namespace std;

int main()
{
	char z;
	long long n,i,wyn=0,ile0=0,ile1=0;
	cin>>n;
	for(i=1; i<=n; i++)
	{
		cin>>z;
		if(z=='0')
		{
			ile0++;
		}
		else // z == '1'
		{
			ile1++;
			wyn += ile0;
		}
	}
	cout<<wyn<<endl;
	
	return 0;
}