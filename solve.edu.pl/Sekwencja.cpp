#include<cstdio> // 100 pkt
#include<new>

#define REP(i,a,b) for(i=a; i<=b; i++)

using namespace std;

struct pole
{
	int x;
	int y;
};

inline int max(int a, int b)
{
	return (a>b) ? a : b ;
}

int main()
{
	bool *czy_aktualne;
	
	pole *gdzie;
	
	int N, M, **plansza, i, j, *wyn, liczba, *kolumna1, *kolumna2;
	
	scanf("%d%d", &N, &M);
	
	wyn = new int [N+M];
	
	kolumna1 = new int [M+1];
	
	kolumna2 = new int [M+1];
	
	czy_aktualne = new bool [(N*M)+1];
	
	gdzie = new pole [(N*M)+1];
	
	plansza = new int *[N+1];
	
	REP(i,1,N)
	{
		plansza[i] = new int [M+1];
	}
	
	REP(i,1,N)
	{
		REP(j,1,M)
		{
			scanf("%d", &plansza[i][j]);
			
			gdzie[plansza[i][j]].x = i;
			gdzie[plansza[i][j]].y = j;
		}
	}
	
	REP(i,1,N*M)
	{
		czy_aktualne[i] = true;
	}
	
	REP(j,1,M)
	{
		kolumna1[j] = 0;
			
		kolumna2[j] = N+1;
	}
	
	REP(liczba,1,N*M) // dla każdej liczby
	{
		if(czy_aktualne[liczba]==true)
		{
			wyn[gdzie[liczba].x + gdzie[liczba].y - 1] = liczba;
			
			REP(j,gdzie[liczba].y + 1, M) // dla każdej kolumny z prawej
			{
				if(kolumna1[j] + 1 <= gdzie[liczba].x - 1)
				{
					REP(i,kolumna1[j] + 1, gdzie[liczba].x - 1)
					{
						czy_aktualne[plansza[i][j]] = false;
					}
					
					kolumna1[j] = gdzie[liczba].x - 1;
				}
			}
			
			REP(j,1,gdzie[liczba].y - 1) // dla każdej kolumny z lewej
			{
				if(kolumna2[j] - 1 >= gdzie[liczba].x + 1)
				{
					REP(i,gdzie[liczba].x + 1, kolumna2[j] - 1)
					{
						czy_aktualne[plansza[i][j]] = false;
					}
					
					kolumna2[j] = gdzie[liczba].x + 1;
				}
			}
			
		}
	}
	
	REP(i,1,N+M-1)
	{
		printf("%d ", wyn[i]);
	}
	printf("\n");
	
	return 0;
	
}
