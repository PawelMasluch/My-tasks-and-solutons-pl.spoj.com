#include<iostream> // 100 pkt
#include<string>


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


const LL MAX_N = 1000000;


string s;

LL n, R[2][MAX_N+1];


void Manacher_Algorithm()
{
	n = s.size();
	
	s = '#' + s + '$';
	
	LL j, tmp, k;
	
	REP(i,0,1)
	{
		tmp = 0;
		
		j = 1;
		
		while( j <= n )
		{
			while( s[ j - tmp - 1 ] == s[ j + tmp + i ] )
			{
				++tmp;
			}
			
			R[i][j] = tmp;
			
			k = 1;
			
			while( k <= R[i][j]  &&  R[i][ j - k ] != R[i][j] - k )
			{
				R[i][ j + k ] = min( R[i][ j - k ], R[i][j] - k );
				
				++k;
			}
			
			j += k;
			
			tmp = max( tmp - k, (LL)0 );
		}
	}
}


LL oblicz_wynik()
{
	LL wyn = 0;
	
	REP(i,0,1)
	{
		REP(j,1,n)
		{
			wyn += R[i][j];
		}
	}
	
	wyn += n;
	
	return wyn;
}


int main()
{
	cin >> s;
	
	Manacher_Algorithm();
	
	cout << oblicz_wynik() << endl;
	
	return 0;
}
