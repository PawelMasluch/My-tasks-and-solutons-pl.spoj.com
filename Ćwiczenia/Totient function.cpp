#include<cstdio>
#include<vector>


typedef std::vector <int> VI;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
#define FOR(i,a,b) for(int i=a; i*i<=b; ++i)


const int MAX_N = 1000000;


// totientFunction[k] - amount of numbers from {1..k} set, relatively prime with k (k=0,...,n)
VI totientFunction(MAX_N+1);


// Counting totientFunction via Eratostenes sieve in O(n*loglog(n)) time.
// n >= 0
void countTotientFunctionViaEratostenesSieve(int n){
	
	// Initially, we assume that all numbers from {1..i} set are relatively prime with i, for i=0,...,n.
	// In particular, totientFunction[0] = 0 (by definition).
	REP(i,0,n,1){
		totientFunction[i] = i;
	}
	
	REP(i,2,n,1){
		if( totientFunction[i] == i ){ // if i is prime
			
			REP(j,i,n,i){
				totientFunction[j] /= i;
				totientFunction[j] *= (i - 1);
			}
		}
	}
}


int main(){
	
	int n;
	scanf( "%d", &n );
	
	countTotientFunctionViaEratostenesSieve(n);
	
	REP(i,1,std::min(n,50),1){
		printf( "totientFunction[%d] = %d\n", i, totientFunction[i] );
	}
	
	return 0;
}
