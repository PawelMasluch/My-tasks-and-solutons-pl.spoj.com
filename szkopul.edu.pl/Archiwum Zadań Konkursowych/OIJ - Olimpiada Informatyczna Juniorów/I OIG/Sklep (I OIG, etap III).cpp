#include<iostream> // 100 pkt
#include<vector>
#include<unordered_map>



using namespace std;


typedef vector <int> VI;
typedef unordered_map <int, int> UMII;


#define PB push_back


int main(){
	
	ios_base::sync_with_stdio(0);
	
	/* 
		Kolejnosc produktow zgodna 
		z kolejnoscia pojawiania sie 
		na wejsciu. 
	*/
	VI products_order;
	
	/*
		Ilosci poszczegolnych produktow.
		Klucz - numer produktu.
		Wartosc - ilosc produktu.
	*/
	UMII products_amounts;
	
	int N;
	cin >> N;
	
	int A, K;
	while( N-- ){
		cin >> A >> K;
		
		/* 
			Jesli produkt o numerze A 
			nie pojawil sie wczesniej.
		*/
		if( products_amounts.count(A) == 0 ){
			products_order.PB(A);
		}
		
		products_amounts[A] += K;
	}
	
	// Ilosc roznych rodzajow produktow.
	cout << products_order.size() << endl;
	
	// Wypisanie rodzajow produktow 
	// (zgodnie z kolejnoscia pojawiania sie na wejsciu) 
	// i ich ilosci.
	for(auto it: products_order){
		cout << it << " " << products_amounts[it] << endl;
	}
	
	return 0;
}
