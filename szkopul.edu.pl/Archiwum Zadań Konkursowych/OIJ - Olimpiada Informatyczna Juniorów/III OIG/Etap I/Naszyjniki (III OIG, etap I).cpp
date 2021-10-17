#include<iostream> // 100 pkt
#include<string>


typedef std::string STR;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int NUMBER_OF_VOWELS = 6;
const char LOWERCASE_VOWELS[NUMBER_OF_VOWELS] = {'a', 'e', 'i', 'o', 'u', 'y'};
const char UPPERCASE_VOWELS[NUMBER_OF_VOWELS] = {'A', 'E', 'I', 'O', 'U', 'Y'};
const int INF = 1000000099;


bool is_lowercase(char c){
	return c >= 'a'  &&  c <= 'z';
}


bool is_uppercase(char c){
	return c >= 'A'  &&  c <= 'Z';
}


bool is_vowel(char c){
	
	REP(i,0,NUMBER_OF_VOWELS-1){
		
		if( c == LOWERCASE_VOWELS[i]  ||  c == UPPERCASE_VOWELS[i] ){
			return true;
		}
	}
	
	return false;
}


bool is_consonant(char c){
	return !is_vowel(c);
}


bool do_two_letters_have_the_same_type(char c1, char c2){
	return is_uppercase( c1 ) == is_uppercase( c2 )  &&  
		       is_vowel( c1 ) ==     is_vowel( c2 );
}


void find_longest_and_shortest_segment(STR &s){
	
	int min_big_bright_segment = INF;
	int max_big_bright_segment = 0;
	
	int min_big_dark_segment = INF;
	int max_big_dark_segment = 0;
	
	int min_small_bright_segment = INF;
	int max_small_bright_segment = 0;
	
	int min_small_dark_segment = INF;
	int max_small_dark_segment = 0;
	
	int min_segment = INF;
	int max_segment = 0;
	
	
	int len = s.length();
	
	
	int start = 0, end = 1;
	if( do_two_letters_have_the_same_type(s[0], s[len-1]) ){
		
		while(  end - start + 1 <= len  &&  
				do_two_letters_have_the_same_type(s[start], s[end]) ){
			
			++end;
		}
		
		start = end;
	}
	
	
	
	s = s + s;
	while(start <= len){ // each possible segment beginning
		
		end = start+1;
		while(          end - start + 1 <= len  &&  
			    do_two_letters_have_the_same_type(s[start], s[end]) ){
			
			++end;
		}
		
		
		/* Cases of uppercaseness (size) and vowelness (brightness) */
		
		// Case 1: Lowercase (small) vowel (bright)
		if( is_lowercase( s[start] ) == true  &&  is_vowel( s[start] ) == true ){
			min_small_bright_segment = std::min( min_small_bright_segment,  end - start );
			min_segment = std::min( min_segment, min_small_bright_segment );
			
			max_small_bright_segment = std::max( max_small_bright_segment,  end - start );
			max_segment = std::max( max_segment, max_small_bright_segment );
		}
		
		// Case 2: Lowercase (small) consonant (dark)
		if( is_lowercase( s[start] ) == true  &&  is_consonant( s[start] ) == true ){
			min_small_dark_segment = std::min( min_small_dark_segment,  end - start );
			min_segment = std::min( min_segment, min_small_dark_segment );
			
			max_small_dark_segment = std::max( max_small_dark_segment,  end - start );
			max_segment = std::max( max_segment, max_small_dark_segment );
		}
		
		// Case 3: Uppercase (big) vowel (bright)
		if( is_uppercase( s[start] ) == true  &&  is_vowel( s[start] ) == true ){
			min_big_bright_segment = std::min( min_big_bright_segment,  end - start );
			min_segment = std::min( min_segment, min_big_bright_segment );
			
			max_big_bright_segment = std::max( max_big_bright_segment,  end - start );
			max_segment = std::max( max_segment, max_big_bright_segment );
		}
		
		// Case 4: Uppercase (big) consonant (dark)
		if( is_uppercase( s[start] ) == true  &&  is_consonant( s[start] ) == true ){
			min_big_dark_segment = std::min( min_big_dark_segment,  end - start );
			min_segment = std::min( min_segment, min_big_dark_segment );
			
			max_big_dark_segment = std::max( max_big_dark_segment,  end - start );
			max_segment = std::max( max_segment, max_big_dark_segment );
		}
		
		start = end;
	}
	
	
	/* max_segment */
	std::cout << max_segment << " ";
	
	if( max_segment == max_big_bright_segment ){
		std::cout << "JASNE\n"; 
	}
	else{
		if( max_segment == max_big_dark_segment ){
			std::cout << "CIEMNE\n"; 
		}
		else{
			if( max_segment == max_small_bright_segment ){
				std::cout << "jasne\n"; 
			}
			else{
				if( max_segment == max_small_dark_segment ){
					std::cout << "ciemne\n"; 
				}
			}
		}
	}
	
	
	/* min_segment */
	std::cout << min_segment << " ";
	
	if( min_segment == min_big_bright_segment ){
		std::cout << "JASNE\n"; 
	}
	else{
		if( min_segment == min_big_dark_segment ){
			std::cout << "CIEMNE\n"; 
		}
		else{
			if( min_segment == min_small_bright_segment ){
				std::cout << "jasne\n"; 
			}
			else{
				if( min_segment == min_small_dark_segment ){
					std::cout << "ciemne\n"; 
				}
			}
		}
	}
	
	s = s.substr(0, len);
}


int main(){
	
	std::ios_base::sync_with_stdio(0);
	
	int n;
	std::cin >> n;
	
	STR s;
	REP(i,1,n){
		std::cin >> s;
		find_longest_and_shortest_segment( s );
	}
	
	return 0;
}
