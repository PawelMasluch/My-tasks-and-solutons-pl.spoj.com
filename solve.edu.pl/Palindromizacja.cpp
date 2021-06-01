#include<iostream> // 100 pkt
#include<string>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 1e6;


string s;

char zn;

int n, KMP[2*MAX_N+2], dl, tmp;


void funkcja_prefiksowa()
{
	KMP[0] = -1;  KMP[1] = 0;
	
	REP(i,2,2*n+1)
	{
		tmp = KMP[ i - 1 ];
		
		while( tmp >= 0 )
		{
			if( s[ i - 1 ] == s[ tmp ] )
			{
				KMP[i] = tmp + 1;
				
				break;
			}
			else
			{
				tmp = KMP[ tmp ];	
			}
		}
		
		KMP[i] = tmp + 1;
	}
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void znajdz()
{
	dl = KMP[ 2 * n + 1 ];	
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> s;
	
	n = s.size();
	
	
	// konstruuję słowo "s#"
	
	s += '#';
	
	
	
	// konstruuję słowo "s#s"
	
	REP(i,0,n-1)
	{
		s += s[i];
	}
	
	
	// konstruuję słowo "(s^R)#s"
	
	REP(i,0,(n/2)-1)
	{
		zn = s[i];
		
		s[i] = s[ n - 1 - i ];
		
		s[ n - 1 - i ] = zn;
	}
	
	funkcja_prefiksowa();
	
	znajdz();
	
	cout << n - dl << endl;
	
	return 0;
}
