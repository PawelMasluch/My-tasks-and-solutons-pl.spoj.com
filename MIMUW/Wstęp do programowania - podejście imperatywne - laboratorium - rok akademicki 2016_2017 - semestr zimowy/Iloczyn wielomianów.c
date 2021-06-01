/* Pawel Masluch, nr albumu 385865 */

#include<stdio.h> // 10/10 pkt


#define MAX_LICZBA_WSPOLCZYNNIKOW 11


void zeruj(int wielomian[]) /*zerowanie wspolczynnikow wielomianu*/
{
      int i;

      for(i=0; i<MAX_LICZBA_WSPOLCZYNNIKOW; ++i)
      {
            wielomian[i] = 0;
      }
}


int min(int a, int b) /* obliczamy mniejsza z 2 liczb */
{
    int wynik;

    if( a < b )
    {
        wynik = a;
    }
    else
    {
        wynik = b;
    }

    return wynik;
}


void wczytaj(int *liczba_wspolczynnikow, int wielomian[]) /* wczytywanie wielomianu */
{
      int i, ile_wczytac, wspolczynnik;

      zeruj( wielomian );

      scanf( "%d", liczba_wspolczynnikow );

      ile_wczytac = min( MAX_LICZBA_WSPOLCZYNNIKOW, (*liczba_wspolczynnikow) ); /* okreslamy, ile wspolczynnikow wielomianu wczytac do tablicy */

      for(i=0; i<ile_wczytac; ++i)
      {
            scanf( "%d", &wielomian[i] );
      }


      /* jesli mamy za duzo wspolczynnikow, to reszte stanowia zera, ktore i tak wypada wczytac */

      if( (*liczba_wspolczynnikow) > MAX_LICZBA_WSPOLCZYNNIKOW )
      {
          for(i=MAX_LICZBA_WSPOLCZYNNIKOW; i<(*liczba_wspolczynnikow); ++i)
          {
              scanf( "%d", &wspolczynnik );
          }
      }
}


void oblicz(int wielomian1[], int wielomian2[], int wynik[]) /* mnozenie wielomianow 'wielomian1' i 'wielomian2', wynik mnozenia zapisany w tablicy 'wynik' */
{
      int i, j;

      zeruj( wynik );

      for(i=0; i<MAX_LICZBA_WSPOLCZYNNIKOW; ++i)
      {
            for(j=0; i+j<MAX_LICZBA_WSPOLCZYNNIKOW; ++j)
            {
                wynik[ i + j ] += wielomian1[i] * wielomian2[j];
            }
      }
}


int sgn(int x) /* zwracamy znak liczby */
{
    int wynik;

    if( x > 0 )
    {
        wynik = 1;
    }
    else
    {
        if( x < 0 )
        {
            wynik = -1;
        }
        else
        {
            wynik = 0;
        }
    }

    return wynik;
}


int modul(int x) /*zwracamy wartosc bezwzgledna liczby */
{
    int wynik;

    if( x >= 0 )
    {
        wynik = x;
    }
    else
    {
        wynik = -x;
    }

    return wynik;
}


void wypisz_pierwszy_skladnik(int potega, int wspolczynnik) /* procedura pomocnicza do wypisywania wielomianu */
{
    int znak = sgn( wspolczynnik );

    if( wspolczynnik != 0 )
    {
        if( wspolczynnik < 0 )
        {
            printf( "-" );
        }

        if( modul( wspolczynnik ) != 1 )
        {
            switch( potega )
            {
                case 0:
                    printf( "%d", znak * wspolczynnik );
                    break;

                case 1:
                    printf( "%dx", znak * wspolczynnik );
                    break;

                default:
                    printf( "%dx^%d", znak * wspolczynnik, potega );
                    break;
            }
        }
        else
        {
            switch( potega )
            {
                case 0:
                    printf( "%d", znak * wspolczynnik );
                    break;

                case 1:
                    printf( "x" );
                    break;

                default:
                    printf( "x^%d", potega );
                    break;
            }
        }
    }
    else
    {
        printf( "0" ); /* jesli mamy zerowy wspolczynnik, to tak naprawde mamy zerowy wielomian */
    }
}


void wypisz_aktualny_skladnik(int potega, int wspolczynnik) /* procedura pomocnicza do wypisywania wielomianu */
{
    int znak = sgn( wspolczynnik );

    if( wspolczynnik != 0 )
    {
        switch( znak )
        {
            case 1:
                printf( "+" );
                break;

            case -1:
                printf( "-" );
                break;
        }

        if( modul( wspolczynnik ) != 1 )
        {
            switch( potega )
            {
                case 0:
                    printf( "%d", znak * wspolczynnik );
                    break;

                case 1:
                    printf( "%dx", znak * wspolczynnik );
                    break;

                default:
                    printf( "%dx^%d", znak * wspolczynnik, potega );
                    break;
            }
        }
        else
        {
            switch( potega )
            {
                case 0:
                    printf( "%d", znak * wspolczynnik );
                    break;

                case 1:
                    printf( "x" );
                    break;

                default:
                    printf( "x^%d", potega );
                    break;
            }
        }
    }
}


void wypisz_wielomian(int wielomian[])
{
      int ind = MAX_LICZBA_WSPOLCZYNNIKOW - 1, i;

      while( wielomian[ ind ] == 0  &&  ind > 0 )
      {
        --ind;
      }

      wypisz_pierwszy_skladnik( ind, wielomian[ ind ] );

      for(i=ind-1; i>=0; --i)
      {
          wypisz_aktualny_skladnik( i, wielomian[i] );
      }
}


void wypisz_wielomian_w_nawiasach(int wielomian[])
{
      printf( "(" );

      wypisz_wielomian( wielomian );

      printf( ")" );
}


void wypisz(int wielomian1[], int wielomian2[], int wynik[]) /* wypisujemy cale wyjscie */
{
      wypisz_wielomian_w_nawiasach( wielomian1 );

      wypisz_wielomian_w_nawiasach( wielomian2 );

      printf( "=" );

      wypisz_wielomian( wynik );

      printf( "\n" );
}


int main(void)
{
      int m, wielomian1[MAX_LICZBA_WSPOLCZYNNIKOW]; /* pierwszy wielomian */

      int n, wielomian2[MAX_LICZBA_WSPOLCZYNNIKOW]; /* drugi wielomian */

      int wynik[MAX_LICZBA_WSPOLCZYNNIKOW]; /* wynik mnozenia wielomianow wejsciowych */

      wczytaj( &m, wielomian1 );

      wczytaj( &n, wielomian2 );

      oblicz( wielomian1, wielomian2, wynik );

      wypisz( wielomian1, wielomian2, wynik );

      return 0;
}
