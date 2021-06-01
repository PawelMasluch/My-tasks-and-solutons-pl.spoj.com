#include<cstdio> // 100 pkt
#include<new>

using namespace std;

inline int max(int a, int b)
{
	return (a>b) ? a : b ;	
}

inline int min(int a, int b)
{
	return (a>b) ? b : a ;	
}

int main()
{
	int N,i,j,**T,k,temp=0,wyn=1000000000,ind;
	
	scanf("%d", &N);
	
	T = new int *[N+1];
	for(i=0; i<=N; i++)
	{
		T[i] = new int [N+1];
	}
	
	for(i=N; i>=1; i--)
	{
		for(j=i; j<=N; j++)
		{
			for(k=i; k<=j; k++)
			{
				if(k-1>=i)
				{
					temp = max(temp, k + T[i][k-1]);
				}
				
				if(k+1<=j)
				{
					temp = max(temp, k + T[k+1][j]);
				}
				
				wyn = min(wyn,temp);
				
				temp = 0;
				
			}
			
			T[i][j] = wyn;
			
			wyn = 1000000000;
		
		}
	}
	
	printf("%d\n", T[1][N]);
	
	if(N==1)
	{
		printf("0\n");
		return 0;
	}
	
	for(k=1; k<=N; k++)
	{
		if(k-1>=1)
		{
			temp = max(temp, k + T[1][k-1]);
		}
		
		if(k+1<=N)
		{
			temp = max(temp, k + T[k+1][N]);
		}
		
		if(temp<wyn)
		{
			wyn = temp;
			ind = k;
		}
		
		temp = 0;
		
	}
	
	printf("%d\n", ind);
	
	return 0;
	
}
