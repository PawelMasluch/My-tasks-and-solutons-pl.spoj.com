#include <iostream> // 100 pkt
#include<cstring>
#include<algorithm>


typedef std::string STR;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int NUMBER_OF_KINDS_OF_STATISTICS = 5;
const int UNDEF = -1;


int amount_of_spaces(STR &s, int len){
	
	int res = 0;
	REP(i,0,len-1){
		
		if( s[i] == ' ' ){
			++res;
		}
	}
	
	return res;
}


int amount_of_numbers(STR &s, int len){
	
	bool does_previous_char_is_digit = false;
	int res = 0;
	
	REP(i,0,len-1){
		
		if( s[i] >= '0'  &&  s[i] <= '9' ){
			
			if(does_previous_char_is_digit == false){
				does_previous_char_is_digit = true; // current character is a previous one in next loop iteration
				++res;
			}
			
		}
		else{
			does_previous_char_is_digit = false; // current character is a previous one in next loop iteration
		}
	}
	
	return res;
}


int amount_of_words(STR &s, int len){
	
	bool does_previous_char_is_letter = false;
	int res = 0;
	
	REP(i,0,len-1){
		
		if( (s[i] >= 'a'  &&  s[i] <= 'z')  ||
			(s[i] >= 'A'  &&  s[i] <= 'Z') ){
			
			if(does_previous_char_is_letter == false){
				does_previous_char_is_letter = true; // current character is a previous one in next loop iteration
				++res;
			}
			
		}
		else{
			does_previous_char_is_letter = false; // current character is a previous one in next loop iteration
		}
	}
	
	return res;
}


int amount_of_sentences(STR &s, int len){
	
	bool does_previous_char_is_letter = false;
	int number_of_words_in_current_sentence = 0;
	
	int res = 0;
	REP(i,1,len-1){
		
		if( s[i] == '.' ){
			
			does_previous_char_is_letter = false; // current character is a previous one in next loop iteration
			
			if( number_of_words_in_current_sentence > 0 ){
				++res;
				number_of_words_in_current_sentence = 0;
			}
		}
		else{
			
			if( (s[i] >= 'a'  &&  s[i] <= 'z')  ||
				(s[i] >= 'A'  &&  s[i] <= 'Z') ){
				
				if( does_previous_char_is_letter == false ){
					does_previous_char_is_letter = true; // current character is a previous one in next loop iteration
					++number_of_words_in_current_sentence;
				}
			}
			else{
				does_previous_char_is_letter = false; // current character is a previous one in next loop iteration
			}
		}
	}
	
	return res;
}


int amount_of_palindroms(STR &s, int len){
	
	// guard
	s += '#';
	++len;
	
	STR tmp_STR = "";
	STR tmp_STR_rev = "";
	int tmp_STR_len;
	
	bool does_previous_char_is_letter = false;
	int begin_of_curr_word;
	int end_of_curr_word;
	int res = 0;
	
	REP(i,0,len-1){
		
		if( (s[i] >= 'a'  &&  s[i] <= 'z')  ||
			(s[i] >= 'A'  &&  s[i] <= 'Z') ){
			
			if(does_previous_char_is_letter == false){
				does_previous_char_is_letter = true; // current character is a previous one in next loop iteration
				begin_of_curr_word = i;
			}
			
		}
		else{
			
			if( does_previous_char_is_letter == true ){
				end_of_curr_word = i-1;
				
				tmp_STR_len = end_of_curr_word - begin_of_curr_word + 1;
				tmp_STR = tmp_STR_rev = s.substr( begin_of_curr_word, tmp_STR_len ); 
				
				reverse( tmp_STR_rev.begin(), tmp_STR_rev.end() );
				
				if( strcasecmp( tmp_STR.c_str(), tmp_STR_rev.c_str() ) == 0 ){
					++res;
				}
			}
			
			does_previous_char_is_letter = false; // current character is a previous one in next loop iteration
		}
	}
	
	// deleting a guard
	s = s.substr( 0, (len-1)-1 );
	--len;
	
	return res;
}


int statistic_amount(STR &s, int len, int statistic_nr){
	
	switch( statistic_nr ){
		
		case 1:
			return amount_of_spaces( s, len );
		
		case 2:
			return amount_of_numbers( s, len );
		
		case 3:
			return amount_of_words( s, len );
		
		case 4:
			return amount_of_sentences( s, len );
		
		case 5:
			return amount_of_palindroms( s, len );
		
		default:
			return 0;
			
	}
}
 
 
int main() {
 
	std::ios_base::sync_with_stdio(0);
 
	int n; // number of queries; 1 <= n <= 5
	std::cin >> n;
 
	int t[n]; // queries; 1 <= t[i] <= 5
	REP(i,0,n-1){
		std::cin >> t[i];
	}
	
	int ans[NUMBER_OF_KINDS_OF_STATISTICS]; // queries' answers
	REP(i,0,NUMBER_OF_KINDS_OF_STATISTICS-1){ // for each kind of statistic
		ans[i] = UNDEF; // given statistic amount hasn't been computed yet
	}
	
	std::cin.ignore();
	
	STR s; // string to be analyzed
	getline(std::cin, s);
	
	int len = s.length(); // string's length
 
	REP(i,0,n-1){ // for each query
		
		if( ans[ t[i]-1 ] == UNDEF ){ // given statistic (with id = t[i]) amount hasn't been computed yet
			ans[ t[i]-1 ] = statistic_amount( s, len, t[i] );
		}
		
		std::cout << ans[ t[i]-1 ] << " ";
	}
	std::cout << std::endl;
 
	return 0;
}
