#include<iostream> // 100 pkt
#include<string>


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 1000000;


string s;

int n, suf[3][MAX_N + 2], R = 0;


/*

suf[r][i] - ile jest sufiksów s[i..n], ze ich suma cyfr daje reszte 'r' z dzielenia przez 3 oraz s[i-1] to cyfra parzysta ( r = 0,1,2 ; i = n+1, n, ..., 2 )

*/


void wczytaj()
{
	cin >> s;
	
	n = s.size();
	
	s = "0" + s;
}


void oblicz()
{
	// obiczenie reszty z dzielenia przez 3 sumy cyfr calego ciagu 
	
	REP(i,1,n)
	{
		R = (   R + ( s[i] - '0' )   ) % 3;
	}
	
	
	// warunki poczatkowe dla tablicy 'suf'
	
	REP(r,0,2)
	{
		suf[r][n+1] = 0;
	}
	
	if( ( s[n] - '0' ) % 2 == 0 )
	{
		++suf[0][n+1];
	}
	
	
	// obliczenie tablicy 'suf'
	
	int R_suf = 0;
	
	FORD(i,n,2)
	{
		REP(r,0,2)
		{
			suf[r][i] = suf[r][i+1];
		}
		
		R_suf = (   R_suf + ( s[i] - '0' )   ) % 3;
		
		if( ( s[i-1] - '0' ) % 2 == 0 )
		{
			++suf[R_suf][i];
		}
	}
	
	
	// obliczenie wyniku
	
	LL wyn = 0;
	
	int R_pref = 0;
	
	REP(i,0,n-1) // dla kazdego mozliwego prefiksu
	{
		R_pref = (   R_pref + ( s[i] - '0' )   ) % 3;
		
		wyn += suf[ ( R + 3 - R_pref ) % 3 ][i+2];
	}
	
	cout << wyn << endl;
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	wczytaj();
	
	oblicz();
	
	return 0;
}
