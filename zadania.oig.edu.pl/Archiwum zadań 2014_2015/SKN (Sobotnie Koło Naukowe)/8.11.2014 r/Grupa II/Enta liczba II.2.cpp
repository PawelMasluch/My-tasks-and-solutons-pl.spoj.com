#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


int main()
{
    /* Idea rozwiazania:
    - wypisuje kolejne liczby naturalne (bez zera) w wierszach, w kazdym wierszu po 6 liczb
    - w kazdym wierszu rozwazamy tylko liczby, ktore przy dzieleniu przez 6 daja reszte 2, 3 lub 4
    - obliczam, ktora liczbe z pewnego (nie obchodzi nas, z ktorego) wiersza mamy wypisac (w kodzie to zmienna r)
    - mozemy zauwazyc, ze gdy r=0, to robiac przypisanie r=3, mamy, ze nasz wynik to 2 * n - r + 1 */

    LL n;

    scanf( "%lld", &n );

    LL r = n % 3;

    if( r == 0 )
    {
        r = 3;
    }

    printf( "%lld\n", 2 * n - r + 1 );

    return 0;
}
