#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


int main()
{
    /* Idea rozwiazania:
    - wypisuje kolejne liczby naturalne (bez zera) w wierszach, w kazdym wierszu po 6 liczb
    - w kazdym wierszu rozwazamy tylko liczby, ktore przy dzieleniu przez 6 daja reszte 2, 3 lub 4
    - obliczam, ktora liczbe z pewnego (nie obchodzi nas, z ktorego) wiersza mamy wypisac (w kodzie to zmienna r)
    - na koniec zauwazmy, ze w zaleznosci od r wypiszemy scisle okreslony wynik */

    LL n;

    scanf( "%lld", &n );

    LL r = n % 3;

    switch( r )
    {
        case 1:
            printf( "%lld\n", 2 * n );
            break;

        case 2:
            printf( "%lld\n", 2 * n - 1 );
            break;

        case 0:
            printf( "%lld\n", 2 * n - 2 );
            break;
    }

    return 0;
}
