#include<iostream> // 100 pkt
#include<string>


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


const LL A = 26, MAX_N = 1000000, p = 1000000007;


LL ile[A], silnia[MAX_N+1], n, wyn = 1;


string s;


LL fpm(LL a, LL b)
{
	LL wyn = 1;
	
	while( b > 0 )
	{
		if( b % 2 == 1 )
		{
			wyn = ( wyn * a ) % p;
		}
		
		a = ( a * a ) % p;
		
		b /= 2;
	}
	
	return wyn;
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	silnia[0] = 1;
	
	REP(i,1,MAX_N)
	{
		silnia[i] = ( silnia[ i - 1 ] * i ) % p;
	}
	
	cin >> s;
	
	n = s.size();
	
	REP(i,0,n-1)
	{
		++ile[ s[i] - 'a' ];
	}
	
	wyn = silnia[n];
	
	REP(i,0,A-1)
	{
		if( ile[i] > 0 )
		{
			wyn = ( wyn * fpm( silnia[ ile[i] ], p - 2 ) ) % p;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
