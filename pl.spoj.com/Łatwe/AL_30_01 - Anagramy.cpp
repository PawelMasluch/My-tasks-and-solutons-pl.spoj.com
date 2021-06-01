#include<string> // AC
#include<iostream>
#include<new>


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)


const int A = 26;


string baza, test;


int n, wyn = 0, *t1 = new int [A], *t2 = new int [A];


void zeruj(int *t)
{
    REP(i,A)
    {
        t[i] = 0;
    }
}


void oblicz(string &s, int *t)
{
    zeruj( t );

    int r = s.size();

    REP(i,r)
    {
        ++t[ s[i] - 'a' ];
    }
}


int f()
{
    oblicz( test, t2 );

    REP(i,A)
    {
        if( t1[i] != t2[i] )
        {
            return 0;
        }
    }

    return 1;
}


int main()
{
    ios_base::sync_with_stdio(0);

    cin >> baza >> n;

    oblicz( baza, t1 );

    REP(i,n)
    {
        cin >> test;

        wyn += f();
    }

    cout << wyn << endl;

    return 0;
}

