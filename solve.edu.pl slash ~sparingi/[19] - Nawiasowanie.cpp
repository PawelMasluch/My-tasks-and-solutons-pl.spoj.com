#include<iostream> // AC
#include<string>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 500000; // maksymalna długość wejściowego wyrażenia nawiasowego


string s; // wejściowe wyrażenie nawiasowe

int n, ile[MAX_N], wyn = 0, przewaga = 0;


/*

n - długość wejściowego wyrażenia nawiasowego

ile[i] - liczba nawiasów zamykających będących na pozycjach i+1...n-1 ( 0 <= i <= n-1 )

wyn - minimalna liczba nawiasów do usunięcia z wejściowego wyrażenia nawiasowego, aby nowo powstałe wyrażenia nawiasowe było poprawne

przewaga - w czasie obliczania wyniku zadania (zmienna 'wyn') pamiętam bieżącą przewagę w ilości nawiasów otwierających nad zamykającymi

*/


int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> s;
	
	n = s.size();
	
	
	// Obliczenie tablicy 'ile'
	
	FORD(i,n-2,0)
	{
		ile[i] = ile[ i + 1 ]; // na pewno wartość ile[i] będzie co najmniej tak duża, jak ile[i+1] (  bo na przedziale nawiasów i+1...n-1 jest co najmniej tyle samo nawiasów zamykających, co na przedziale nawiasów (i+1)+1...n-1  )
		
		if( s[ i + 1 ] == ')' ) // jeśli i+1-szy nawias jest zamykający
		{
			++ile[i]; // to zwiększamy ile[i] o 1
		}
	}
	
	
	// Obliczenie wyniku zadania (zmienna 'wyn')
	
	REP(i,0,n-1) // przechodzimy wejściowe wyrażenie nawiasowe od lewej do prawej
	{
		if( s[i] == ')' ) // jeśli aktualny (czyli i-ty) nawias jest zamykający
		{
			--przewaga; // to zmiejszamy przewagę o 1
			
			if( przewaga < 0 ) // jeśli okazuje się, że przewaga jest ujemna
			{
				++wyn; // to tak naprawdę musimy usunąć i-ty nawias
				
				++przewaga; // skoro usunęliśmy i-ty nawias, to tak naprawdę musimy przywrócić wartość zmiennej 'przewaga' sprzed uwzględniania i-tego nawiasu
			}
		}
		else // aktualny (czyli i-ty) nawias jest otwierający (  tj. s[i] == '('  )
		{
			++przewaga; // to zwiększamy przewagę o 1
			
			if( ile[i] < przewaga ) // jeśli brakuje nam nawiasów zamykających, by przewagę zmniejszyć do zera
			{
				++wyn; // to tak naprawdę musimy usunąć i-ty nawias
				
				--przewaga; // skoro usunęliśmy i-ty nawias, to tak naprawdę musimy przywrócić wartość zmiennej 'przewaga' sprzed uwzględniania i-tego nawiasu
			}
		}
	}
	
	printf( "%d\n", wyn );
	
	return 0;
}
