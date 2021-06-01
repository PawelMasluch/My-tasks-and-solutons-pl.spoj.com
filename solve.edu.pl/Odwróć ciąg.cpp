#include<iostream> // 100 pkt
#include<new>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int n,i,*t;
	cin>>n;
	t = new int [n];
	for(i=0; i<=n-1; i++)
	{
		cin>>t[i];
	}
	for(i=n-1; i>=0; i--)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
