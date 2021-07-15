#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, a, *pref, pocz = 0, kon = 0, *b, wyn = 0, mini = 0, S = 0, ind = 0;
	
	/*
	
	"a" - n-elementowy ci?g bit?w
	
	"pref" - ci?g sum prefiksowych ci?gu "a"
	
	"b" - przekszta?cony ci?g "a" : b[i] = 1 dla a[i] = 0, b[i] = -1 dla a[i] = 1
	
	(pocz, kon] - kra?ce podci?gu ci?gu "b" o najwi?kszej sumie (0<=pocz<kon<=n)
	
	mini - minimalna suma prefiksowa ci?gu "b"
	
	ind - oznacza, kt?ry prefiks ci?gu "b" ma minimaln? sum? (0<=ind<=n)
	
	S - aktualna suma prefiksowa ci?gu "b"
	
	*/
	
	cin >> n;
	
	b = new int [n];
	
	pref = new int [n];
	
	pref[0] = 0;
	
	REP(i,0,n-1)
	{
		cin >> a;
		
		b[i] = ( a == 0 ) ? 1 : -1 ;
		
		pref[ i + 1 ] = pref[i] + a;
	}
	
	if( pref[n] == n ) // przypadek brzegowy : nie mo?emy zamieni? ?adnego zera na jedynk?, bo ?adnego zera w ci?gu "a" nie ma
	{
		cout << n - 1 << endl; // zamieniamy jedn? jedynk? na zero, wi?c w ci?gu jest teraz (n-1) jedynek
		
		return 0;
	}
	
	REP(i,0,n-1)
	{
		S += b[i]; // aktualizacja sumy prefiksowej
		
		if( S < mini ) // aktualizacja zmiennej mini oraz ind
		{
			mini = S;
			
			ind = i + 1;
		}
		
		if( wyn < S - mini ) // aktualizacja zmiennych wyn, pocz, kon
		{
			wyn = S - mini;
			
			pocz = ind;
			
			kon = i + 1;
		}
	}
	
	++pocz; // chcemy mie? przedzia? lewostronnie domkni?ty
	
	cout << pref[ pocz - 1 ] + ( kon - pocz + 1 ) - ( pref[ kon ] - pref[ pocz - 1 ] ) + ( pref[n] - pref[ kon ] ) << endl;
	
	return 0;
}
