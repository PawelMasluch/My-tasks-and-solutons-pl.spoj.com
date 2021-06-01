#include<stack> // 100 pkt
#include<iostream>
#include<vector>
#include<cstdio>


using namespace std;


typedef pair < int, int > PII;

typedef vector < PII > VPII;

typedef stack < int > SI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define MP make_pair

#define ST first

#define ND second

#define E empty


const int MAX_N = 1000000;


VPII v; // wynikowe pary sparowanych nawias?w

SI S; // pozycje niewykorzystanych jeszcze nawias?w otwieraj?cych

int n;


int main()
{
	char zn;
    
    scanf( "%d", &n );
    
    REP(i,1,2*n)
    {
         cin >> zn;
         
         if( zn == '(' )
         {
               S.push( i );
         }
         else // zn == ')'
         {
             if( S.E() )
             {
					printf( "NIE\n" );
					
					return 0;
             }
             else
             {
                 v.PB( MP( S.top(), i ) );
                 
                 S.pop();
             }
         }
    }
    
    if( !S.E() )
    {
		printf( "NIE\n" );
    }
    else
    {
        printf( "TAK\n" );
        
        REP(i,0,n-1)
        {
        	printf( "%d %d\n", v[i].ST, v[i].ND );
        }
    }
    
    return 0;
}
