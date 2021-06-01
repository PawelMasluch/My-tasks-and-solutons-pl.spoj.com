#include<iostream> // 100 pkt
#include<string>
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)

#define PB push_back

#define pb pop_back


const int MAX_N = 500000; // maksymalna długość słowa wejściowego


string s; // słowo wejściowe

VI prefsuf; // wektor wszystkich prefiksosufiksów słowa "s"

int r, KMP[MAX_N+1], R = 0; // r - długość słowa "s", R - ilość wszystkich prefiksosufiksów słowa "s", KMP[i] - długość najdłuższego właściwego prefiksosufiksu słowa s[1..i]


void operacje_techniczne()
{
	cin >> s;
	
	r = s.size();
	
	s = '#' + s;	
}


void funkcja_prefiksowa()
{
	KMP[0] = -1;  KMP[1] = 0;
	
	int tmp;
	
	REP(i,2,r)
	{
		KMP[i] = 0;
		
		tmp = KMP[ i - 1 ];
		
		while( tmp >= 0 )
		{
			if( s[i] == s[ tmp + 1 ] )
			{
				KMP[i] = tmp + 1;
				
				break;
			}
			else
			{
				tmp = KMP[ tmp ];
			}
		}
	}
}


void znajdz_prefiksosufiksy()
{
	int tmp = r;
	
	while( tmp > 0 )
	{
		prefsuf.PB( tmp );
		
		++R;
		
		tmp = KMP[ tmp ];
	}
}


bool szablon(int dl) // sprawdzamy, czy prefiksosufiks słowa "s" o długości "dl" jest szablonem słowa "s"
{
	int last = dl;
	
	REP(i,dl+1,r) // musimy iść do końca słowa "s", bo gdyby nie (tzn. byśmy kończyli na pozycji "r-dl"), to mogłoby się okazać, że gdzieś przed tą pozycją (najwcześniej na pozycji "r-2*dl") jest koniec wystąpienia prefiksosufiksu długości "dl", a po niej kolejny koniec wystąpienia prefiksosufiksu długości "dl" dopiero na pozycji "r" (wtedy powinniśmy zrócić fałsz, a nie prawdę), oraz wiemy, że możemy zacząć od pozycji "dl+1", bo s[1..dl] to nasz sprawdzany prefiksosufiks; tak naprawdę musimy od niej zacząć, bo gdyby nie (tzn. gdybyśmy zaczynali od początku słowa "s", czyli od pozycji numer 1), to na pozycji "dl" byśmy nie wyłapali prefiksosufiksu o długości "dl", bo to nie jest najdłuższy właściwy prefiksosufiks słowa s[1..dl]
	{
		if( KMP[i] >= dl )
		{
			last = i;
		}
		else
		{
			if( last < i - dl + 1 )
			{
				return false;
			}
		}
	}
	
	return true;
}


int oblicz()
{
	int tmp, ind = R - 1;
	
	while( ind >= 0 )
	{
		tmp = prefsuf[ ind ];
		
		if( szablon( tmp ) )
		{
			return tmp;
		}
		else
		{
			while( prefsuf[ ind ] <= 2 * tmp )
			{
				prefsuf.pb();
				
				--ind;
			}
		}
	}	
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	operacje_techniczne();
	
	funkcja_prefiksowa();
	
	znajdz_prefiksosufiksy();
	
	cout << oblicz() << endl;
	
	return 0;
}
