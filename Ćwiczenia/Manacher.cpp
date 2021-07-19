#include <bits/stdc++.h>


typedef std::vector <int> VI;

typedef std::vector <VI> VVI;



#define REP(i,a,b) for(int i=a; i<=b; ++i)


// Manacher algorithm for searching radiuses of palindroms (odd and even) in a text.
// This function returns R - vector of two vectors:
//		- first vector (index 0) contains radiuses of even palindroms, 
//		- the second one (index 1) - radiuses of odd palindroms.

// s - string to be analyzed

// Assumption 1. Indexing is from 1 (string s) or 0 (R - vector of two vectors)!!!
// Assumption 2. String s is non-empty!!!
// Assumption 3. For even palindrom v = w*w^R, the center is defined as the first letter in w^R
// Assumption 4. For odd palindrom v = w*X*w^R, the center is defined as letter X


// Sources:
// https://eduinf.waw.pl/inf/alg/001_search/0060.php#P2
// https://www.mimuw.edu.pl/~jrad/teksty/manacher.cpp
// https://docs.google.com/document/d/e/2PACX-1vQlUP_ERYJAtkE3VLSokwnE1qgxkvD3rm6trxhJQaeR3Qpbyyp-5FYHTHAnzXJPBoaTpkTS4NCAOvWZ/pub
// https://www.youtube.com/watch?v=1POY4ULhIoI
VVI Manacher(std::string &s){
	
	int n = s.size(); // length of string s
	
	
	/* Initializing a result */
	VVI R; // function's result: R[0..1][0..n-1]
	VI tmp( n, 0 ); // temporary vector
	
	R.push_back( tmp );		R.push_back( tmp ); // initialization
	tmp.clear(); // temporary vector is no longer useful 


	s = "#" + s + "$"; // we add guards to text


	REP(j,0,1){ // even and odd (in this order) palindroms
		
		int radius = 0; // initial palindrom's radius
		
		int i = 1; // current index for our text
		while( i <= n ) // all palindroms' centres in text s[1..n]
		{
			while(   s[i - radius - 1] == s [i + j + radius]   ){
				++radius;
			}
			R[j][ i-1 ] = radius;
			
			int k = 1;
			while(   R[j][i - k - 1] != R[j][i - 1] - k   &&   k <= R[j][i - 1]   )
			{
				R[j][i + k - 1] = std::min( R[j][i - k - 1],   R[j][i - 1] - k );
				++k;
			}
			
			radius = std::max(radius - k, 0);
			i += k;
		}
	}
	
	s = s.substr( 1, n ); // we remove guards
	
	return R;
}


int main(){
	
	std::string s = "abaabcckajaksedeskaaksedeskajakccbaaba";
	//std::string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	std::cout << "Tekst:\n" << s << std::endl << std::endl << std::endl;
	
	int lengthS = s.size();
	
	std::vector < std::vector <int> > R = Manacher(s);
	
	std::string prompts[2] = { "Promienie palindromow parzystych:\n", "\nPromienie palindromow nieparzystych:\n" };
	
	REP(i,0,1){
		std::cout << prompts[i];;
		
		REP(j,0,lengthS-1){
			std::cout << "R[" << j+1 << "]=" << R[i][j] << std::endl;  
		}
		
		std::cout << std::endl;
	}

  return 0;
} 
