#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


int main()
{
    /* Idea rozwiazania:
    - wypisuje kolejne liczby naturalne (bez zera) w wierszach, w kazdym wierszu po 6 liczb
    - wiersze numeruje kolejnymi liczbami naturalnymi, poczawszy od zera
    - w kazdym wierszu rozwazamy tylko liczby, ktore przy dzieleniu przez 6 daja reszte 2, 3 lub 4
    - obliczam numer wiersza, w ktorym jest wynik (w kodzie to zmienna k)
    - obliczam, ktora liczbe z wiersza nr k mamy wypisac (w kodzie to zmienna r)
    - wyliczam reszte z dzielenia przez 6 wyniku (w kodzie to zmienna reszta)
    - wypisuje wynik*/

    LL n;

    scanf( "%lld", &n );

    LL k = ( n - 1 ) / 3; // ew. LL k = ( ( n + 2 ) / 3 ) - 1;

    LL r = n % 3;

    LL reszta;

    switch( r )
    {
        case 1:
            reszta = 2;
            break;

        case 2:
            reszta = 3;
            break;

        case 0:
            reszta = 4;
            break;
    }

    printf( "%lld\n", 6 * k + reszta );

    return 0;
}
