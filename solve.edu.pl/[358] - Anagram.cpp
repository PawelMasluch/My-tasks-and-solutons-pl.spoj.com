#include<iostream> // 100 pkt
#include<string>


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)

#define S size


const int A = 26;


string w, s;

int q, t_w[A], t_s[A];


void obsluz(string &slowo, int *t)
{
	REP(i,A)
	{
		t[i] = 0;
	}

	int n = slowo.S();

	REP(i,n)
	{
		++t[ slowo[i] - 'a' ];
	}
}


void obliczenia_wstepne()
{
	cin >> w;

	obsluz( w, t_w );
}


bool anagram(int *w, int *s)
{
	REP(i,A)
	{
		if( w[i] != s[i] )
		{
			return false;
		}
	}

	return true;
}


void query()
{
    cin >> s;

	obsluz( s, t_s );

	if( anagram( t_w, t_s ) )
	{
		cout << s << endl;
	}
}


void zapytania()
{
	cin >> q;

	while( q )
	{
		query();

		--q;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);

	obliczenia_wstepne();

	zapytania();

	return 0;
}
