#include<iostream> // 100 pkt
#include<vector>
#include<unordered_map>
#include<algorithm>



using namespace std;


typedef vector <char> VC;
typedef unordered_map <char, int> UMCI;


#define PB push_back


int main(){
	
	ios_base::sync_with_stdio(0);
	
	/* 
		Kolejnosc produktow zgodna 
		z kolejnoscia pojawiania sie 
		na wejsciu. 
	*/
	VC products_order;
	
	/*
		Ilosci poszczegolnych produktow.
		Klucz - kod produktu.
		Wartosc - ilosc produktu.
	*/
	UMCI products_amounts;
	
	int n;
	cin >> n;
	
	char product_code;
	char product_amount_change_code;
	int product_amount;
	while( n-- ){
		
		cin >> product_code >> 
			   product_amount_change_code >> 
			   product_amount;
		
		/* 
			Jesli produkt danego typu 
			nie pojawil sie wczesniej.
		*/
		if( products_amounts.count(product_code) == 0 ){
			products_order.PB(product_code);
		}
		
		if( product_amount_change_code == '+' ){
			products_amounts[product_code] += product_amount;
		}
		else{ // product_amount_change_code == '-'
			products_amounts[product_code] -= product_amount;
		}
	}
	
	sort( products_order.begin(), products_order.end() );
	
	// Wypisanie rodzajow produktow 
	// (zgodnie z kolejnoscia alfabetyczna ich kodow) 
	// i ich ilosci.
	for(auto it: products_order){
		cout << it << " " << products_amounts[it] << endl;
	}
	
	return 0;
}
