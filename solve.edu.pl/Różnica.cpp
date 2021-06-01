#include<iostream> // 100 pkt
#include<new>
#include<string>
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back


int min(int a, int b)
{
	return (a<b) ? a : b ;
}


int max(int a, int b)
{
	return (a>b) ? a : b ;
}


void inicjuj(int *t, int n, int val)
{
	REP(i,0,n-1)
	{
		t[i] = val;
	}
}


void wypelnij(string &s, VI *pom, int *r_pom)
{
	int r_s = s.size(), ind;
	
	inicjuj( r_pom, 26, 0 );
	
	REP(i,0,r_s-1)
	{
		ind = (int)( s[i] ) - 97;
		
		pom[ ind ].PB(i);
		
		++r_pom[ ind ];
	}
}


int f(VI *pom, int *r_pom, int max_ind, int min_ind)
{
	int i = 0, j = 0, suma = 0, suma_pop = 0, wyn = 0, mini = 10090009;
	
	while( i <= r_pom[ max_ind ] - 1  &&  j <= r_pom[ min_ind ] - 1 )
	{
		if( pom[ max_ind ][i] > pom[ min_ind ][j] ) // -1
		{
			--suma;
			
			mini = min( mini, suma_pop );
			
			suma_pop = suma;
			
			++j;
		}
		else // 1
		{
			++suma;
			
			++i;
		}
		
		wyn = max( wyn, suma - mini );
	}
	
	while( i <= r_pom[ max_ind ] - 1 )
	{
		++suma;
		
		wyn = max( wyn, suma - mini );
		
		++i;
	}
	
	while( j <= r_pom[ min_ind ] - 1 )
	{
		--suma;
			
		mini = min( mini, suma_pop );
		
		suma_pop = suma;
		
		wyn = max( wyn, suma - mini );
		
		++j;
	}
	
	return wyn;
}


int oblicz(string &s)
{
	VI *pom = new VI [26];
	
	int *r_pom = new int [26], temp, wyn = 0;
	
	wypelnij( s, pom, r_pom );
	
	REP(i,0,25)
	{
		REP(j,0,i-1)
		{
			temp = f( pom, r_pom, i, j );
			
			wyn = max( wyn, temp );
		}
		
		REP(j,i+1,25)
		{
			temp = f( pom, r_pom, i, j );
			
			wyn = max( wyn, temp );
		}
	}
	
	return wyn;
}


int main()
{
	string s;
	
	cin >> s;
	
	cout << oblicz( s ) << endl;
	
	return 0;
}
