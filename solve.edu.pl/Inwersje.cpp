#include<iostream> // 100 pkt
#include<new>

using namespace std;

typedef long long LL;

LL f(LL k, LL n)
{
	LL pocz=1, kon=n, sr, wyn;
	while(pocz<=kon)
	{
		sr = (pocz+kon)/2;
		if(sr*(sr-1)<=2*k)
		{
			wyn=sr;
			pocz=sr+1;
		}
		else
		{
			kon=sr-1;
		}
	}
	return wyn;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n,i,*t,m,temp,ile,k;
	
	cin>>n>>k;
	
	t = new LL [n+1];
	
	m = f(k,n);
	
	ile = k - (m*(m-1)/2);
	
	temp = n;
	
	for(i=1; i<=n-m-1; i++)
	{
		t[i]=i;
	}
	
	for(i=n-m+1; i<=n-ile; i++)
	{
		t[i] = temp;
		temp--;
	}
	
	t[n-m] = temp;
	temp--;
	
	for(i=n-ile+1; i<=n; i++)
	{
		t[i] = temp;
		temp--;
	}
	
	for(i=1; i<=n; i++)
	{
		cout<<t[i]<<" ";
	}
	cout<<endl;
	
	return 0;
	
}
