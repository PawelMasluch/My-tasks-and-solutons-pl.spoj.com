#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
 
LL min(LL a, LL b)
{
	return (a<b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n, *zlicz = new LL [100001], *ile = new LL [100001], a, temp1, temp2, pom1 = 0, pom2 = 0, *last = new LL [100001], wyn = 1090007009;
	
	REP(i,0,100000)
	{
		zlicz[i] = ile[i] = last[i] = 0; // zlicz[i] - dla ilu wyraz?w ci?gu osi?gni?to obj?to?? "i", ile[i] - liczba wymaganych operacji do wyr?wnania do obj?to?ci "i"
	}
	
	cin >> n;
	
	REP(i,1,n)
	{
		cin >> a;
		
		temp1 = a;
		
		while( temp1 > 0 )
		{
			temp2 = temp1;
			
			while( temp2 <= 100000 )
			{
				if( last[ temp2 ] != i )
				{
					last[ temp2 ] = i;
					
					++zlicz[ temp2 ];
					
					ile[ temp2 ] += pom1 + pom2;
				}
				
				temp2 *= 2;
				
				++pom2;
			}
			
			temp1 /= 2;
			
			++pom1;
			
			pom2 = 0;
		}
		
		pom1 = pom2 = 0;
	}
	
	REP(i,0,100000)
	{
		if( zlicz[i] == n )
		{
			wyn = min( wyn, ile[i] );
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
