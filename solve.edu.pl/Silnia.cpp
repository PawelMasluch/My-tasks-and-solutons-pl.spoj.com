#include<iostream> // 100 pkt
using namespace std;
int main()
{
	long long n,i,wyn=0;
	cin>>n;
	for(i=5; i<=n; i*=5)
	{
		wyn+=(n/i);	
	}
	cout<<wyn<<endl;
	return 0;
}