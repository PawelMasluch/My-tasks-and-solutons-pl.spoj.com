#include<queue>
#include<cstdio>


using namespace std;


typedef queue <int> QI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define FOR_SQR(i,a,b) for(int i=a; i*i<=b; ++i)
#define P push
#define p pop
#define F front
#define E empty


const int NUMBER_OF_ONE_DIGIT_PRIMES = 4;
const int NUMBER_OF_LAST_DIGITS_IN_MULTI_DIGIT_PRIMES = 4;


int one_digit_primes[NUMBER_OF_ONE_DIGIT_PRIMES] = {2, 3, 5, 7};
int last_digits_in_multi_digit_primes[NUMBER_OF_LAST_DIGITS_IN_MULTI_DIGIT_PRIMES] = {1, 3, 7, 9};
int number = 0; // liczba skracalnych liczb pierwszych


bool isPrime(int x){ // x >= 4
	
	FOR_SQR(i,2,x){
		if( x % i == 0 ){
			return false;
		}
	}
	
	return true;
}


int main(){
	
	FILE *f = fopen( "skracalne_liczby_pierwsze.txt", "w" );
	REP(i,0,NUMBER_OF_ONE_DIGIT_PRIMES-1){
		fprintf( f, "%d, ", one_digit_primes[i] );
	}
	
	QI Q;
	REP(i,0,3){
		Q.P( one_digit_primes[i] );
		++number;
	}
	
	while( !Q.E() ){
		int x = Q.F();	Q.p();
		
		REP(i,0,NUMBER_OF_LAST_DIGITS_IN_MULTI_DIGIT_PRIMES-1){
			
			int tmp = 10*x + last_digits_in_multi_digit_primes[i];
			if( isPrime(tmp) ){
				fprintf( f, "%d, ", tmp );
				Q.P( tmp );
				++number;
			}
		}
	}
	
	fprintf( f, "\n%d\n", number );
	
	fclose(f);
	
	return 0;
}
