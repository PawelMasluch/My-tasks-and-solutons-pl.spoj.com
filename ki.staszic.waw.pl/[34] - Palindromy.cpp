#include<iostream> // 100 pkt
#include<string>


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 500000;


string s;

LL wyn = 0;

int n, R[2][MAX_N+1];


void wczytaj()
{
	cin >> s;
	
	n = s.size();	
}


void oblicz() // algorytm Manachera
{
	s = '#' + s + '$';
	
	int j, tmp, k;
	
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
			
			wyn += R[i][j] + i;
			
			k = 1;
			
			while( k <= R[i][j]  &&  R[i][ j - k ] != R[i][j] - k )
			{
				R[i][ j + k ] = min( R[i][ j - k ], R[i][j] - k );
				
				wyn += R[i][ j + k ] + i;
				
				++k;
			}
			
			j += k;
			
			tmp = max( tmp - k, 0 );
		}
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
