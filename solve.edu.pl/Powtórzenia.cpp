#include<cstdio> // 100 pkt
#include<algorithm>
#include<new>
using namespace std;
void input(int *t, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &t[i]);
	}
}
bool f(int *t, int n)
{
	int j;
	for(j=1; j<=n-2; j++)
	{
		if(t[j]==t[j-1] && t[j]==t[j+1])
		{
			return true;
		}
	}
	return false;
}
void output(int *t, int n)
{
	if(f(t,n)==true)
	{
		printf("TAK\n");
	}
	else
	{
		printf("NIE\n");
	}
}
int main()
{
	int Q,n,i,j,*t;
	scanf("%d", &Q);
	for(i=0; i<Q; i++)
	{
		scanf("%d", &n);
		t = new int [n];
		input(t,n);
		sort(t,t+n);
		output(t,n);
		delete [] t;
	}
	return 0;
}
