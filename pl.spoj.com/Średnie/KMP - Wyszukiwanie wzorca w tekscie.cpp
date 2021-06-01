#include<iostream> // AC
#include<new>
#include<string>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define D delete


int * funkcja_prefiksowa(string &s)
{
	int n = s.size(), *KMP = new int [n+1], temp; // n >= 1
	
	KMP[0] = -1;  KMP[1] = 0;
		
	REP(i,2,n) // dla 2 <= i <= n wyznaczam KMP[i]
	{
		temp = KMP[ i - 1 ];
		
		while( temp >= 0 )
		{
			if( s[ ( i ) - 1 ] != s[ ( temp + 1 ) - 1 ] ) // s[0..n-1]
			{
				temp = KMP[ temp ];
			}
			else
			{
				KMP[i] = temp + 1;
				
				break;
			}
		}
		
		if( temp == -1 )
		{
			KMP[i] = 0;
		}
	}
	
	return KMP;
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	string W, S, slowo;
	
	int q, n, rS, *KMP;
	
	cin >> q;
	
	REP(i,1,q)
	{
		cin >> n >> W >> S; // n = |W|
		
		rS = S.size(); // rS = |S|
		
		slowo = W + '#' + S; // n + rS + 1 = |slowo|
		
		KMP = funkcja_prefiksowa( slowo );
		
		REP(j,n+2,n+rS+1)
		{
			if( KMP[j] == n )
			{
				cout << ( j - ( 2 * n ) ) - 1 << endl;
			}
		}
		
		D [] KMP;
	}
	
	return 0;
}
