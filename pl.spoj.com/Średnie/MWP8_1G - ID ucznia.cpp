#include<string> // AC
#include<iostream>
#include<new>


using namespace std;


typedef long long LL;


#define REP(i,n) for(LL i=0; i<n; ++i)

#define FORD(i,n) for(LL i=n-1; i>=0; --i)


const LL A = 26;


string s1, s2;

LL q;


LL ID(string &s, LL &r)
{
    LL wyn = 0, tmp = 1;

    FORD(i,r)
    {
        wyn += ( s[i] - 'a' ) * tmp;

        tmp *= A;
    }

    return wyn;
}


void odwroc(string &s, LL &r)
{
    char tmp;

    REP(i,(r >> 1))
    {
        tmp = s[i];

        s[i] = s[ r - 1 - i ];

        s[ r - 1 - i ] = tmp;
    }
}


string slowo(LL &identyfikator, LL &r)
{
    string wyn = "";

    char znak;

    REP(i,r)
    {
        znak = (char)( 97 + ( identyfikator % A ) );

        wyn = wyn + znak;

        identyfikator /= A;
    }

    odwroc( wyn, r );

    return wyn;
}


void f()
{
    LL r = s1.size(), ID1 = ID( s1, r ), ID2 = ID( s2, r );

    if( ( ID1 & 1 ) != ( ID2 & 1 ) )
    {
        cout << "BRAK\n";

        return ;
    }

    LL ID3 = ( ID1 + ID2 ) >> 1;

    cout << slowo( ID3 , r ) << endl;
}


void zapytania()
{
    cin >> q;

    while( q )
    {
        cin >> s1 >> s2;

        f();

        --q;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);

    zapytania();

    return 0;
}

