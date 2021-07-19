#include<bits/stdc++.h>


#define REP(i,a,b) for(int i=a; i<=b; ++i)


// KMP algorithm for searching a pattern in a text.
// This function returns vector of ends of pattern's occurences in a text.
// pattern - a string to be searched
// text - a string in which we find a pattern string

// This version:
// 		1. Computes a preffix function on pattern
// 		2. Finds matches' ends in a text

// Assumption 1. Indexing is from 0!!!
// Assumption 2. A pattern is non-empty!!!

// Sources: 
// https://docs.google.com/document/d/e/2PACX-1vQlUP_ERYJAtkE3VLSokwnE1qgxkvD3rm6trxhJQaeR3Qpbyyp-5FYHTHAnzXJPBoaTpkTS4NCAOvWZ/pub
// https://www.youtube.com/watch?v=V5-7GzOfADQ
std::vector <int> KMP(std::string &pattern, std::string &text){
	
	int lengthPattern = pattern.size();
	int lengthText = text.size();
	
	
	// -------------------------------------------------
	
	
	// 1. Computing a preffix function on pattern
	
	std::vector <int> preffixFunction(lengthPattern);
	preffixFunction[0] = 0;
	
	REP(i,1,lengthPattern-1){
		int t = preffixFunction[i-1];
		
		while( t > 0  &&  pattern[ (t-1) + 1 ] != pattern[i] ){
			t = preffixFunction[t-1];
		}
		
		if( pattern[ (t-1) + 1 ] == text[i] ){
			++t;
		}
		
		preffixFunction[i] = t;
	}
	
	
	// ---------------------------------------------------
	
	
	// 2. Searching matches' ends in a text
	
	std::vector <int> endsofMatchings; // a function's result
	
	
	/*
		iText - current position in a text
		jPattern = max k: text[iText-k..iText] = pattern[0..k]
	*/
	
	int iText = 0;
	int jPattern = -1;
	
	while( iText < lengthText ){ // for all positions in a text
		
		//std::cout << "i=" << iText << ": ";
		
		
		int t = jPattern+1;
			
		while( t > 0  &&  text[iText] != pattern[ (t-1)+1 ] ){
			t = preffixFunction[t-1];
		}
		
		if( pattern[ (t-1) + 1 ] == text[iText] ){
			++t;
		}
		
		
		//std::cout << "t=" << t << std::endl;
		
		
		if( t == lengthPattern ){
			endsofMatchings.push_back(iText);
			jPattern = preffixFunction[t - 1] - 1;
		}
		else{
			jPattern = t - 1;
		}
		
		
		++iText; // next position in a text
	}
	
	
	// --------------------------------------------------
	
	
	return endsofMatchings;
}


int main(){
	
	
	std::string pattern = "aabab";
	std::string text = "aababaabababaaabbababbbaaaabaabaabab";
	
	
	/*
	std::string pattern = "ababd";
	std::string text = "ababcabcabababd";
	*/
	
	
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
