#include<iostream> // 100 pkt
#include<vector>


using namespace std;


typedef vector <char> VC;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define PB push_back
#define C clear


const int INF = 1099;


int main(){

    int N; // 1 <= N <= 26 (26 -> rozmiar alfabetu angielskiego)
    cin >> N;

    // ----------------------

    VC res;
    int x, max_x = -INF;

    REP(i,0,N-1){
        
        cin >> x;

        if( x == max_x ){
            res.PB( 'A' + i );
        }
        else{
            
            if( x > max_x ){
                
                max_x = x;

                res.C();
                res.PB( 'A' + i );
            }
        }
    }

    REP(i,0,res.size()-1){
        cout << res[i];
    }
    cout << endl;

    return 0;
}
