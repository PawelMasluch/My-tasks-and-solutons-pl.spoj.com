#include<iostream> // 100 pkt
#include<string>


typedef std::string STR;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int ALPHABET_SIZE = 26;


char most_popular_letter_in_cryptogram(STR s, int len){
	
	int how_many_letters[ALPHABET_SIZE];
	REP(i,0,ALPHABET_SIZE-1){
		how_many_letters[i] = 0;
	}
	
	REP(i,0,len-1){
		++how_many_letters[ s[i] - 'A' ];
	}
	
	char most_popular_letter = 'A';
	int biggest_number_of_occurences = how_many_letters[ most_popular_letter - 'A' ];
	
	REP(c,'B','Z'){
		if( how_many_letters[ c - 'A' ] > biggest_number_of_occurences ){
			biggest_number_of_occurences = how_many_letters[ c - 'A' ];
			most_popular_letter = c;
		}
	}
	
	return most_popular_letter;
}


int compute_cyclic_shift_length(char source_letter, char target_letter){
	return ( target_letter - source_letter + ALPHABET_SIZE ) % ALPHABET_SIZE;
}


char find_encrypted_letter(char public_character, int cyclic_shift_length){
	
	return   'A'   +   (public_character - 'A' + cyclic_shift_length) % ALPHABET_SIZE;
}

STR Caesar_cipher(STR &s, int len, int cyclic_shift_length){
	
	STR res = "";
	REP(i,0,len-1){
		res += find_encrypted_letter( s[i], cyclic_shift_length );
	}
	
	return res;
}


int main(){
	
	std::ios_base::sync_with_stdio(0);
	
	int n;
	char c;
	STR s;
	std::cin >> n >> c >> s;
	
	char z = most_popular_letter_in_cryptogram( s, n );
	
	// length of cyclic shift for decryption
	int cyclic_shift_length = compute_cyclic_shift_length(z, c);
	
	// decryption
	std::cout << Caesar_cipher(s, n, cyclic_shift_length) << std::endl;
	
	return 0;
}
