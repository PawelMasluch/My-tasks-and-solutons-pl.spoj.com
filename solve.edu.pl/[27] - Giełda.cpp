#include<iostream> // 100 pkt
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int n,a,i,wyn=0,mini=1000000001;
	cin>>n;
	for(i=1; i<=n; i++)
	{
		cin>>a;
		mini=min(mini,a);
		wyn=max(wyn,a-mini);
	}
	cout<<wyn<<endl;
	return 0;
}
