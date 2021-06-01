#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


int pocz[27] = { 4, 8, 24, 90, 114, 524, 888, 1130, 1328, 9552, 15684, 19610, 31398, 155922, 360654, 370262, 492114, 1349534, 1357202, 2010734, 4652354, 17051708, 20831324, 47326694, 122164748, 189695660, 191912784 }, kon[27] = { 4, 10, 28, 96, 126, 540, 906, 1150, 1360, 9586, 15726, 19660, 31468, 156006, 360748, 370372, 492226, 1349650, 1357332, 2010880, 4652506, 17051886, 20831532, 47326912, 122164968, 189695892, 191913030 };


int f(int x) // obliczam indeks przedzia?u, w kt?rym jest 'x' 
{
	REP(i,0,26)
	{
		if( pocz[i] <= x  &&  x <= kon[i] )
		{
			return i;
		}
	}
	
	return -1;
}


int g(int x) // obliczam najwi?kszy indeks przedzia?u o ko?cu mniejszym ni? 'x'
{
	int wyn = -1;
	
	REP(i,0,26)
	{
		if( x > kon[i] )
		{
			wyn = i;
		}
	}
	
	return wyn;
}


int main()
{
	int n, ktory, najblizszy;
	
	scanf( "%d", &n );
	
	ktory = f( n );
	
	if( ktory != -1 )
	{
		if(     ktory == 0    ||    n - pocz[ ktory ] + 1  >  kon[ ktory - 1 ] - pocz[ ktory - 1 ] + 1     )
		{
			printf( "%d %d\n", pocz[ ktory ], n );
		}
		else
		{
			printf( "%d %d\n", pocz[ ktory - 1 ], kon[ ktory - 1 ] );
		}
	}
	else
	{
		najblizszy = g( n );
		
		printf( "%d %d\n", pocz[ najblizszy ], kon[ najblizszy ] );
	}
	
	return 0;
}
