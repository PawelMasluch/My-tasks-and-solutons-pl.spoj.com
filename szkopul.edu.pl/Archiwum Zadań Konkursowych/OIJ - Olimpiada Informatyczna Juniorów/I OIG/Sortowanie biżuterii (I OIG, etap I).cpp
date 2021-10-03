#include<iostream> // 100 pkt
#include<string>
#include<algorithm>


using namespace std;


typedef string STR;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


// Funkcja porownujaca lancuchy tekstowe 
// zlozone z malych liter alfabetu angielskiego 
// (na potrzeby sortowania w funkcji main).
bool comparator(STR s1, STR s2){
	
	if( s1.size() == s2.size() ){
		return s1 < s2;
	}
	
	return s1.size() < s2.size();
}


int main(){
	
	ios_base::sync_with_stdio(0);
	
	// Liczba lancuchow znakow 
	// zlozonych z malych liter 
	// alfabetu angielskiego.
	int N;
	cin >> N;
	
	STR s[N];
	
	REP(i,0,N-1){
		cin >> s[i];	
	}
	
	sort( s, s + N, comparator );
	
	REP(i,0,N-1){
		cout << s[i] << endl;	
	}
	
	return 0;
}
