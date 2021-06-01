#include<algorithm> // 100 pkt
#include<new>
#include<cstdio>
using namespace std;
bool f(int *t, int n)
{
		int j;
		for(j=2; j<=n-1; j++)
		{
			if(t[j]==t[j-1] && t[j-1]==t[j-2])
			{
				return true;
			}
		}
		return false;
}
int main()
{
	int Q,i,*t,j,n;
	scanf("%d", &Q);
	for(i=0; i<Q; i++)
	{
		scanf("%d", &n);
		t=new int[n];
		for(j=0; j<n; j++)
		{
			scanf("%d", &t[j]);
		}
		sort(t,t+n);
		if(f(t,n)==true) 
		{
			printf("TAK\n");
		}
		else  
		{
			printf("NIE\n");
		}
		delete [] t;
	}
	return 0;
}
