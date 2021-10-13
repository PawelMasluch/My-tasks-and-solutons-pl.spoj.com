#include<iostream> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int LICZBA_SKRACALNYCH_LICZB_PIERWSZYCH = 83;


int skracalne_liczby_pierwsze[LICZBA_SKRACALNYCH_LICZB_PIERWSZYCH] = { 2, 3, 5, 7, 23, 29, 31, 37, 53, 59, 71, 73, 79, 233, 239, 293, 311, 313, 317, 373, 379, 593, 599, 719, 733, 739, 797, 2333, 2339, 2393, 2399, 2939, 3119, 3137, 3733, 3739, 3793, 3797, 5939, 7193, 7331, 7333, 7393, 23333, 23339, 23399, 23993, 29399, 31193, 31379, 37337, 37339, 37397, 59393, 59399, 71933, 73331, 73939, 233993, 239933, 293999, 373379, 373393, 593933, 593993, 719333, 739391, 739393, 739397, 739399, 2339933, 2399333, 2939999, 3733799, 5939333, 7393913, 7393931, 7393933, 23399339, 29399999, 37337999, 59393339, 73939133 };


int main(){
	
	LL A, B;
	cin >> A >> B;
	
	int wynik = 0;
	REP(i,0,LICZBA_SKRACALNYCH_LICZB_PIERWSZYCH-1){
		
		if( A <= skracalne_liczby_pierwsze[i]  &&  skracalne_liczby_pierwsze[i] <= B ){
			++wynik;
		}
	}
	
	cout << wynik << endl;
	
	return 0;
}
