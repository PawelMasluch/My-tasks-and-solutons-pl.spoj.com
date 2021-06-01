#include<cstdio> /* 100 pkt ; po sprawdzeniu okazalo sie, ze tak naprawde 10^5 >= n >= 2 */


using namespace std;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)


const int MAX = 1000000;


int n, ile[MAX+1], a, wyn, tmp = 0;


int main()
{
    scanf( "%d", &n );

    REP(i,1,n,1)
    {
        scanf( "%d", &a );

        ++ile[a];
    }

    REP(i,1,MAX,1)
    {
        REP(j,i,MAX,i)
        {
            tmp += ile[j];
        }

        if( tmp >= 2 )
        {
            wyn = i;
        }

        tmp = 0;
    }

    printf( "%d\n", wyn );

    return 0;
}
