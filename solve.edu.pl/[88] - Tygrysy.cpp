#include<iostream> // 100 pkt
#include<algorithm>
using namespace std;
int wyszukaj_binarnie(long long *t, int pocz, int kon, long long szukany)
{
	int ind,sr;
	while(pocz<=kon)
	{
		sr=(pocz+kon)/2;
		if(2*t[sr]>szukany)
		{
			ind=sr;
			kon=sr-1;
		}
		else
		{
			pocz=sr+1;
		}
	}
	return ind;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n,i,wynik=0;
	cin>>n;
	long long t[n];
	int naj[n]; naj[0]=0;
	for(i=0; i<n; i++)
	{
		cin>>t[i];
	}
	sort(t,t+n);
	for(i=1; i<n; i++)
	{
		if(t[i]==t[i-1])
		{
			naj[i]=naj[i-1];
		}
		else
		{
			naj[i]=wyszukaj_binarnie(t,0,i,t[i]);
		}
	}
	for(i=0; i<n; i++)
	{
		wynik=max(wynik,i-naj[i]+1);
	}
	cout<<wynik<<endl;
	return 0;
}
