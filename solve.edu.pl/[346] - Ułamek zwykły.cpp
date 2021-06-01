#include<cstdio> // 100 pkt


using namespace std;


int NWD(int a, int b)
{
    int tmp;

    while( b )
    {
        tmp = a % b;

        a = b;

        b = tmp;
    }

    return a;
}


void skroc(int &a, int &b)
{
    int pom = NWD( a, b );

    a /= pom;

    b /= pom;
}


int main()
{
    int A, B, C, D, E, F, ACE, BDF;

    scanf( "%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F );

    ACE = A * C * E;

    BDF = B * D * F;

    skroc( ACE, BDF );

    printf( "%d/%d\n", ACE, BDF );

    return 0;
}
