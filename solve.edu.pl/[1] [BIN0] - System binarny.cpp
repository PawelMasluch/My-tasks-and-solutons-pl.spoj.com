#include<iostream> // 100 pkt
#include<vector>
using namespace std;
int main()
{
	vector <int> v;
	long long n;
	int t,r=0,i,j;
	cin>>t;
	for(i=0; i<t; i++)
	{
		cin>>n;
		if(!n) 
		{
			cout<<"0";
		}
		else 
		{
			while(n>0)
			{
				v.push_back(n%2);
				n/=2;
				r++;
			}
			for(j=r-1; j>=0; j--)
			{
				cout<<v[j];
			}
		}
		cout<<"\n";
		v.clear();
		r=0;
	}
	return 0;
}
