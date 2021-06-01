#include<cstdio> // 100 pkt
#include<new>

using namespace std;

typedef long long LL;

LL bin(LL *S, LL n, LL value) // takie sr, ?e S[sr-1]<value<=S[sr] ; S - rosn?cy
{
	LL pocz=1,kon=n-1,sr;
	
	while(pocz<=kon)
	{
		sr = (pocz+kon)/2;
		
		if(S[sr-1]<value)
		{
			if(S[sr]>=value)
			{
				return sr;
			}
			pocz=sr+1;
		}
		else
		{
			kon=sr-1;
		}
	}
	
	return -1;
}

#define INF 1000000000000000001

LL najdluzszy_podciag_rosnacy(LL *t, LL n)
{
	LL *S = new LL [n+2], i, j, pom; 
	
	S[0] = -INF;
	for(i=1; i<=n+1; i++)
	{
		S[i] = INF;
	}
	
	for(i=0; i<=n-1; i++)
	{	
		S[bin(S,n+2,t[i])] = t[i];	
	}
	
	i=n+1;
	while(S[i]==INF)
	{
		i--;
	}
	
	delete [] S;
	
	return i;
}

int main()
{
	LL m,i,n,*t,j;
	scanf("%lld", &m);
	for(i=1; i<=m; i++)
	{
		scanf("%lld", &n);
		t = new LL [n];
		for(j=0; j<=n-1; j++)
		{
			scanf("%lld", &t[j]);
		}
		printf("%lld\n", najdluzszy_podciag_rosnacy(t,n));
		delete [] t;
	}
}
