#include<iostream> // 100 pkt
using namespace std;
void f(int n)
{
	char z;
	int i,ile=0,wyn=0;
	for(i=0; i<n; i++)
	{
		cin>>z;
		if(z=='B')
		{
			ile++;
		}
		else
		{
			wyn=max(wyn,ile);
			ile=0;
		}
	}
	wyn=max(wyn,ile);
	if(n==1)
	{
		cout<<0<<endl;
	}
	else
	{
		cout<<wyn+1<<"\n";
	}
}
int main()
{
	int n;
	cin>>n;
	f(n);
	return 0;
}
