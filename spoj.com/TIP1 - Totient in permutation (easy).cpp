#include<cstdio> // AC
 
 
using namespace std;
 
 
const int best[44] = { 21, 63, 291, 2817, 2991, 4435, 20617, 45421, 69271, 75841, 162619, 176569, 284029, 400399, 474883, 732031, 778669, 783169, 1014109, 1288663, 1504051, 1514419, 1924891, 1956103, 2006737, 2044501, 2094901, 2239261, 2710627, 2868469, 3582907, 3689251, 4198273, 4696009, 5050429, 5380657, 5886817, 6018163, 6636841, 7026037, 7357291, 7507321, 8316907, 8319823 };
 
 
int q, n, ind;
 
 
int bin()
{
	int pocz = 0, kon = 43, wyn = -1, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) >> 1;
		
		if( best[ sr ] <= n - 1 )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}
 
 
int main()
{
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d", &n );
		
		ind = bin();
		
		if( ind == -1 )
		{
			printf( "No solution.\n" );
		}
		else
		{
			printf( "%d\n", best[ ind ] );
		}
		
		--q;
	}
	
	return 0;
} 
