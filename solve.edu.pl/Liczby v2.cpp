#include<iostream> // 100 pkt
#include<map>
#include<string> // program dziala dla 0 <= N < 10^9


using namespace std;


typedef map < int, string > MIS;


#define ST first

#define ND second

#define UB upper_bound


MIS M;

int N;


void init()
{
	M[0] = "zero";    M[1] = "jeden";    M[2] = "dwa";
	
	M[3] = "trzy";    M[4] = "cztery";    M[5] = "piec";
	
	M[6] = "szesc";    M[7] = "siedem";    M[8] = "osiem";
	
	M[9] = "dziewiec";    M[10] = "dziesiec";    M[11] = "jedenascie";
	
	M[12] = "dwanascie";    M[13] = "trzynascie";    M[14] = "czternascie";
	
	M[15] = "pietnascie";    M[16] = "szesnascie";    M[17] = "siedemnascie";
	
	M[18] = "osiemnascie";    M[19] = "dziewietnascie";    M[20] = "dwadziescia";
	
	M[30] = "trzydziesci";    M[40] = "czterdziesci";    M[50] = "piecdziesiat";
	
	M[60] = "szescdziesiat";    M[70] = "siedemdziesiat";    M[80] = "osiemdziesiat";
	
	M[90] = "dziewiecdziesiat";    M[100] = "sto";    M[200] = "dwiescie";
	
	M[300] = "trzysta";    M[400] = "czterysta";    M[500] = "piecset";
	
	M[600] = "szescset";    M[700] = "siedemset";    M[800] = "osiemset";
	
	M[900] = "dziewiecset";
}


void wczytaj()
{
	cin >> N;
}


int rozbij(int x)
{
	MIS::iterator it;
	
	int last;
	
	while( x > 0 )
	{
		it = M.UB( x );    --it;
		
		cout << it -> ND << " ";
		
		x -= it -> ST;
		
		last = it -> ST;
	}
	
	return last;
}


void fun(int x, string s1, string s2, string s3)
{
	if( x > 0 ) // jesli x == 0, to nic nie wypisuje
	{
		if( x > 1 )
		{
			int last = rozbij( x ); // ostatnia liczba powstala z zachlannego rozbicia liczby 'x'
			
			if( x % 10 != 2  &&  x % 10 != 3  &&  x % 10 != 4 )
			{
				cout << s1 << " ";
			}
			else
			{
				if( last == 12  ||  last == 13  ||  last == 14 )
				{
					cout << s1 << " ";
				}
				else
				{
					cout << s2 << " ";
				}
			}
		}
		else // x == 1
		{
			cout << s3 << " ";
		}
	}
}


void oblicz()
{
	if( N == 0 ) // przypadek brzegowy
	{
		cout << M[0] << endl;
		
		return;
	}
	
	
	// teraz mozna powiedziec, ze N = A*1000000 + B*1000 + C
	
	int A = ( N / 1000000 ) % 1000, B = ( N / 1000 ) % 1000, C = ( N / 1 ) % 1000;
	
	
	// A
	
	fun( A, "milionow", "miliony", "milion" );
	
	
	// B
	
	fun( B, "tysiecy", "tysiace", "tysiac" );
	
	
	// C
	
	fun( C, "", "", "jeden" );
	
	/*if( C > 0 ) // jesli C == 0, to nic nie wypisuje
	{
		int last = rozbij( C ); // ostatnia liczba powstala z zachlannego rozbicia liczby 'C'
	}*/
	
	
	cout << endl;
}


void solve()
{
	init();
	
	wczytaj();
	
	oblicz();
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	solve();
	
	return 0;
}