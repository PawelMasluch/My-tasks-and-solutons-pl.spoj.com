#include<bits/stdc++.h>


#define REP(i,a,b) for(int i=a; i<=b; ++i)


// KMP algorithm for searching a pattern in a text.
// This function returns vector of ends of pattern's occurences in a text.
// pattern - a string to be searched
// text - a string in which we find a pattern string

// This version:
//		1. Computes a preffix function on string s = pattern#text
//		2. Searches matches on string s[lengthPattern+1..lengthS-1]

// Assumption 1. Indexing is from 0!!!
// Assumption 2. A '#' character doesn't occur in pattern and text!!!
// Assumption 3. A pattern is non-empty!!!

// Source: 
// https://docs.google.com/document/d/e/2PACX-1vQlUP_ERYJAtkE3VLSokwnE1qgxkvD3rm6trxhJQaeR3Qpbyyp-5FYHTHAnzXJPBoaTpkTS4NCAOvWZ/pub
std::vector <int> KMP(std::string &pattern, std::string &text){
	std::string s = pattern + '#' + text;
	
	int lengthPattern = pattern.size();
	int lengthText = text.size();
	int lengthS = lengthPattern + 1 + lengthText;
	
	
	// -------------------------------------------------
	
	
	// 1. Computing a preffix function on string s = pattern#text
	
	std::vector <int> preffixFunction(lengthS);
	preffixFunction[0] = 0;
	
	REP(i,1,lengthS-1){
		int t = preffixFunction[i-1];
		
		while( t > 0  &&  s[ (t-1) + 1 ] != s[i] ){
			t = preffixFunction[t-1];
		}
		
		if( s[ (t-1) + 1 ] == s[i] ){
			++t;
		}
		
		preffixFunction[i] = t;
	}
	
	
	// ---------------------------------------------------
	
	
	// 2. Searching matches on string s[lengthPattern+1..lengthS-1]
	
	std::vector <int> endsofMatchings; // a function's result
	
	REP(i,lengthPattern+1,lengthS-1){
		if( preffixFunction[i] == lengthPattern ){
			endsofMatchings.push_back(   i - (lengthPattern + 1)   );
		}
	}
	
	
	// -----------------------------------------------------
	
	
	return endsofMatchings;
}


int main(){
	
	std::string pattern = "aabab";
	std::string text = "aababaabababaaabbababbbaaaabaabaabab";
	
	// -------------
	
	std::cout << "Pattern: " << pattern << std::endl;
	std::cout << "Text:    " << text << std::endl;
	std::cout << std::endl;
	
	// --------------
	
	std::vector <int> endsofMatchings = KMP(pattern, text);
	int n = endsofMatchings.size();
	
	// --------------
	
	std::cout << "Indices of ocurrences' ends:" << std::endl;
	REP(i,0,n-1){
		std::cout << endsofMatchings[i] << std::endl;
	}
	
	
	return 0;
}
