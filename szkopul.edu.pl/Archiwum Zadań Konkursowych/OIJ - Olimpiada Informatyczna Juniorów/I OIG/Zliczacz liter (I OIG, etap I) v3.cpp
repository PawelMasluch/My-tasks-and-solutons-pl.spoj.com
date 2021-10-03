// Rozwiazanie z uzyciem tablic

#include<iostream> // 100 pkt
#include<string>


using namespace std;


typedef string STR;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int ALPHABET_SIZE = 26;


// Klucz: litera (mala badz duza)
// Wartosc: liczba wystapien litery 
//          we wszystkich wierszach tekstu 
int lowercase_letters_histogram[ALPHABET_SIZE]; // poczatkowo same zera
int uppercase_letters_histogram[ALPHABET_SIZE]; // poczatkowo same zera


int main(){
	
	ios_base::sync_with_stdio(0);
	
	int N; // liczba wierszy tekstu do analizy
	cin >> N;
	
	STR s; // wiersz tekstu do analizy
	int K; // liczba znakow wiersza tekstu do analizy
	
	while( N-- >= 0 ){ // dla kazdego wiersza tekstu
		getline(cin, s); // wczytanie wiersza tekstu
		
		K = s.size(); // liczba znakow wiersza tekstu do analizy
		
		REP(i,0,K-1){ // dla kazdgo znaku wiersza tekstu
			if( 'a' <= s[i]  &&  s[i] <= 'z' ){ // mala litera
				++lowercase_letters_histogram[ s[i] - 'a' ];
			}
			else{
				if( 'A' <= s[i]  &&  s[i] <= 'Z' ){ // duza litera
					++uppercase_letters_histogram[ s[i] - 'A' ];
				}
			}
		}
	}
	
	
	
	// Wypisanie histogramu wystapien malych liter 
	// (w kolejnosci alfabetycznej) 
	// we wszystkich wierszach tekstu 
	REP(c,'a','z'){
		if( lowercase_letters_histogram[ c - 'a' ] > 0 ){
			cout << (char) c << " " << lowercase_letters_histogram[ c - 'a' ] << endl;
		}
	}
	
	// Wypisanie histogramu wystapien duzych liter 
	// (w kolejnosci alfabetycznej)
	// we wszystkich wierszach tekstu 
	REP(c,'A','Z'){
		if( uppercase_letters_histogram[ c - 'A' ] > 0 ){
			cout << (char) c << " " << uppercase_letters_histogram[ c - 'A' ] << endl;
		}
	}
	
	return 0;
}
