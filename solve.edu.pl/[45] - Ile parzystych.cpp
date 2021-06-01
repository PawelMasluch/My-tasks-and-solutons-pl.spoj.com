#include<iostream> // 100 pkt
using namespace std;
inline int f(int x)
{
	return (!(x&1)) ? 1 : 0 ;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n,a,i,wyn=0;
	cin>>n;
	for(i=1; i<=n; i++)
	{
		cin>>a;
		wyn+=f(a);
	}
	cout<<wyn<<endl;
	return 0;
}
