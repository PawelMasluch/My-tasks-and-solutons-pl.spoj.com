#include<iostream> // 100 pkt
#include<string>
#include<algorithm>


using namespace std;


struct submit
{
	char zn;
	
	int a;
	
	string s;
};


#define REP(i,n) for(int i=0; i<n; ++i)


const int MAX_N = 100;


submit t[MAX_N];

bool czy[26];

int ile[26], wyn = 0, n, zrobione = 0;


bool f(const submit &A, const submit &B)
{
	return ( A.a < B.a );
}


int main()
{
	cin >> n;
	
	REP(i,n)
	{
		cin >> t[i].zn >> t[i].a >> t[i].s;
	}
	
	sort( t, t + n, f );
	
	REP(i,n)
	{
		if( !czy[ t[i].zn - 'A' ] )
		{
			if( t[i].s == "AC" )
			{
				wyn += t[i].a + 20 * ile[ t[i].zn - 'A' ];
				
				czy[ t[i].zn - 'A' ] = true;
				
				++zrobione;
			}
			else
			{
				if( t[i].s != "CE" )
				{
					++ile[ t[i].zn - 'A' ];
				}
			}
		}
	}
	
	cout << zrobione << " " << wyn << endl;
	
	return 0;
}
