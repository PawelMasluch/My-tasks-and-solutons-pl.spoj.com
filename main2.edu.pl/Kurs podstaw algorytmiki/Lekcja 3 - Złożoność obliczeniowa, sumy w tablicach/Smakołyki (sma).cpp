#include<iostream>
#include<new>

using namespace std;

typedef long long LL;

int main()
{
	LL n, m, *t, i, j, *pom, wyn = 0;
	
	cin>>n>>m;
	
	t = new LL [n+2];
	
	pom = new LL [m+1];
	
	for(i=1; i<=m; i++)
	{
		pom[i] = 0;
	}
	
	for(i=1; i<=n; i++)
	{
		cin>>t[i];
	}
	
	t[n+1] = t[n]; 
	
	i=1;
	j=i; 
	
	while(i<=n)
	{
		while(pom[t[j]]!=1)
		{
			pom[t[j]]++;
			j++;
		}
		wyn += j-i;
		pom[t[i]]--;
		i++;
	}
	
	cout<<wyn<<endl;
	
	return 0;
}