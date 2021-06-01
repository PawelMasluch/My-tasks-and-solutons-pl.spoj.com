#include<cstdio> // 100 pkt
#include<new> // 1<=n<=2000 ; 1<=a_i<=10^6

#define REP(i,a,b) for(i=a; i<=b; i++)
#define FORD(i,b,a) for(i=b; i>=a; i--)

using namespace std;

int max(int a, int b)
{
	return (a>b) ? a : b ;
}

int main()
{
	int N, i, j, **DP, /***gdzie,*/ *pref, *t/*, pocz, kon, num*/;
	
	scanf("%d", &N);
	
	t = new int [N];
	
	pref = new int [N+1];
	pref[0] = 0;
	
	DP = new int *[N];
	
	//gdzie = new int *[N];
	
	REP(i,0,N-1)
	{
		//gdzie[i] = new int [N];
		DP[i] = new int [N];
	}
	
	REP(i,0,N-1)
	{
		scanf("%d", &t[i]);
		pref[i+1] = pref[i] + t[i];
		DP[i][i] = t[i];
		//gdzie[i][i] = i;
	}
	
	FORD(i,N-1,0)
	{
		REP(j,i+1,N-1)
		{
			/*if(t[i] + pref[j+1] - pref[i+1] - DP[i+1][j] > t[j] + pref[j] - pref[i] - DP[i][j-1])
			{
				DP[i][j] = t[i] + pref[j+1] - pref[i+1] - DP[i+1][j];
				gdzie[i][j] = i;
			}
			else
			{
				DP[i][j] = t[j] + pref[j] - pref[i] - DP[i][j-1];
				gdzie[i][j] = j;
			}*/
			DP[i][j] = max(t[i] + pref[j+1] - pref[i+1] - DP[i+1][j], t[j] + pref[j] - pref[i] - DP[i][j-1]);
		}
	}
	
	/*pocz = 0; 
	kon = N-1;
	num = 1;
	
	while(pocz<=kon)
	{
		if(num % 2 == 1) // jesli teraz m?j ruch
		{
			printf("A : t[%d] = %d\n", gdzie[pocz][kon] + 1, t[gdzie[pocz][kon]]);
		}
		else
		{
			printf("B : t[%d] = %d\n", gdzie[pocz][kon] + 1, t[gdzie[pocz][kon]]);	
		}
		
		if(gdzie[pocz][kon] == pocz)
		{
			pocz++;
		}
		else
		{
			kon--;
		}
		
		num++;
	}
	
	printf("A : %d\nB : %d\n", DP[0][N-1], pref[N] - DP[0][N-1]);*/
	
	printf("%d %d\n", DP[0][N-1], pref[N] - DP[0][N-1]);
	
	return 0;
}

/*
	test :
	
	22
	9 8 2 1 2 1 3 6 5 100 8 90 12 34 23 12 6 9 1 1 4 2
	
*/
