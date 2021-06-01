#include<iostream> // 100 pkt
using namespace std;
int main()
{
	int n,q,i;
	cin>>q;
	for(i=0; i<q; i++)
	{
	cin>>n;
	if(n%4==0)
	{
		if(n%100==0 && n%400!=0)
		{
			cout<<"NIE\n";
		}
		else
		{
				cout<<"TAK\n";
		}
	}
	else
	{
		cout<<"NIE\n";
	}
	}
	return 0;
}
