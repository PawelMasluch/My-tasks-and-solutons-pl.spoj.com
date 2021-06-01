#include<iostream> // 100 pkt
#include<string>
#include<algorithm>


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)


const int MAX_N = 1000;


string s;

int n, t[MAX_N];


int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n;

    REP(i,n)
    {
        cin >> s;

        t[i] = s.size();
    }

    sort( t, t + n );

    REP(i,n)
    {
        REP(j,t[i])
        {
            cout << "O";
        }

        cout << endl;
    }

    return 0;
}
