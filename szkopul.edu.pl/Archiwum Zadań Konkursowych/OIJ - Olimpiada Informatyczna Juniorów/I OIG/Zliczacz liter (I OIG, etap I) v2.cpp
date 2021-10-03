// Rozwiazanie z uzyciem mapy

#include<iostream> // 100 pkt
#include<string>
#include<map>


using namespace std;


typedef map <char, int> MCI;
typedef string STR;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


int main(){
	
	ios_base::sync_with_stdio(0);
	
	// Klucz: litera (mala badz duza)
	// Wartosc: liczba wystapien litery 
	//          we wszystkich wierszach tekstu  
	MCI lowercase_letters_histogram;
	MCI uppercase_letters_histogram;
	
	int N; // liczba wierszy tekstu do analizy
	cin >> N;
	
	STR s; // wiersz tekstu do analizy
	int K; // liczba znakow wiersza tekstu do analizy
	
	while( N-- >= 0 ){ // dla kazdego wiersza tekstu
		getline(cin, s); // wczytanie wiersza tekstu
		
		K = s.size(); // liczba znakow wiersza tekstu do analizy
		
		REP(i,0,K-1){ // dla kazdgo znaku wiersza tekstu
			if( 'a' <= s[i]  &&  s[i] <= 'z' ){ // mala litera
				++lowercase_letters_histogram[ s[i] ];
			}
			else{
				if( 'A' <= s[i]  &&  s[i] <= 'Z' ){ // duza litera
					++uppercase_letters_histogram[ s[i] ];
				}
			}
		}
	}
	
	
	
	// Wypisanie histogramu wystapien malych liter 
	// (w kolejnosci alfabetycznej) we wszystkich 
	// wierszach tekstu 
	for(auto it: lowercase_letters_histogram){
		cout << it.first << " " << it.second << endl;
	}
	
	
	// Wypisanie histogramu wystapien duzych liter 
	// (w kolejnosci alfabetycznej) we wszystkich 
	// wierszach tekstu 
	for(auto it: uppercase_letters_histogram){
		cout << it.first << " " << it.second << endl;
	}
	
	return 0;
}
