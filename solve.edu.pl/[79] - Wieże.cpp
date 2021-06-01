#include<iostream> // 100 pkt
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0);
	ll s1=0,s2=0;
	int n,m,i,i1,i2,wyn=0;
	cin>>n>>m;
	i1=n-1; i2=m-1;
	int t1[n],t2[m];
	for(i=0; i<n; i++)
	{
		cin>>t1[i];
		s1+=t1[i];
	}
	for(i=0; i<m; i++)
	{
		cin>>t2[i];
		s2+=t2[i];
	}
	while(s1!=s2)
	{
		if(s1>s2)
		{
			s1-=t1[i1];
			i1--;
			wyn++;
		}
		else
		{
			s2-=t2[i2];
			i2--;
			wyn++;
		}
	}
	cout<<wyn<<endl;
	return 0;
}
